//
//  Brick.cpp
//  Breakout
//
//  Created by Zixuan Zhao on 4/25/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#include "Brick.hpp"

//Constructor for Brick class
Brick::Brick()
{
    reset();
}

void Brick:: reset(){
    this->width = ELEM_BRICK_WIDTH;
    this->height = ELEM_BRICK_HEIGHT;
}

/*
//Reset parameters to default value
void Brick::reset(int type)
{
    switch (type) {
        case QUAD:
        {
            this->height = ELEM_BRICK_HEIGHT;
            this->width = ELEM_BRICK_WIDTH;
        }
            break;
        case POLYGON:
            this->size = ELEM_BRICK_SIZE;
            break;
        default:
            break;
    }
}


void Brick::resetSquareBrick()
{
    this->squareHeight = BRICK_SQUARE_HEIGHT;
    this->squareWidth = BRICK_SQUARE_WIDTH;
}

void Brick::resetPolygonBrick()
{
    this->polygonLength = BRICK_POLYGON_LENGTH;
}
*/


void Brick:: setSkill(int total)
{
    skill = rand() * total;
}

int Brick:: getSkill()
{
    return skill;
}





