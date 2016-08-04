//
//  Shader.cpp
//  Breakout
//
//  Created by Zixuan Zhao on 6/16/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#include "Shader.hpp"

Shader::Shader(const GLchar *vp, const GLchar *fp, const GLchar *gp)
{
    vertexPath = vp;
    fragmentPath = fp;
    geometryPath = gp;
    
    prepShader();
}

void Shader::prepShader()
{
    std::string vString, fString, gString;
    const GLchar *vertexCode, *fragmentCode, *geometryCode;
    
    GLuint vertex, fragment, geometry;
    GLint succ;
    GLchar log[512];
    
    //reading vertex and fragment shader
    try {
        
        std::stringstream vStream, fStream, gStream;
        
        //read vertex shader
        std::ifstream vFile(vertexPath);
        vStream << vFile.rdbuf();
        vFile.close();
        vString = vStream.str();
        //std::cout << vStream.str().size() << std::endl;
        
        //read fragment shader
        std::ifstream fFile(fragmentPath);
        fStream << fFile.rdbuf();
        fFile.close();
        fString = fStream.str();
        
        //read geometry shader
        if (geometryPath != NULL) {
            std::ifstream gFile(geometryPath);
            gStream << gFile.rdbuf();
            gFile.close();
            gString = gStream.str();
        }
        
    }
    catch(std::exception e)
    {
        std::cout << "ERROR: Failed to read Shader file." << std::endl;
        exit(EXIT_FAILURE);
    }

    //compile vertex shader
    vertexCode = vString.c_str();
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertexCode, NULL);
    glCompileShader(vertex);
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &succ);
    if(!succ)
    {
        glGetShaderInfoLog(vertex, 512, NULL, log);
        std::cout << "ERROR: Failed to compile vertex shader.\n" << log << std::endl;
        exit(EXIT_FAILURE);
    };
    
    //compile fragment shader
    fragmentCode = fString.c_str();
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragmentCode, NULL);
    glCompileShader(fragment);
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &succ);
    if(!succ)
    {
        glGetShaderInfoLog(vertex, 512, NULL, log);
        std::cout << "ERROR: Failed to compile fragment shader.\n" << log << std::endl;
        exit(EXIT_FAILURE);
    };
    
    //compile geometry shader
    if (geometryPath != NULL) {
        geometryCode = gString.c_str();
        geometry = glCreateShader(GL_GEOMETRY_SHADER);
        glShaderSource(geometry, 1, &geometryCode, NULL);
        glCompileShader(geometry);
        glGetShaderiv(geometry, GL_COMPILE_STATUS, &succ);
        if(!succ)
        {
            glGetShaderInfoLog(vertex, 512, NULL, log);
            std::cout << "ERROR: Failed to compile geometry shader.\n" << log << std::endl;
            exit(EXIT_FAILURE);
        };
    }
    
    
    //setup shader program
    this->Program = glCreateProgram();
    glAttachShader(this->Program, vertex);
    glAttachShader(this->Program, fragment);
    if (geometryPath != NULL) {
        glAttachShader(this->Program, geometry);
    }
    glLinkProgram(this->Program);
    
    glGetProgramiv(this->Program, GL_LINK_STATUS, &succ);
    if(!succ)
    {
        glGetProgramInfoLog(this->Program, 512, NULL, log);
        std::cout << "ERROR: Failed to link shader. \n" << log << std::endl;
        exit(EXIT_FAILURE);
    }
    
    glDeleteShader(vertex);
    glDeleteShader(fragment);
    if (geometryPath != NULL) {
        glDeleteShader(geometry);
    }
    
}


void Shader::runShader()
{
    glUseProgram(this->Program);
}

