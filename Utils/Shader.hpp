//
//  Shader.hpp
//  Breakout
//
//  Created by Zixuan Zhao on 6/16/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#ifndef Shader_hpp
#define Shader_hpp

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>

class Shader{
    
private:
    const GLchar *vertexPath;
    const GLchar *fragmentPath;
    const GLchar *geometryPath;

public:
    GLuint Program;
    
    Shader(const GLchar *vp, const GLchar *fp, const GLchar *gp = NULL);
    void readShader();
    void prepShader();
    void runShader();
};
#endif /* Shader_hpp */
