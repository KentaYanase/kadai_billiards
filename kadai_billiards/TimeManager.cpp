//
//  TimeManager.hpp.cpp
//  kadai_billiards
//
//  Created by 簗瀬研太 on 2016/11/23.
//  Copyright © 2016年 Kenta Yanase. All rights reserved.
//


#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include <glm/glm.hpp>
#include "TimeManager.hpp"
#include "ActorManager.hpp"
#include "PhysicsManager.hpp"

TimeManager* TimeManager::instance = nullptr;

float TimeManager::time = 0.0f;
float TimeManager::timeScale = 1.0f;

const int TimeManager::fixedUpdateSpan = 20;    //ms間隔

TimeManager& TimeManager::getInstance () {
    return *instance;
}

void TimeManager::create() {
    if ( !instance ) {
        instance = new TimeManager;
        glutTimerFunc(fixedUpdateSpan , TimeManager::fixedUpdate , 0);
    }
}

void TimeManager::destroy() {
    if ( instance ) {
        delete instance;
        instance = nullptr;
    }
}

float TimeManager::getTime() {
    return time;
}

void TimeManager::fixedUpdate(int value) {
    float deltaTime = (float)fixedUpdateSpan/(float)1000;
    time += deltaTime;

    for(auto actor : ActorManager::getActorList()) {
        if(actor->rigidBody != nullptr) {
            if(!actor->rigidBody->isStaticObject() && !actor->rigidBody->isKinematicObject()) {
                
            }else {
                actor->applyTransform();
            }
        }
    }
    
    PhysicsManager::stepSimulation(deltaTime * timeScale);
    
    for(auto actor : ActorManager::getActorList()) {
        actor->fixedUpdate(deltaTime * timeScale);
    }
    
    glutTimerFunc(fixedUpdateSpan , TimeManager::fixedUpdate , 0);
}