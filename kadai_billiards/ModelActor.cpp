//
//  ModelActor.cpp
//  kadai_billiards
//
//  Created by 簗瀬研太 on 2016/11/24.
//  Copyright © 2016年 Kenta Yanase. All rights reserved.
//

#include "ModelActor.hpp"

ModelActor::ModelActor(std::string name, std::string modelName) : Actor(name){
    mqoModel = ResourcesManager::getMqoModel(modelName);
}

ModelActor::~ModelActor () {
    
}

void ModelActor::fixedUpdate(float deltaTime) {
//    std::cout << name << "  fixedUpdate" << std::endl;
}

void ModelActor::displayUpdate(float deltaTime) {
//    std::cout << name << "  displayUpdate" << std::endl;
    
    glPushMatrix();
    
    glTranslatef(position.x, position.y, position.z);
    glRotatef(euler.z, 0.0, 0.0, 1.0);
    glRotatef(euler.y, 0.0, 1.0, 0.0);
    glRotatef(euler.x, 1.0, 0.0, 0.0);
    mqoCallModel(*mqoModel);
    
    glPopMatrix();
}