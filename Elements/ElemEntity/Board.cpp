//
//  Board.cpp
//  Breakout
//
//  Created by Zixuan Zhao on 4/25/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#include "Board.hpp"

//Constructor for Board class
Board::Board(){
    reset();
    std::cout<< "Board Non-parameter" << std::endl;
}

Board::Board(float width, float height, float speed){
    this->width = width;
    this->height = height;
    this->speed = speed;
    std::cout<< "Board parameter" << std::endl;
}


void Board::reset(){
    this->height = ELEM_BOARD_HEIGHT;
    this->width = ELEM_BOARD_WIDTH;
    this->posX = ELEM_BOARD_POSX;
    this->posY = ELEM_BOARD_POSY;
    this->speed = 1.0;
}

//encapsulation for board properties
void Board::setSpeed(float speed)
{
    this->speed = speed;
}

float Board::getSpeed()
{
    return this->speed;
}

//extend the width of board
void Board:: extendBoard(double scale)
{
    this->width = this->width * scale;
}

//shift the board based on the given displacement
void Board:: shiftBoard(double displacement)
{
    this->posX += displacement;
}

//check whether we can shift. After shift, whether the borad is in the range or not.
bool Board:: canShift(double displacement)
{
    
    if (fabs(this->posX + displacement) <= fabs(1 - this->width)) {
        return true;
    }
    return false;
}



