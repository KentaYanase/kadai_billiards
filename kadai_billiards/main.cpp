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
#include "Ball.hpp"
#include "PlayerBall.hpp"
#include "Table.hpp"
#include "ActorManager.hpp"
#include "RenderManager.hpp"
#include "PhysicsManager.hpp"
#include "ResourcesManager.hpp"
#include "TimeManager.hpp"

ModelActor *billiardsTable;
PlayerBall *whiteBall;
std::vector<Ball*> balls;


void GameClear () {
    printf("GameClear\n");
    RenderManager::isGameClear = true;
}

void GameOver () {
    printf("GameOver\n");
    RenderManager::isGameOver = true;
}


bool isStoppedAllBall () {
    if(!whiteBall->isFall) {
        if(!whiteBall->isFall && whiteBall->rigidBody->getAngularVelocity().length() > 0.01f) return false;
    }
    for(auto ball : balls) {
        if(!ball->isFall) {
            if(ball->rigidBody->getAngularVelocity().length() > 0.01f) return false;
        }else {
            printf("fall\n");
        }
    }
    return true;
}

void addForce () {
    auto dir = whiteBall->mouseEnd - whiteBall->mouseStart;
    whiteBall->rigidBody->applyImpulse(btVector3(-dir.x/10.0,0,-dir.y/10.0), btVector3(0,0,0));
    whiteBall->mouseEnd = whiteBall->mouseStart;
}

void motion(int x , int y) {
    if(!isStoppedAllBall()) return;
    
    whiteBall->mouseEnd.x = x;
    whiteBall->mouseEnd.y = y;
}

void mouse(int button , int state , int x , int y) {
    if(!isStoppedAllBall()) return;
    
    std::cout << x << ", " << y << std::endl;
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        whiteBall->mouseStart.x = x;
        whiteBall->mouseStart.y = y;
        whiteBall->mouseEnd.x = x;
        whiteBall->mouseEnd.y = y;
    }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        whiteBall->mouseEnd.x = x;
        whiteBall->mouseEnd.y = y;
        addForce();
    }
}


void update (int value) {
    
    if(whiteBall->isFall) {
        GameOver();
        return;
    }
    
    int count = 0;
    for(auto ball : balls) {
        if(!ball->isFall) {
            ball->target = (count == 0);
            count++;
        }
    }
    if(count == 0) {
        GameClear();
        return;
    }
    
    glutTimerFunc(20 , update , 0);
}

int main(int argc, char *argv[]) {
    
    ActorManager::create();
    RenderManager::create();
    TimeManager::create();
    PhysicsManager::create();
    
    ResourcesManager::create();
    ResourcesManager::exePath = argv[0];
    
    ResourcesManager::load();
    
    //開始
    billiardsTable = new Table ("BilliardsTable");
    whiteBall = new PlayerBall ("Ball", "Ball", glm::vec3(1.5f,0.1f,0.01f), glm::vec3(0.0f,0.0f,0.0f));
    
    balls.push_back(new Ball("Ball1", "Ball1", glm::vec3(-1.7f,0.1f,0.0f), glm::vec3(0.0f,0.0f,0.0f)));
    balls.push_back(new Ball("Ball2", "Ball2", glm::vec3(-1.85f,0.1f,0.1f), glm::vec3(0.0f,0.0f,0.0f)));
    balls.push_back(new Ball("Ball4", "Ball4", glm::vec3(-2.0f,0.1f,0.2f), glm::vec3(0.0f,0.0f,0.0f)));
    balls.push_back(new Ball("Ball6", "Ball6", glm::vec3(-2.15f,0.1f,0.1f), glm::vec3(0.0f,0.0f,0.0f)));
    balls.push_back(new Ball("Ball9", "Ball9", glm::vec3(-2.0f,0.1f,0.0f), glm::vec3(0.0f,0.0f,0.0f)));
    balls.push_back(new Ball("Ball5", "Ball5", glm::vec3(-2.15f,0.1f,-0.1f), glm::vec3(0.0f,0.0f,0.0f)));
    balls.push_back(new Ball("Ball7", "Ball7", glm::vec3(-2.0f,0.1f,-0.2f), glm::vec3(0.0f,0.0f,0.0f)));
    balls.push_back(new Ball("Ball3", "Ball3", glm::vec3(-1.85f,0.1f,-0.1f), glm::vec3(0.0f,0.0f,0.0f)));
    balls.push_back(new Ball("Ball8", "Ball8", glm::vec3(-2.3f,0.1f,0.0f), glm::vec3(0.0f,0.0f,0.0f)));
    
    balls.front()->target = true;
    
    glutTimerFunc(20 , update , 0);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    
    printf("start_loop\n");
    glutMainLoop();
    printf("close\n");
    
    delete billiardsTable;
    delete whiteBall;
    for(auto ball : balls) {
        delete ball;
    }
    balls.clear();
    
    ResourcesManager::unload();
    ResourcesManager::destroy();
    PhysicsManager::destroy();
    TimeManager::destroy();
    RenderManager::destroy();
    ActorManager::destroy();
    
    return 0;
}