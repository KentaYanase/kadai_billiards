//
//  TimeManager.hpp.hpp
//  kadai_billiards
//
//  Created by 簗瀬研太 on 2016/11/23.
//  Copyright © 2016年 Kenta Yanase. All rights reserved.
//

#ifndef TimeManager_hpp
#define TimeManager_hpp

#include <stdio.h>

class TimeManager {
private:
    TimeManager() = default;
    ~TimeManager() = default;
    
    static TimeManager* instance;
    
    static const int fixedUpdateSpan;
    static float time;
    
    static void fixedUpdate (int value);

public:
    TimeManager(const TimeManager&) = delete;
    TimeManager& operator=(const TimeManager&) = delete;
    TimeManager(TimeManager&&) = delete;
    TimeManager& operator=(TimeManager&&) = delete;
    
    static float timeScale;
    
    static float getTime ();
    static TimeManager& getInstance ();
    static void create();
    static void destroy();
    
};

#endif /* TimeManager_hpp */
