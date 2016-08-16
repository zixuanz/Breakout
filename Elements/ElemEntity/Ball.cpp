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


//Resize the ball by a specific scale
void Ball:: resizeBall(GLdouble scale)
{
    this->width = this->width * scale;
    this->height = this->height * scale;
}
