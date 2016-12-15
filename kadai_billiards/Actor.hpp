//
//  gameObject.hpp
//  kadai_billiards
//
//  Created by 簗瀬研太 on 2016/11/23.
//  Copyright © 2016年 Kenta Yanase. All rights reserved.
//

#ifndef Actor_hpp
#define Actor_hpp

#include <stdio.h>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include "GLMetaseq.h"
#include "ResourcesManager.hpp"
#include <BulletDynamics/btBulletDynamicsCommon.h>

class Actor {
private:
    
protected:
    std::string name;
    
    glm::vec3 position;
    glm::vec3 euler;
    
public:
    Actor (std::string name);
    Actor (std::string name, glm::vec3 position, glm::vec3 euler);
    
    virtual ~Actor ();
    
    btRigidBody* rigidBody = nullptr;

    std::string getName();
    
    glm::vec3 getPosition ();
    glm::vec3 getEuler ();
    virtual void setPosition (glm::vec3 position);
    virtual void setEuler (glm::vec3 euler);
    
    //void getTransform (glm::vec3 &position, glm::vec3 &euler, btTransform &worldTrans);
    virtual void applyTransform ();
    virtual void fixedUpdate(float deltaTime);
    virtual void displayUpdate(float deltaTime);
    
};

#endif /* Actor_hpp */
