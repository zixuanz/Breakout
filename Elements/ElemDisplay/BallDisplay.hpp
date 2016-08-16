//
//  BallDisplay.hpp
//  New-Breakout
//
//  Created by Zixuan Zhao on 8/3/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#ifndef BallDisplay_hpp
#define BallDisplay_hpp

#include "Ball.hpp"
#include "ElemDisplay.hpp"


class BallDisplay: public Ball, public ElemDisplay{
    
private:
    double seconds;
    
public:
    
    BallDisplay(const GLchar *vp, const GLchar *fp, const GLchar *gp);
    
    void reset();
    
    //prepare buffers for sending data
    void prepVertices();
    void prepTextureVert();
    void prepDataArray();
    
    //prepare for render
    void prepRender();
    
    //render
    void render();
    
    //actions for board
    void move(GLfloat radian, GLdouble duration, GLint direction);            //move in the playground
    void shiftBall(GLfloat bump, GLfloat dist);            //shift board

};


#endif /* BallDisplay_hpp */
