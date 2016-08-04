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
void Board:: extendBoard(float scale)
{
    this->width = this->width * scale;
}



