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

void ResourcesManager::load(){
    std::ostringstream os;
    char *dir;
    dir = dirname(exePath);
    //MQOモデル
    std::string ballPath = dir; ballPath += "/Ball.mqo";
    std::string cuePath = dir; cuePath += "/Cue.mqo";
    std::string billiardsTablePath = dir; billiardsTablePath += "/BilliardsTable.mqo";
    
    instance->mqoModelMap["Ball"] = mqoCreateModel(const_cast<char *>(ballPath.c_str()), 0.0001);   //ボール
    instance->mqoModelMap["Cue"] = mqoCreateModel(const_cast<char *>(cuePath.c_str()), 0.00001);   //キュー
    instance->mqoModelMap["BilliardsTable"] = mqoCreateModel(const_cast<char *>(billiardsTablePath.c_str()), 0.0001);   //ビリヤード台
    
//    instance->mqoModelMap["Ball"] = mqoCreateModel("Ball.mqo", 0.0001);   //ボール
//    instance->mqoModelMap["Cue"] = mqoCreateModel( "Cue.mqo", 0.00001);   //キュー
//    instance->mqoModelMap["BilliardsTable"] = mqoCreateModel( "BilliardsTable.mqo", 0.0001);   //ビリヤード台
    
    //テクスチャ
        //1番ボール
        //2番
        //3番
        //4番
        //5番
        //6番
        //7番
        //8番
        //9番
    
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

MQO_MODEL* ResourcesManager::getMqoModel(std::string key) {
    return &getInstance().mqoModelMap[key];
}