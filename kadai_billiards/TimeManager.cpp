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

TimeManager* TimeManager::instance = nullptr;

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

void TimeManager::fixedUpdate(int value) {
    for(auto actor : ActorManager::getActorList()) {
        actor->fixedUpdate(1.0f/60.0f);
    }
    glutTimerFunc(fixedUpdateSpan , TimeManager::fixedUpdate , 0);
}