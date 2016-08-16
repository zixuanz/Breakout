//
//  ElemShift.cpp
//  New-Breakout
//
//  Created by Zixuan Zhao on 8/3/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#include "ElemShift.hpp"

//x is current elements position on x-coordinator
void ElemShift:: shift(glm::mat4 &model, GLfloat &x, GLfloat bump, GLfloat displacement){
    
    if (canShift(x, bump, displacement))
    {
        model = glm::translate(model, glm::vec3(displacement, 0.f, 0.f));
        shiftDist(x, displacement);
    }
    
}

//shift the board based on the given displacement
void ElemShift:: shiftDist(GLfloat &x, GLfloat displacement)
{
    x += displacement;
}

//check whether we can shift. After shift, whether the borad is in the range or not.
bool ElemShift:: canShift(GLfloat x, GLfloat bump, GLfloat displacement)
{
    
    if (fabs(x + displacement) <= fabs(1 - bump)) {
        return true;
    }
    return false;
}
