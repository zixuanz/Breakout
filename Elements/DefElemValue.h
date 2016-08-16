//
//  DefElemValue.h
//  New-Breakout
//
//  Created by Zixuan Zhao on 8/2/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#ifndef DefElemValue_h
#define DefElemValue_h


#define GLEW_STATIC
#include <GL/glew.h>

const GLfloat ELEM_BOARD_WIDTH = 0.2f;
const GLfloat ELEM_BOARD_HEIGHT = 0.06f;
const GLfloat ELEM_BOARD_POSX = 0.0f;
const GLfloat ELEM_BOARD_POSY = -0.7f;

const GLfloat ELEM_BRICK_WIDTH = 0.1f;
const GLfloat ELEM_BRICK_HEIGHT = 0.05f;
const GLfloat ELEM_BRICK_SIZE = 0.01f;

const GLfloat ELEM_BALL_RADIUS = 0.05f;
const GLfloat ELEM_BALL_POSX = 0.0f;
const GLfloat ELEM_BALL_POSY = ELEM_BOARD_POSY + ELEM_BOARD_HEIGHT + ELEM_BALL_RADIUS;
const GLfloat ELEM_BALL_VELOCITY = 2;
const GLfloat ELEM_BALL_SPRING = 0.67;

const GLfloat ELEM_SHIFT_DIST = 0.02f;

enum Shape{
    
};

//Dierections
const GLint UP = 1;
const GLint DOWN = 8;
const GLint LEFT = 4;
const GLint RIGHT = 2;

#endif /* DefElemValue_h */
