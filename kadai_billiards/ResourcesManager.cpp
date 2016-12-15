//
//  ResourcesManager.hpp.cpp
//  kadai_billiards
//
//  Created by 簗瀬研太 on 2016/11/23.
//  Copyright © 2016年 Kenta Yanase. All rights reserved.
//


#include "ResourcesManager.hpp"
#include <string>
#include <unistd.h>
#include <sstream>
#include <iostream>

#include <libgen.h>
#include "GLMetaseqUtil.hpp"

char *ResourcesManager::exePath = nullptr;

ResourcesManager* ResourcesManager::instance = nullptr;

ResourcesManager& ResourcesManager::getInstance () {
    return *instance;
}

void ResourcesManager::create() {
    if ( !instance ) {
        mqoInit();
        instance = new ResourcesManager;
    }
}

void ResourcesManager::destroy() {
    if ( instance ) {
        mqoCleanup();

        delete instance;
        instance = nullptr;
    }
}

MQO_MODEL mqoCreateModel (std::string dir, std::string path, float size) {
    return mqoCreateModel(const_cast<char *>((dir + path).c_str()), size);
}

void ResourcesManager::load(){
    std::ostringstream os;
    char *dir;
    dir = dirname(exePath);
    
    instance->mqoModelMap["Cue"] = mqoCreateModel(dir, "/Model/Cue.mqo", 0.00001);   //キュー
    instance->mqoModelMap["BilliardsTable"] = mqoCreateModel(dir, "/Model/BilliardsTable.mqo", 0.001);   //ビリヤード台
    instance->mqoModelMap["Ball"] = mqoCreateModel(dir, "/Model/Ball.mqo", 0.0008);   //ボール
    instance->mqoModelMap["Ball1"] = mqoCreateModel(dir, "/Model/Ball1.mqo", 0.0008);   //ボール
    instance->mqoModelMap["Ball2"] = mqoCreateModel(dir, "/Model/Ball2.mqo", 0.0008);   //ボール
    instance->mqoModelMap["Ball3"] = mqoCreateModel(dir, "/Model/Ball3.mqo", 0.0008);   //ボール
    instance->mqoModelMap["Ball4"] = mqoCreateModel(dir, "/Model/Ball4.mqo", 0.0008);   //ボール
    instance->mqoModelMap["Ball5"] = mqoCreateModel(dir, "/Model/Ball5.mqo", 0.0008);   //ボール
    instance->mqoModelMap["Ball6"] = mqoCreateModel(dir, "/Model/Ball6.mqo", 0.0008);   //ボール
    instance->mqoModelMap["Ball7"] = mqoCreateModel(dir, "/Model/Ball7.mqo", 0.0008);   //ボール
    instance->mqoModelMap["Ball8"] = mqoCreateModel(dir, "/Model/Ball8.mqo", 0.0008);   //ボール
    instance->mqoModelMap["Ball9"] = mqoCreateModel(dir, "/Model/Ball9.mqo", 0.0008);   //ボール
}

void ResourcesManager::unload() {
    //MQOモデル
    for(auto itr = getInstance().mqoModelMap.begin(); itr != getInstance().mqoModelMap.end(); ++itr) {
        mqoDeleteModel(itr->second);
    }
    
    //テクスチャ
//    for(auto itr = getInstance()..begin(); itr != getInstance()..end(); ++itr) {
//    }
    
}

void ResourcesManager::getMqoModel(std::string key, MQO_MODEL& model) {
    model = getInstance().mqoModelMap[key];
}