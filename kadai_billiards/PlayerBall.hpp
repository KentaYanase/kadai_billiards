//
//  PlayerBall.hpp
//  kadai_billiards
//
//  Created by 簗瀬研太 on 2016/12/15.
//  Copyright © 2016年 Kenta Yanase. All rights reserved.
//

#ifndef PlayerBall_hpp
#define PlayerBall_hpp

#include <stdio.h>
#include <string>
#include "ModelActor.hpp"
#include "PhysicsManager.hpp"
#include "TimeManager.hpp"
#include "GLMetaseq.h"
#include "GLMetaseqUtil.hpp"
#include "Ball.hpp"

class PlayerBall : public Ball {

public:
    PlayerBall(std::string name, std::string modelName, glm::vec3 position, glm::vec3 euler);
    virtual ~PlayerBall();
    
    glm::vec2 mouseStart;
    glm::vec2 mouseEnd;
        
    virtual void fixedUpdate(float deltaTime);
    virtual void displayUpdate(float deltaTime);
};

#endif /* PlayerBall_hpp */
