//
//  Table.cpp
//  kadai_billiards
//
//  Created by 簗瀬研太 on 2016/12/14.
//  Copyright © 2016年 Kenta Yanase. All rights reserved.
//

#include "Table.hpp"

void Table::createRigidBody (int objIndex, btRigidBody* &rigid, btCompoundShape* &shape) {
    
    shape = new btCompoundShape();
    
    btVector3 vec1, vec2, vec3;
    MQO_INNER_OBJECT obj = mqoModel->obj[objIndex];

    btTransform trans;
    trans.setIdentity();
    
    for(int j=0;j<obj.matnum;j++) {
        MQO_MATERIAL mat = obj.mat[j];
        if(mat.datanum < 9) continue;
        
        btTriangleMesh* triangleMesh = new btTriangleMesh;
        for(int k=0;k<mat.datanum;k+=3) {
            if (mat.isUseTexture) {
                vec1 = btVector3(mat.vertex_t[k].point[0], mat.vertex_t[k].point[1], mat.vertex_t[k].point[2]);
                vec2 = btVector3(mat.vertex_t[k+1].point[0], mat.vertex_t[k+1].point[1], mat.vertex_t[k+1].point[2]);
                vec3 = btVector3(mat.vertex_t[k+2].point[0], mat.vertex_t[k+2].point[1], mat.vertex_t[k+2].point[2]);
            }else {
                vec1 = btVector3(mat.vertex_p[k].point[0], mat.vertex_p[k].point[1], mat.vertex_p[k].point[2]);
                vec2 = btVector3(mat.vertex_p[k+1].point[0], mat.vertex_p[k+1].point[1], mat.vertex_p[k+1].point[2]);
                vec3 = btVector3(mat.vertex_p[k+2].point[0], mat.vertex_p[k+2].point[1], mat.vertex_p[k+2].point[2]);
            }
            triangleMesh->addTriangle(vec1, vec2, vec3);
        }
        
        auto meshShape = new btBvhTriangleMeshShape(triangleMesh, true, true);
        shape->addChildShape(trans, meshShape);
    }
    
    btVector3 localInertia(0,0,0);
    btDefaultMotionState* motionState = new btDefaultMotionState();
    btRigidBody::btRigidBodyConstructionInfo rbInfo(0.0, motionState, shape, localInertia);
    rigid = new btRigidBody(rbInfo);
    rigid->setCollisionFlags( rigid->getCollisionFlags() | btCollisionObject::CF_KINEMATIC_OBJECT);
    rigid->setActivationState(DISABLE_DEACTIVATION);
}

Table::Table (std::string name) : ModelActor(name){
    ResourcesManager::getMqoModel("BilliardsTable", mqoModel);

    //TOP Shape
    btTransform trans;
    trans.setIdentity();
    trans.setOrigin(btVector3(0,0.65,0));
    btBoxShape* box = new btBoxShape(btVector3( 5.0f, 0.4f, 3.0f));
    topShape = new btCompoundShape();
    topShape->addChildShape(trans, box);
    
    btVector3 localInertia(0,0,0);
    btDefaultMotionState* motionState = new btDefaultMotionState();
    btRigidBody::btRigidBodyConstructionInfo topRbInfo(0.0, motionState, topShape, localInertia);
    topRigidBody = new btRigidBody(topRbInfo);
    
    topRigidBody->setCollisionFlags( topRigidBody->getCollisionFlags() | btCollisionObject::CF_KINEMATIC_OBJECT);
    topRigidBody->setActivationState(DISABLE_DEACTIVATION);
    topRigidBody->setRestitution(0.0);
    topRigidBody->setFriction(0.0f);
    PhysicsManager::addRigidBody(topRigidBody);
    
    //Floor
    createRigidBody(1, rigidBody, floorShape);
    rigidBody->setRestitution(0.0);
    rigidBody->setFriction(0.5f);
    PhysicsManager::addRigidBody(rigidBody);
    
    //Wall
    createRigidBody(2, wallRigidBody, wallShape);
    wallRigidBody->setRestitution(0.9);
    wallRigidBody->setFriction(0.0f);
    PhysicsManager::addRigidBody(wallRigidBody);
}

Table::~Table(){
    delete floorShape;
    delete topShape;
    delete wallShape;
    delete topRigidBody;
    delete wallRigidBody;
}
//
//void Table::fixedUpdate(float deltaTime) {
//    ModelActor::fixedUpdate(deltaTime);
//    //euler.x += deltaTime*10.0f;
//}
//
//void Table::displayUpdate(float deltaTime) {
//    ModelActor::displayUpdate(deltaTime);
//}
