//
//  ElemShift.hpp
//  New-Breakout
//
//  Created by Zixuan Zhao on 8/3/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#ifndef ElemShift_hpp
#define ElemShift_hpp

#include <cmath>

#define GLEW_STATIC
#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class ElemShift{
public:
    static void shift(glm::mat4 &model, GLfloat &x, GLfloat bump, GLfloat displacement);
    static void shiftDist(GLfloat &x, GLfloat displacement);
    static bool canShift(GLfloat x, GLfloat bump, GLfloat displacement);
};

#endif /* ElemShift_hpp */
