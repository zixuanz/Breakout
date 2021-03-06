//
//  Ball.hpp
//  Breakout
//
//  Created by Zixuan Zhao on 4/25/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#ifndef Ball_hpp
#define Ball_hpp

#include "GameElem.hpp"
#include "ElemShift.hpp"


class Ball : public GameElem{
    
protected:
    GLfloat velocity;
    GLfloat spring;
    
public:
    
    Ball();
    
    void reset();
    
    void setVelocity(GLfloat velocity);
    GLfloat getVelocity();
    
    void setSpring(GLfloat spring);
    GLfloat getSpring();
    
    void resizeBall(GLdouble scale);                  //Resize the ball by a specific scale. Scale > 1.0
    
};


#endif /* Ball_hpp */
