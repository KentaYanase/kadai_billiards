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

class Actor {
private:
    
protected:
    
public:
    Actor (std::string name);
    virtual ~Actor ();
    
    std::string name;
    
    glm::vec3 position;
    glm::vec3 euler;
    glm::vec3 scale;

    
    virtual void fixedUpdate(float deltaTime);
    virtual void displayUpdate(float deltaTime);
    
};

#endif /* Actor_hpp */
