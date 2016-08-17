//
//  GameElem.cpp
//  New-Breakout
//
//  Created by Zixuan Zhao on 8/2/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#include "GameElem.hpp"

void GameElem:: setWidth(GLfloat width){
    this->width = width;
}

GLfloat GameElem:: getWidth(){
    return width;
}

void GameElem:: setHeight(GLfloat height){
    this->height = height;
}

GLfloat GameElem:: getHeight(){
    return height;
}

void  GameElem:: setPosX(GLfloat x){
    pos.x = x;
}

GLfloat GameElem:: getPosX(){
    return pos.x;
}

void GameElem:: setPosY(GLfloat y){
    pos.y = y;
}

GLfloat GameElem:: getPosY(){
    return pos.y;
}

glm::vec2 GameElem:: getPos(){
    return pos;
}

void GameElem:: updatePos(GLfloat x, GLfloat y){
    pos.x = x;
    pos.y = y;
}