//
//  PhysicsManager.hpp.cpp
//  kadai_billiards
//
//  Created by 簗瀬研太 on 2016/11/23.
//  Copyright © 2016年 Kenta Yanase. All rights reserved.
//


#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include <glm/glm.hpp>
#include "PhysicsManager.hpp"

const int PhysicsManager::maxSubSteps = 5;

PhysicsManager* PhysicsManager::instance = nullptr;

PhysicsManager& PhysicsManager::getInstance () {
    return *instance;
}

void PhysicsManager::create() {
    if ( !instance ) {
        instance = new PhysicsManager;
        
        instance->collisionConfiguration = new btDefaultCollisionConfiguration();
        instance->dispatcher = new btCollisionDispatcher(instance->collisionConfiguration);
        instance->overlappingPairCache = new btDbvtBroadphase();
        instance->solver = new btSequentialImpulseConstraintSolver;
        instance->dynamicsWorld = new btDiscreteDynamicsWorld(
            instance->dispatcher,
            instance->overlappingPairCache,
            instance->solver,
            instance->collisionConfiguration);
        
        instance->dynamicsWorld->setGravity(btVector3(0,-9.8,0));
        
        instance->debugDrawer = new GLDebugDrawer;
        instance->debugDrawer->setDebugMode(btIDebugDraw::DBG_DrawWireframe);
        
        instance->dynamicsWorld->setDebugDrawer(instance->debugDrawer);
        
//        btCollisionShape* groundShape = new btBoxShape(btVector3(btScalar(50.),btScalar(50.),btScalar(50.)));
//        btAlignedObjectArray<btCollisionShape*> collisionShapes;
//        collisionShapes.push_back(groundShape);
//        btTransform groundTransform;
//        groundTransform.setIdentity();
//        groundTransform.setOrigin(btVector3(0,-56,0));
    }
}

void PhysicsManager::destroy() {
    if ( instance ) {
        delete instance;
        instance = nullptr;
        
        delete instance->debugDrawer;
        delete instance->dynamicsWorld;
        delete instance->solver;
        delete instance->overlappingPairCache;
        delete instance->dispatcher;
        delete instance->collisionConfiguration;
    }
}

void PhysicsManager::stepSimulation(float deltaTime) {
    getInstance().dynamicsWorld->stepSimulation(deltaTime, maxSubSteps);
}

void PhysicsManager::addRigidBody(btRigidBody *rigidBody) {
    getInstance().dynamicsWorld->addRigidBody(rigidBody);
}

void PhysicsManager::removeRigidBody(btRigidBody *rigidBody) {
    getInstance().dynamicsWorld->removeRigidBody(rigidBody);
}

void PhysicsManager::debugDrawWorld () {
    getInstance().dynamicsWorld->debugDrawWorld();
}

void PhysicsManager::contactTest (btRigidBody *rigidBody, btCollisionWorld::ContactResultCallback &resultCallback) {
    instance->dynamicsWorld->contactTest(rigidBody, resultCallback);
}
