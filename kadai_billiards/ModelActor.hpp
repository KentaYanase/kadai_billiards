//
//  ModelActor.hpp
//  kadai_billiards
//
//  Created by 簗瀬研太 on 2016/11/24.
//  Copyright © 2016年 Kenta Yanase. All rights reserved.
//

#ifndef ModelActor_hpp
#define ModelActor_hpp

#include <iostream>
#include <stdio.h>
#include <string>
#include "Actor.hpp"
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include <glm/glm.hpp>
#include "GLMetaseq.h"
#include "ResourcesManager.hpp"
#include <BulletDynamics/btBulletDynamicsCommon.h>

class ModelActor : public Actor {
private:
    
protected:
    
public:
    ModelActor (std::string name);
    ModelActor (std::string name, std::string modelName);
    ModelActor (std::string name, glm::vec3 position, glm::vec3 euler);
    ModelActor (std::string name, glm::vec3 position, glm::vec3 euler, std::string modelName);
    virtual ~ModelActor ();
    
    MQO_MODEL mqoModel = nullptr;
    
    virtual void fixedUpdate(float deltaTime);
    virtual void displayUpdate(float deltaTime);
};

#endif /* ModelActor_hpp */
