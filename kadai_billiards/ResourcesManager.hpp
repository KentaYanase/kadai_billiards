//
//  ResourcesManager.hpp.hpp
//  kadai_billiards
//
//  Created by 簗瀬研太 on 2016/11/23.
//  Copyright © 2016年 Kenta Yanase. All rights reserved.
//

#ifndef ResourcesManager_hpp
#define ResourcesManager_hpp

#include <stdio.h>
#include <string>
#include <map>
#include "GLMetaseq.h"
#include <unistd.h>


class ResourcesManager {
private:
    ResourcesManager() = default;
    ~ResourcesManager() = default;
    
    static ResourcesManager* instance;

    std::map<std::string, MQO_MODEL> mqoModelMap;
    //std::map<std::string, > textureMap;
    
public:
    ResourcesManager(const ResourcesManager&) = delete;
    ResourcesManager& operator=(const ResourcesManager&) = delete;
    ResourcesManager(ResourcesManager&&) = delete;
    ResourcesManager& operator=(ResourcesManager&&) = delete;
    
    static char *exePath;
    
    static ResourcesManager& getInstance ();
    static void create();
    static void destroy();
    
    static void load ();
    static void unload ();
    
    static void getMqoModel (std::string key, MQO_MODEL& model);
    //static const * getTexture (std::string key);
};

#endif /* ResourcesManager_hpp */
