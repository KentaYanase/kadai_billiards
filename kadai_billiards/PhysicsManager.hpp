//
//  PhysicsManager.hpp.hpp
//  kadai_billiards
//
//  Created by 簗瀬研太 on 2016/11/23.
//  Copyright © 2016年 Kenta Yanase. All rights reserved.
//

#ifndef PhysicsManager_hpp
#define PhysicsManager_hpp

#include <stdio.h>
#include "GLDebugDrawer.hpp"
#include <LinearMath/btIDebugDraw.h>
#include <BulletDynamics/btBulletDynamicsCommon.h>

class PhysicsManager {
private:
    PhysicsManager() = default;
    ~PhysicsManager() = default;
    
    static PhysicsManager* instance;

    btDefaultCollisionConfiguration* collisionConfiguration;
    btCollisionDispatcher* dispatcher;
    btBroadphaseInterface* overlappingPairCache;
    btSequentialImpulseConstraintSolver* solver;
    btDiscreteDynamicsWorld* dynamicsWorld;
    
public:
    
    PhysicsManager(const PhysicsManager&) = delete;
    PhysicsManager& operator=(const PhysicsManager&) = delete;
    PhysicsManager(PhysicsManager&&) = delete;
    PhysicsManager& operator=(PhysicsManager&&) = delete;
    
    GLDebugDrawer* debugDrawer;
    
    static const int maxSubSteps;
    
    static PhysicsManager& getInstance ();
    static void create();
    static void destroy();
    
    static void stepSimulation (float deltaTime);
    static void addRigidBody (btRigidBody* rigidBody);
    static void removeRigidBody (btRigidBody* rigidBody);
    static void debugDrawWorld ();
    static void contactTest (btRigidBody *rigidBody, btCollisionWorld::ContactResultCallback &resultCallback);
};

#endif /* PhysicsManager_hpp */
