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

class ModelActor : public Actor {
private:
    
protected:
    //TODO
    //やっぱりMQOではなくobjファイルローダーを作る.
    MQO_MODEL *mqoModel;
    
public:
    ModelActor (std::string name, std::string modelName);
    virtual ~ModelActor ();
    
    virtual void fixedUpdate(float deltaTime);
    virtual void displayUpdate(float deltaTime);
};

#endif /* ModelActor_hpp */
