//
//  GLDebugDrawer.cpp
//  kadai_billiards
//
//  Created by 簗瀬研太 on 2016/12/14.
//  Copyright © 2016年 Kenta Yanase. All rights reserved.
//

#include "GLDebugDrawer.hpp"

#include <stdio.h> //printf debugging

GLDebugDrawer::GLDebugDrawer() : m_debugMode(0) {
    
}

void GLDebugDrawer::drawLine(const btVector3& from,const btVector3& to,const btVector3& color) {
    glBegin( GL_LINES );
        glColor4f(color.getX(), color.getY(), color.getZ(), 1.0f);
        glVertex3f( from.x(), from.y(), from.z() );
        glColor4f(color.getX(), color.getY(), color.getZ(), 1.0f);
        glVertex3f( to.x(), to.y(), to.z() );
    glEnd();
}

void GLDebugDrawer::setDebugMode(int debugMode) {
    m_debugMode = debugMode;
}

void GLDebugDrawer::draw3dText(const btVector3& location,const char* textString) {
}

void GLDebugDrawer::reportErrorWarning(const char* warningString) {
    printf(warningString);
}

void GLDebugDrawer::drawContactPoint(const btVector3& pointOnB,const btVector3& normalOnB,btScalar distance,int lifeTime,const btVector3& color) {
}