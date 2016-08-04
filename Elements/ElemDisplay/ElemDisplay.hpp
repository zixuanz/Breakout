//
//  ElemDisplay.hpp
//  New-Breakout
//
//  Created by Zixuan Zhao on 8/2/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#ifndef ElemDisplay_hpp
#define ElemDisplay_hpp

#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../../Utils/Shader.hpp"
const float MAIN_WINDOW_WIDTH = 480;
const float MAIN_WINDOW_HEIGHT = 640;


class ElemDisplay{
    
protected:
    
    //buffers
    GLuint VAO;
    GLuint vertexBuffer;
    GLuint colorBuffer;
    GLuint textureBuffer;
    GLuint offsetBuffer;
    GLuint EBO;
    
    //vertex info
    float vertices[8];
    float colorVert[12];
    float textureVert[8];
    float normalVert[12];
    
    //the index for quard
    int index[6] = {
        0, 1, 2,
        0, 2, 3
    };
    
    //shader program
    Shader *shader;
    
    //view in window
    glm::mat4 camera = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
    glm::mat4 ortho = glm::ortho(-1.f, 1.f, -1.f * (GLfloat)MAIN_WINDOW_HEIGHT / (GLfloat)MAIN_WINDOW_WIDTH, 1.f * (GLfloat)MAIN_WINDOW_HEIGHT / (GLfloat)MAIN_WINDOW_WIDTH, 0.1f, 10.0f);
    glm::mat4 model;
    
public:
    
    //encapsulation for neccessary
    
    float* getVertices();
    int* getIndex();
    
    //get input methods
    //void updateKeyboard(int key, int action);
    
    //prepare buffers for sending data
    virtual void prepVertices() = 0;
    virtual void prepcolorVert();
    virtual void preptextureVert();
    
    virtual void prepDataArray() = 0;
    
    //prepare for render
    virtual void prepRender(const GLchar *vp, const GLchar *fp, const GLchar *gp = NULL) = 0;
    
    //render
    virtual void render() = 0;
    
    //keyboard input solution
    virtual void keyboardInput(int key, int action) = 0;
    
    
};


#endif /* ElemDisplay_hpp */