//
//  GLMetaseqUtil.hpp
//  kadai_billiards
//
//  Created by 簗瀬研太 on 2016/12/14.
//  Copyright © 2016年 Kenta Yanase. All rights reserved.
//

#ifndef GLMetaseqUtil_hpp
#define GLMetaseqUtil_hpp

#include <stdio.h>
#include "GLMetaseq.h"

class GLMetaseqUtil {
public:
    static void SetColor (MQO_MATERIAL& mat, float r, float g, float b, float a);
    static void SetDifColor (MQO_MATERIAL& mat, float r, float g, float b, float a);
    static void SetAmbColor (MQO_MATERIAL& mat, float r, float g, float b, float a);

    static void SetColorAllMat (MQO_MODEL& model, float r, float g, float b, float a);
    static void SetDifColorAllMat (MQO_MODEL& model, float r, float g, float b, float a);
    static void SetAmbColorAllMat (MQO_MODEL& model, float r, float g, float b, float a);
};

#endif /* GLMetaseqUtil_hpp */