//
//  ModelActor.cpp
//  kadai_billiards
//
//  Created by 簗瀬研太 on 2016/11/24.
//  Copyright © 2016年 Kenta Yanase. All rights reserved.
//

#include "ModelActor.hpp"

ModelActor::ModelActor(std::string name) : Actor(name){
}

ModelActor::ModelActor(std::string name, std::string modelName) : Actor(name){
    ResourcesManager::getMqoModel(modelName, this->mqoModel);
}

ModelActor::ModelActor(std::string name, glm::vec3 position, glm::vec3 euler) : Actor(name, position, euler){
}

ModelActor::ModelActor(std::string name, glm::vec3 position, glm::vec3 euler, std::string modelName) : Actor(name, position, euler){
    ResourcesManager::getMqoModel(modelName, this->mqoModel);
}

ModelActor::~ModelActor () {
    if(mqoModel != nullptr) mqoDeleteModel( mqoModel);
}

void ModelActor::fixedUpdate(float deltaTime) {
    Actor::fixedUpdate(deltaTime);
}

void ModelActor::displayUpdate(float deltaTime) {
    Actor::displayUpdate(deltaTime);
    
    glPushMatrix();
    
    glTranslatef(position.x, position.y, position.z);
    glRotatef(euler.z, 0.0, 0.0, 1.0);
    glRotatef(euler.y, 0.0, 1.0, 0.0);
    glRotatef(euler.x, 1.0, 0.0, 0.0);

    mqoCallModel(mqoModel);
    
    glPopMatrix();
}