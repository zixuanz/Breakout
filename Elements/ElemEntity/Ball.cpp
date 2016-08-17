//
//  Ball.cpp
//  Breakout
//
//  Created by Zixuan Zhao on 4/25/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#include "Ball.hpp"

//Constructor for Ball class
Ball:: Ball(){
    reset();
}

//Reset each parameter to default value
void Ball:: reset(){
    this->setWidth(ELEM_BALL_RADIUS);
    this->setHeight(ELEM_BALL_RADIUS);
    this->updatePos(ELEM_BALL_POSX, ELEM_BALL_POSY);
    this->setVelocity(ELEM_BALL_VELOCITY);
    this->setSpring(ELEM_BALL_SPRING);
}

void Ball:: setVelocity(GLfloat velocity){
    this->velocity = velocity;
}

GLfloat Ball:: getVelocity(){
    return this->velocity;
}

void Ball:: setSpring(GLfloat spring){
    this->spring = spring;
}

GLfloat Ball:: getSpring(){
    return this->spring;
}


//Resize the ball by a specific scale
void Ball:: resizeBall(GLdouble scale)
{
    this->setWidth(this->getWidth() * scale);
    this->setHeight(this->getHeight() * scale);
}



