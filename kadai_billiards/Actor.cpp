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
    ActorManager::addActor(this);
}

Actor::~Actor() {
    ActorManager::removeActor(this);
}

void Actor::fixedUpdate(float deltaTime) {
    
}

void Actor::displayUpdate(float deltaTime) {
    
}