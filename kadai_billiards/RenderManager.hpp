//
//  RenderManager.hpp
//  kadai_billiards
//
//  Created by 簗瀬研太 on 2016/11/23.
//  Copyright © 2016年 Kenta Yanase. All rights reserved.
//

#ifndef RenderManager_hpp
#define RenderManager_hpp

#include <stdio.h>
#include <vector>
#include <GLUT/GLUT.h>
#include <glm/glm.hpp>
#include "Actor.hpp"

class RenderManager {
    
private:
    RenderManager() = default;
    ~RenderManager() = default;
    
    static RenderManager* instance;
    
    static const glm::vec2 screenSize;
    
    static void reshape (int w, int h);
    static void display ();
    static void setLight ();
    
public:
    RenderManager(const RenderManager&) = delete;
    RenderManager& operator=(const RenderManager&) = delete;
    RenderManager(RenderManager&&) = delete;
    RenderManager& operator=(RenderManager&&) = delete;
   
    static RenderManager& getInstance ();
    static void create();
    static void destroy();
};

#endif /* RenderManager_hpp */
