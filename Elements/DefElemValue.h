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

const GLfloat ELEM_BOARD_WIDTH      = 0.15f;
const GLfloat ELEM_BOARD_HEIGHT     = 0.035f;
const GLfloat ELEM_BOARD_POSX       = 0.0f;
const GLfloat ELEM_BOARD_POSY       = -0.7f;
const GLfloat ELEM_BOARD_VELOCITY   = 1.f;

const GLfloat ELEM_BRICK_WIDTH      = 0.1f;
const GLfloat ELEM_BRICK_HEIGHT     = 0.02f;
const GLfloat ELEM_BRICK_SIZE       = 0.01f;

const GLfloat ELEM_BALL_RADIUS      = 0.03f;
const GLfloat ELEM_BALL_POSX        = 0.0f;
const GLfloat ELEM_BALL_POSY        = ELEM_BOARD_POSY + ELEM_BOARD_HEIGHT + ELEM_BALL_RADIUS;
const GLfloat ELEM_BALL_VELOCITY    = 1;
const GLfloat ELEM_BALL_SPRING      = 0.67;

const GLfloat ELEM_SHIFT_DIST       = 0.05f;
const GLfloat ELEM_BUMP_SIZE        = 0.001f;           //the bump for collision
const GLfloat ELEM_ACCELERATION     = 2.f;              //when board hit on the surface of borad, giving an acceleration

enum Shape{
    
};

//Dierections
const GLint TOP                     = 1;
const GLint BOTTOM                  = 8;
const GLint LEFT                    = 4;
const GLint RIGHT                   = 2;

#endif /* DefElemValue_h */
