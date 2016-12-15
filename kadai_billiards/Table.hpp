//
//  Table.hpp
//  kadai_billiards
//
//  Created by 簗瀬研太 on 2016/12/14.
//  Copyright © 2016年 Kenta Yanase. All rights reserved.
//

#ifndef Table_hpp
#define Table_hpp

#include <stdio.h>
#include "ModelActor.hpp"
#include "PhysicsManager.hpp"

class Table : public ModelActor {
protected:
    btCompoundShape* floorShape;
    btCompoundShape* wallShape;
    btCompoundShape* topShape;
    
    btRigidBody* wallRigidBody;
    btRigidBody* topRigidBody;
    
    void createRigidBody (int objIndex, btRigidBody* &rigid, btCompoundShape* &shape);
public:
    Table(std::string name);
    virtual ~Table();

//    virtual void fixedUpdate(float deltaTime);
//    virtual void displayUpdate(float deltaTime);
};

#endif /* Table_hpp */
