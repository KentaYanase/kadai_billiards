//
//  gameObject.cpp
//  kadai_billiards
//
//  Created by 簗瀬研太 on 2016/11/23.
//  Copyright © 2016年 Kenta Yanase. All rights reserved.
//

#include "Actor.hpp"
#include "ActorManager.hpp"

Actor::Actor(std::string name) {
    this->name = name;
    this->position = glm::vec3(0.0f,0.0f,0.0f);
    this->euler = glm::vec3(0.0f,0.0f,0.0f);
    ActorManager::addActor(this);
}

Actor::Actor(std::string name, glm::vec3 position, glm::vec3 euler) {
    this->name = name;
    this->position = position;
    this->euler = euler;
    ActorManager::addActor(this);
}

Actor::~Actor() {
    ActorManager::removeActor(this);
    if(rigidBody != nullptr) delete rigidBody;
}

std::string Actor::getName() {
    return name;
}

void Actor::setPosition(glm::vec3 position) {
    this->position = position;
    applyTransform();
}

void Actor::setEuler(glm::vec3 euler) {
    this->euler = euler;
    applyTransform();
}

glm::vec3 Actor::getPosition () {
    return position;
}

glm::vec3 Actor::getEuler () {
    return euler;
}

//void getTransform (glm::vec3 position, glm::vec3 euler, btTransform &worldTrans) {
//    btQuaternion q;
//    worldTrans.setOrigin(btVector3(position.x, position.y, position.z));
//    q.setEuler(euler.z * M_PI / 180.0f, euler.y * M_PI / 180.0f, euler.x * M_PI / 180.0f);
//    worldTrans.setRotation(q);
//}

void Actor::applyTransform () {
    if(rigidBody != nullptr) {
        btTransform worldTrans;
        btQuaternion q;
        worldTrans.setOrigin(btVector3(position.x, position.y, position.z));
        q.setEulerZYX(euler.z * M_PI / 180.0f, euler.y * M_PI / 180.0f, euler.x * M_PI / 180.0f);
        worldTrans.setRotation(q);
        rigidBody->getMotionState()->setWorldTransform(worldTrans);
    }
}

void Actor::fixedUpdate(float deltaTime) {
    if(rigidBody != nullptr && !rigidBody->isStaticObject() && !rigidBody->isKinematicObject()) {
        btTransform worldTrans;
        rigidBody->getMotionState()->getWorldTransform(worldTrans);
        
        btVector3 btPos = worldTrans.getOrigin();
        position.x = btPos.getX();
        position.y = btPos.getY();
        position.z = btPos.getZ();
        
        worldTrans.getBasis().getEulerZYX(euler.z, euler.y, euler.x);
        euler.z *= 180.0f / M_PI;
        euler.y *= 180.0f / M_PI;
        euler.x *= 180.0f / M_PI;
    }
}

void Actor::displayUpdate(float deltaTime) {
}