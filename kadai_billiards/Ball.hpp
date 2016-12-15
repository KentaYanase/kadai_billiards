//
//  Ball.hpp
//  kadai_billiards
//
//  Created by 簗瀬研太 on 2016/12/14.
//  Copyright © 2016年 Kenta Yanase. All rights reserved.
//

#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>
#include <string>
#include "ModelActor.hpp"
#include "PhysicsManager.hpp"
#include "TimeManager.hpp"
#include "GLMetaseq.h"
#include "GLMetaseqUtil.hpp"

class Ball : public ModelActor {
    
protected:
    btSphereShape* shape;
    
public:
    Ball(std::string name, std::string modelName, glm::vec3 position, glm::vec3 euler);
    virtual ~Ball();
    
    bool isFall = false;
    bool target = false;
    
    virtual void fixedUpdate(float deltaTime);
    virtual void displayUpdate(float deltaTime);
};

#endif /* Ball_hpp */
