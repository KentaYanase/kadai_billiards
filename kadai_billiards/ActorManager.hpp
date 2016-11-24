//
//  ActorManager.hpp
//  kadai_billiards
//
//  Created by 簗瀬研太 on 2016/11/23.
//  Copyright © 2016年 Kenta Yanase. All rights reserved.
//

#ifndef ActorManager_hpp
#define ActorManager_hpp

#include <stdio.h>
#include <vector>
#include <GLUT/GLUT.h>
#include <glm/glm.hpp>
#include "Actor.hpp"

class ActorManager {
    
private:
    ActorManager() = default;
    ~ActorManager() = default;
    
    static ActorManager* instance;
    
    std::vector<Actor*> actorList;
    
public:
    ActorManager(const ActorManager&) = delete;
    ActorManager& operator=(const ActorManager&) = delete;
    ActorManager(ActorManager&&) = delete;
    ActorManager& operator=(ActorManager&&) = delete;
   
    static ActorManager& getInstance ();
    static void create();
    static void destroy();
    
    static const std::vector<Actor*>& getActorList ();
    static void addActor (Actor *actor);
    static void removeActor  (Actor *actor);
};

#endif /* ActorManager_hpp */
