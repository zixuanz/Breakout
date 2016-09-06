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
    GLint impactDirect[2] = {0, 0};
    GLfloat radian;
    
    void randomRadian();
    
protected:
    //prepare buffers for sending data
    void prepVertices();
    void prepTextureVert();
    void prepDataArray();
    
    //prepare for render
    void prepRender();
    
public:
    
    BallDisplay(const GLchar *vp, const GLchar *fp, const GLchar *gp);
    
    void reset();
    
    //encapsulation
    void setImpactDirect(GLint index, GLint direct);
    
    void setRadian(GLfloat radian);
    GLfloat getRadian();
    
    //render
    void render(glm::mat4 view);
    
    //actions for board
    void move(GLdouble duration);            //move in the playground
    void rebound();
    void updateVelocity(GLdouble duration);
    void shiftBall(GLfloat bump, GLfloat dist);            //shift board

};


#endif /* BallDisplay_hpp */
