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

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class ElemShift{
public:
    static void shift(glm::mat4 &model, float &x, float bump, float displacement);
    static void shiftDist(float &x, float displacement);
    static bool canShift(float x, float bump, float displacement);
};

#endif /* ElemShift_hpp */
