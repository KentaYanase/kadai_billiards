//
//  PlayerBall.cpp
//  kadai_billiards
//
//  Created by 簗瀬研太 on 2016/12/15.
//  Copyright © 2016年 Kenta Yanase. All rights reserved.
//

#include "PlayerBall.hpp"

PlayerBall::PlayerBall(std::string name, std::string modelName, glm::vec3 position, glm::vec3 euler) : Ball(name, modelName, position, euler){
    
}

PlayerBall::~PlayerBall() {
    
}

void PlayerBall::fixedUpdate(float deltaTime) {
    if(isFall) return;
    Ball::fixedUpdate(deltaTime);
}

void PlayerBall::displayUpdate(float deltaTime) {
    if(isFall) return;
    Ball::displayUpdate(deltaTime);
    
    auto dir = this->mouseEnd - this->mouseStart;
    
    glLineWidth(20);
    glBegin( GL_LINES );
        glColor3f(1.0,0.0,0.0f);
        glVertex3f( position.x, position.y, position.z);
        glColor3f(1.0,0.0,0.0f);
        glVertex3f( position.x - dir.x / 100.0f, position.y, position.z - dir.y/100.0f);
    glEnd();
}