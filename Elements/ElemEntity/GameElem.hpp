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

#include "../DefElemValue.h"

class GameElem{
    
protected:
    float width;
    float height;
    
    float posX;
    float posY;
    
public:
    //reset all properties of elements with default value
    virtual void reset() = 0;
    
    //encapsulation for perperties
    void setWidth(float width);
    float getWidth();
    
    void setHeight(float height);
    float getHeight();
    
    void setPosX(float x);
    float getPosX();
    
    void setPosY(float y);
    float getPosY();
    
    //update the position of element
    void updatePos(float x, float y);
    
    
    
    
};

#endif /* GameElem_hpp */
