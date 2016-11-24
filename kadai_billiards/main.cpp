//
//  main.cpp
//  kadai_billiards
//
//  Created by 簗瀬研太 on 2016/11/22.
//  Copyright © 2016年 Kenta Yanase. All rights reserved.
//

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include <glm/glm.hpp>
#include "Actor.hpp"
#include "ModelActor.hpp"
#include "ActorManager.hpp"
#include "RenderManager.hpp"
#include "ResourcesManager.hpp"
#include "TimeManager.hpp"

ModelActor *billiardsTable, *whiteBall, *cue;

void update (int value) {
    //cue->rotation.x += 0.5f;
    cue->euler.y += 0.5f;
    glutTimerFunc(20 , update , 0);
}

int main(int argc, char *argv[]) {
    
    ActorManager::create();
    RenderManager::create();
    TimeManager::create();
    ResourcesManager::create();
    
    ResourcesManager::exePath = argv[0];
    
    ResourcesManager::load();
    
    glutTimerFunc(20 , update , 0);
    
    //開始
    billiardsTable = new ModelActor ("BilliardsTable", "BilliardsTable");
    whiteBall = new ModelActor ("Ball", "Ball");
    cue = new ModelActor ("Cue", "Cue");
    
    whiteBall->position.y = 0.01f;
    cue->position.y = 0.05f;
    
    printf("start_loop\n");
    glutMainLoop();
    printf("close\n");
    
    delete billiardsTable;
    delete whiteBall;
    delete cue;
    
    ResourcesManager::unload();
    
    ResourcesManager::destroy();
    TimeManager::destroy();
    RenderManager::destroy();
    ActorManager::destroy();
    
    return 0;
}