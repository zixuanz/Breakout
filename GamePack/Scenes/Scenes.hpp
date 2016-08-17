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

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "DefGameValue.h"


class Scenes{
    
protected:
    static GLfloat winWidth;
    static GLfloat winHeight;
    
    static GLint status;
    static glm::mat4 camera;
    static glm::mat4 ortho;
    static GLfloat winScale;
    static glm::mat4 view;
    
public:
    
    static void setWinSize(GLfloat width, GLfloat height);
    
    virtual void render() = 0;
    virtual void keyboardInput(GLint key, GLint action) = 0;
    
};

#endif /* Scenes_hpp */
