//
//  InputManager.hpp.hpp
//  kadai_billiards
//
//  Created by 簗瀬研太 on 2016/11/23.
//  Copyright © 2016年 Kenta Yanase. All rights reserved.
//

#ifndef InputManager_hpp
#define InputManager_hpp

#include <stdio.h>

class InputManager {
private:
    InputManager() = default;
    ~InputManager() = default;
    
    static InputManager* instance;

    
    
public:
    InputManager(const InputManager&) = delete;
    InputManager& operator=(const InputManager&) = delete;
    InputManager(InputManager&&) = delete;
    InputManager& operator=(InputManager&&) = delete;
    
    static InputManager& getInstance ();
    static void create();
    static void destroy();
};

#endif /* InputManager_hpp */
