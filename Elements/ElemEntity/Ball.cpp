//
//  Ball.cpp
//  Breakout
//
//  Created by Zixuan Zhao on 4/25/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#include "Ball.hpp"

//Constructor for Ball class
Ball::Ball(){
    reset();
}

//Reset each parameter to default value
void Ball::reset(){
    this->width = ELEM_BALL_RADIUS;
    this->height = ELEM_BALL_RADIUS;
    this->posX = ELEM_BALL_POSX;
    this->posY = ELEM_BALL_POSY;
    this->velocity = ELEM_BALL_VELOCITY;
}

//move the ball after duration with radian angle
void Ball:: moveTo(GLfloat radian, GLdouble duration, GLint direction){
    
    GLfloat verticalDist = velocity * cosf(radian) * duration;
    GLfloat horizontalDist = velocity * sinf(radian) * duration;
    GLfloat gravityDist = 0.5 * 0.98 * duration * duration;
    std::cout<<direction<< " "<< sinf(radian) <<std::endl;
    if (direction %2 != 0) {
        posY += verticalDist - gravityDist;
        direction -= UP;
    }else if(direction >= DOWN){
        posY -= verticalDist + gravityDist;
        direction -= DOWN;
    }
    std::cout<<direction<<std::endl;
    if(direction == LEFT){
        posX -= horizontalDist;
    }else if(direction == RIGHT){
        posX += horizontalDist;
    }
    std::cout<< posX << " " << posY <<std::endl;
    
}

//Resize the ball by a specific scale
void Ball:: resizeBall(GLdouble scale)
{
    this->width = this->width * scale;
    this->height = this->height * scale;
}
