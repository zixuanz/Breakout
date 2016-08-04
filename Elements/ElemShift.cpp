//
//  ElemShift.cpp
//  New-Breakout
//
//  Created by Zixuan Zhao on 8/3/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#include "ElemShift.hpp"

//
void ElemShift:: shift(glm::mat4 &model, float &x, float bump, float displacement){
    
    if (canShift(x, bump, displacement))
    {
        model = glm::translate(model, glm::vec3(displacement, 0.f, 0.f));
        shiftDist(x, displacement);
    }
    
}

//shift the board based on the given displacement
void ElemShift:: shiftDist(float &x, float displacement)
{
    x += displacement;
}

//check whether we can shift. After shift, whether the borad is in the range or not.
bool ElemShift:: canShift(float x, float bump, float displacement)
{
    
    if (fabs(x + displacement) <= fabs(1 - bump)) {
        return true;
    }
    return false;
}
