//
//  Scenes.hpp
//  New-Breakout
//
//  Created by Zixuan Zhao on 8/15/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#ifndef Scenes_hpp
#define Scenes_hpp

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "DefGameValue.h"

class Scenes{
protected:
    static GLint status;
    
    
public:
    virtual void render() = 0;
    virtual void keyboardInput(GLint key, GLint action) = 0;
    
};

#endif /* Scenes_hpp */
