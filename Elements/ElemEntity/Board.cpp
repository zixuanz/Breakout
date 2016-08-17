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
    //std::cout<< "Board Non-parameter" << std::endl;
}

Board::Board(GLfloat width, GLfloat height, GLfloat velocity){
    this->setWidth(width);
    this->setHeight(height);
    this->updatePos(ELEM_BOARD_POSX, ELEM_BOARD_POSY);
    this->setVelocity(velocity);
    
    //std::cout<< "Board parameter" << this->width << std::endl;
}


void Board::reset(){
    this->setWidth(ELEM_BOARD_WIDTH);
    this->setHeight(ELEM_BOARD_HEIGHT);
    this->updatePos(ELEM_BOARD_POSX, ELEM_BOARD_POSY);
    this->setVelocity(ELEM_BOARD_VELOCITY);
}

//encapsulation for board properties
void Board::setVelocity(GLfloat velocity)
{
    this->velocity = velocity;
}

GLfloat Board::getVelocity()
{
    return this->velocity;
}

//extend the width of board
void Board:: extendBoard(GLfloat scale)
{
    this->setWidth(this->getWidth() * scale);
}



