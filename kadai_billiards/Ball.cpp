//
//  Ball.cpp
//  kadai_billiards
//
//  Created by 簗瀬研太 on 2016/12/14.
//  Copyright © 2016年 Kenta Yanase. All rights reserved.
//

#include "Ball.hpp"

//struct ballContactResult : public btCollisionWorld::ContactResultCallback {
//    
//    Ball *ball;
//    
//    ballContactResult (Ball *ball) {
//        this->ball = ball;
//    }
//    
//    virtual	btScalar addSingleResult(btManifoldPoint& cp, const btCollisionObjectWrapper* colObj0Wrap
//                                     ,int partId0,int index0,const btCollisionObjectWrapper* colObj1Wrap,int partId1,int index1) {
//        std::cout << ball->getName() << std::endl;
//        return 0;
//    }
//};

Ball::Ball (std::string name, std::string modelName, glm::vec3 position, glm::vec3 euler) : ModelActor(name, modelName) {
    float mass = 0.5f;
    float size = 0.07f;
    shape = new btSphereShape(size);
    
    btVector3 localInertia(0,0,0);
    shape->calculateLocalInertia(mass,localInertia);
    btDefaultMotionState* motionState = new btDefaultMotionState();
    
    this->setPosition(position);
    this->setEuler(euler);

    btTransform worldTrans;
    btQuaternion q;
    worldTrans.setOrigin(btVector3(position.x, position.y, position.z));
    q.setEulerZYX(euler.z * M_PI / 180.0f, euler.y * M_PI / 180.0f, euler.x * M_PI / 180.0f);
    worldTrans.setRotation(q);
    motionState->setWorldTransform(worldTrans);
    
    btRigidBody::btRigidBodyConstructionInfo rbInfo(mass,motionState,shape,localInertia);
    this->rigidBody = new btRigidBody(rbInfo);
    this->rigidBody->setDamping(0.1f, 0.6f);
    this->rigidBody->setRestitution(0.9);
    this->rigidBody->setCcdSweptSphereRadius(size);
    this->rigidBody->setCcdMotionThreshold(0.1);
    //this->rigidBody->setFriction(0.1f);
    this->rigidBody->setRollingFriction(0.002f);
    
    PhysicsManager::addRigidBody(this->rigidBody);
}

Ball::~Ball () {
    PhysicsManager::removeRigidBody(this->rigidBody);
    delete shape;
}

void Ball::fixedUpdate(float deltaTime) {
    if(isFall) return;
    ModelActor::fixedUpdate(deltaTime);
    
//    ballContactResult result(this);
//    PhysicsManager::contactTest(this->rigidBody, result);
    auto pos = getPosition();
    if(pos.y < -0.2) {
        isFall = true;
        this->rigidBody->setActivationState(DISABLE_SIMULATION);
    }
    
    btVector3 velocity = rigidBody->getLinearVelocity();
    btVector3 anglerVelocity = rigidBody->getAngularVelocity();
    if(velocity.length() < 0.1f && anglerVelocity.length() < 0.1f) {
        rigidBody->setLinearVelocity(velocity * 0.2f);
        rigidBody->setAngularVelocity(anglerVelocity * 0.2f);
    }
}

void Ball::displayUpdate(float deltaTime) {
    if(isFall) return;
    
    if(target) {
        float wave = std::sin(TimeManager::getTime()*10.0f);
        wave *= wave;
        GLMetaseqUtil::SetDifColorAllMat(mqoModel, wave, wave, wave, 1);
    }
    
    ModelActor::displayUpdate(deltaTime);
}