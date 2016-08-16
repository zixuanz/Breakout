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
    posX = x;
}

GLfloat GameElem:: getPosX(){
    return posX;
}

void GameElem:: setPosY(GLfloat y){
    posY = y;
}

GLfloat GameElem:: getPosY(){
    return posY;
}

void GameElem:: updatePos(GLfloat x, GLfloat y){
    posX = x;
    posY = y;
}