//
//  RenderManager.cpp
//  kadai_billiards
//
//  Created by 簗瀬研太 on 2016/11/23.
//  Copyright © 2016年 Kenta Yanase. All rights reserved.
//

#include <GLUT/GLUT.h>
#include <glm/glm.hpp>
#include "Actor.hpp"
#include "RenderManager.hpp"
#include "PhysicsManager.hpp"
#include "ActorManager.hpp"

bool RenderManager::isGameOver = false;
bool RenderManager::isGameClear = false;

const glm::vec2 RenderManager::screenSize = glm::vec2(1280, 720);

RenderManager* RenderManager::instance = nullptr;

void renderString(float x, float y, std::string const& str){
    float z = -1.0f;
    glRasterPos3f(x, y, z);
    for(char c : str){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}

RenderManager& RenderManager::getInstance () {
    return *instance;
}

void RenderManager::create() {
    if ( !instance ) {
        instance = new RenderManager;
        
        glutInitWindowPosition(100, 100);
        glutInitWindowSize(screenSize.x, screenSize.y);
        glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE| GLUT_DEPTH);

        int arg = 0;
        glutInit(&arg, NULL);
        glutCreateWindow(NULL);
        
        glutDisplayFunc(RenderManager::display);
        glutIdleFunc(RenderManager::display);
        glutReshapeFunc(RenderManager::reshape);
//        glutReshapeFunc(resize);
//        glutMouseFunc(mouse);
//        glutKeyboardFunc(keyboard);
//        glutIdleFunc(idle);
        
    }
}

void RenderManager::destroy() {
    if ( instance ) {
        delete instance;
        instance = nullptr;
    }
}

void RenderManager::reshape (int w, int h)
{
    double	znear = 0.10;
    double	zfar = 1000;
    double	fovy = 50;
    
    glViewport(0, 0, w, h);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fovy, (double)w/h, znear, zfar);
    glMatrixMode(GL_MODELVIEW);
}


void RenderManager::setLight () {
    GLfloat light_diffuse[]  = { 0.9, 0.9, 0.9, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_ambient[]  = { 0.3, 0.3, 0.3, 1.0 };
    GLfloat light_position[] = { 0.2, 1.0, 0.2, 0.0 };
    
    glLightfv( GL_LIGHT0, GL_DIFFUSE,  light_diffuse );
    glLightfv( GL_LIGHT0, GL_SPECULAR, light_specular );
    glLightfv( GL_LIGHT0, GL_AMBIENT,  light_ambient );
    glLightfv( GL_LIGHT0, GL_POSITION, light_position );
    
    glShadeModel( GL_SMOOTH );
    glEnable( GL_LIGHT0 );
}

void RenderManager::display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glClearColor(0.f, 0.f, 0.2f, 1.0);

    glLoadIdentity();
    gluLookAt(0, 5, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    
    glEnable( GL_DEPTH_TEST );
    setLight();
    glEnable( GL_LIGHTING );
    
    for(auto actor : ActorManager::getActorList()) {
        actor->displayUpdate(1.0f/60.0f);
    }
    
    glDisable( GL_LIGHTING );
    glDisable( GL_DEPTH_TEST );
    
    //PhysicsManager::debugDrawWorld();
    if(isGameClear) {
        glLoadIdentity();
        renderString(-0.1, 0.0, "GAME CLEAR");
    }
    if(isGameOver) {
        glLoadIdentity();
        renderString(-0.1, 0.0, "GAME OVER");
    }

    glLoadIdentity();
    renderString(0.0, -0.42, "Please drag the mouse and decide the strength and direction.");
    
    glutSwapBuffers();
}