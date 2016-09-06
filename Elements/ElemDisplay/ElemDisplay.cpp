//
//  ElemDisplay.cpp
//  New-Breakout
//
//  Created by Zixuan Zhao on 8/2/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#include "ElemDisplay.hpp"

glm::vec2* ElemDisplay:: getVertices(){
    return vertices;
}

GLint* ElemDisplay:: getIndex(){
    return index;
}

glm::mat4 ElemDisplay:: getModel(){
    return model;
}

void ElemDisplay:: prepcolorVert(){
    //implement it when need it
}

void ElemDisplay:: preptextureVert(){
    //implement it when need it
}
