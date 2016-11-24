//
//  InputManager.hpp.cpp
//  kadai_billiards
//
//  Created by 簗瀬研太 on 2016/11/23.
//  Copyright © 2016年 Kenta Yanase. All rights reserved.
//


#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include <glm/glm.hpp>
#include "InputManager.hpp"

InputManager* InputManager::instance = nullptr;

InputManager& InputManager::getInstance () {
    return *instance;
}

void InputManager::create() {
    if ( !instance ) {
        instance = new InputManager;
    }
}

void InputManager::destroy() {
    if ( instance ) {
        delete instance;
        instance = nullptr;
    }
}
