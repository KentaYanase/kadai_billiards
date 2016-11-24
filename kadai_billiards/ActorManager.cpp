//
//  ActorManager.cpp
//  kadai_billiards
//
//  Created by 簗瀬研太 on 2016/11/23.
//  Copyright © 2016年 Kenta Yanase. All rights reserved.
//

#include "ActorManager.hpp"
#include <GLUT/GLUT.h>
#include <glm/glm.hpp>
#include "Actor.hpp"

ActorManager* ActorManager::instance = nullptr;

ActorManager& ActorManager::getInstance () {
    return *instance;
}

void ActorManager::create() {
    if ( !instance ) {
        instance = new ActorManager;
    }
}

void ActorManager::destroy() {
    if ( instance ) {
        delete instance;
        instance = nullptr;
    }
}

const std::vector<Actor*>& ActorManager::getActorList () {
    return getInstance().actorList;
}

void ActorManager::addActor(Actor *actor) {
    getInstance().actorList.push_back(actor);
}

void ActorManager::removeActor(Actor *actor) {
    getInstance().actorList.erase(remove(getInstance().actorList.begin()
        , getInstance().actorList.end(), actor), getInstance().actorList.end());
}