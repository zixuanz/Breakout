//
//  Board.hpp
//  Breakout
//
//  Created by Zixuan Zhao on 4/25/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <cmath>

#include "GameElem.hpp"


class Board : public GameElem{
    
private:
    float speed;
    
public:
    //constructors
    Board();
    Board(float width, float height, float speed);
    
    //reset all properties of board with default value
    void reset();
    
    //encapsulation for board properties
    void setSpeed(float speed);
    float getSpeed();
    
    //board actions
    void extendBoard(double scale);                 //extend the width of board. Scale > 0.5
    void shiftBoard(double displacement);
    bool canShift(double displacement);
};

#endif /* Board_hpp */
