//
//  GLMetaseqUtil.cpp
//  kadai_billiards
//
//  Created by 簗瀬研太 on 2016/12/14.
//  Copyright © 2016年 Kenta Yanase. All rights reserved.
//

#include "GLMetaseqUtil.hpp"

void GLMetaseqUtil::SetColorAllMat (MQO_MODEL& model, float r, float g, float b, float a) {
    for(int i=0; i<model->objnum; i++) {
        MQO_INNER_OBJECT& obj = model->obj[i];
        for(int j=0; j<obj.matnum; j++) {
            MQO_MATERIAL& mat = obj.mat[j];
            SetColor(mat, r, g, b, a);
        }
    }
}

void GLMetaseqUtil::SetDifColorAllMat (MQO_MODEL& model, float r, float g, float b, float a){
    for(int i=0; i<model->objnum; i++) {
        MQO_INNER_OBJECT& obj = model->obj[i];
        for(int j=0; j<obj.matnum; j++) {
            MQO_MATERIAL& mat = obj.mat[j];
            SetDifColor(mat, r, g, b, a);
        }
    }
}

void GLMetaseqUtil::SetAmbColorAllMat (MQO_MODEL& model, float r, float g, float b, float a){
    for(int i=0; i<model->objnum; i++) {
        MQO_INNER_OBJECT& obj = model->obj[i];
        for(int j=0; j<obj.matnum; j++) {
            MQO_MATERIAL& mat = obj.mat[j];
            SetAmbColor(mat, r, g, b, a);
        }
    }
}

void GLMetaseqUtil::SetColor (MQO_MATERIAL& mat, float r, float g, float b, float a) {
    mat.color[0] = r;
    mat.color[1] = g;
    mat.color[2] = b;
    mat.color[3] = a;
}

void GLMetaseqUtil::SetDifColor (MQO_MATERIAL& mat, float r, float g, float b, float a) {
    mat.dif[0] = r;
    mat.dif[1] = g;
    mat.dif[2] = b;
    mat.dif[3] = a;
}

void GLMetaseqUtil::SetAmbColor (MQO_MATERIAL& mat, float r, float g, float b, float a) {
    mat.amb[0] = r;
    mat.amb[1] = g;
    mat.amb[2] = b;
    mat.amb[3] = a;
}

