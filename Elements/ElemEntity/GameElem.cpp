//
//  GameElem.cpp
//  New-Breakout
//
//  Created by Zixuan Zhao on 8/2/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#include "GameElem.hpp"

void GameElem:: setWidth(float width){
    this->width = width;
}

float GameElem:: getWidth(){
    return width;
}

void GameElem:: setHeight(float height){
    this->height = height;
}

float GameElem:: getHeight(){
    return height;
}

void  GameElem:: setPosX(float x){
    posX = x;
}

float GameElem:: getPosX(){
    return posX;
}

void GameElem:: setPosY(float y){
    posY = y;
}

float GameElem:: getPosY(){
    return posY;
}

void GameElem:: updatePos(float x, float y){
    posX = x;
    posY = y;
}