//
//  Board.hpp
//  Breakout
//
//  Created by Zixuan Zhao on 4/25/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp


#include "GameElem.hpp"
#include "ElemShift.hpp"


class Board : public GameElem{
    
protected:
    GLfloat velocity;
    
public:
    //constructors
    Board();
    Board(GLfloat width, GLfloat height, GLfloat speed);
    
    //reset all properties of board with default value
    void reset();
    
    //encapsulation for board properties
    void setVelocity(GLfloat velocity);
    GLfloat getVelocity();
    
    //board actions
    void extendBoard(GLfloat scale);                 //extend the width of board. Scale > 0.5

};

#endif /* Board_hpp */
