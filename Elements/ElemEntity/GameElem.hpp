//
//  GameElem.hpp
//  New-Breakout
//
//  Created by Zixuan Zhao on 8/2/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#ifndef GameElem_hpp
#define GameElem_hpp

#include <iostream>

#include "DefElemValue.h"

class GameElem{
    
protected:
    GLfloat width;
    GLfloat height;
    
    GLfloat posX;
    GLfloat posY;
    
public:
    //reset all properties of elements with default value
    virtual void reset() = 0;
    
    //encapsulation for perperties
    void setWidth(GLfloat width);
    GLfloat getWidth();
    
    void setHeight(GLfloat height);
    GLfloat getHeight();
    
    void setPosX(GLfloat x);
    GLfloat getPosX();
    
    void setPosY(GLfloat y);
    GLfloat getPosY();
    
    //update the position of element
    void updatePos(GLfloat x, GLfloat y);
    
    
    
    
};

#endif /* GameElem_hpp */
