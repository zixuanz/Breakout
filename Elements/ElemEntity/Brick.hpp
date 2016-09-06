//
//  Brick.hpp
//  Breakout
//
//  Created by Zixuan Zhao on 4/25/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#ifndef Brick_hpp
#define Brick_hpp


#include "GameElem.hpp"

class Brick: public GameElem{
private:
//    GLfloat size;
    GLint skill;
    GLboolean exist;
    
public:
    
    Brick();
    
    void reset();
    //void resetSquareBrick();
    //void resetPolygonBrick();
    
    //decide what kind of bonus this brick will contain
    void setSkill(GLint total);
    GLint getSkill();
        
    void setExist(GLboolean exist);
    GLboolean getExist();
    
    //brick property
    
};

#endif /* Brick_hpp */
