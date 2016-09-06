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

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.hpp"
#include "Tools.hpp"

class ElemDisplay{
    
protected:
    
    
    //buffers
    GLuint VAO;
    GLuint vertexBuffer;
    GLuint colorBuffer;
    GLuint textureBuffer;
    GLuint EBO;
    
    //vertex info
    glm::vec2 vertices[4];
    glm::vec2 colorVert[6];
    glm::vec2 textureVert[4];
    glm::vec2 normalVert[6];
    
    //the index for quard
    GLint index[6] = {
        0, 1, 2,
        0, 2, 3
    };
    
    //shader program
    Shader *shader;
    
    //view in window
    glm::mat4 model = glm::mat4(1);
    
    //prepare buffers for sending data
    virtual void prepVertices() = 0;
    virtual void prepcolorVert();
    virtual void preptextureVert();
    virtual void prepDataArray() = 0;
    
    //prepare for render
    virtual void prepRender() = 0;
    
public:
    
    //encapsulation for neccessary
    
    virtual void reset() = 0;
    
    glm::vec2* getVertices();
    GLint* getIndex();
    glm::mat4 getModel();
    
    //get input methods
    //void updateKeyboard(int key, int action);
    
    
    
    //render
    virtual void render(glm::mat4 view) = 0;
    
    
};


#endif /* ElemDisplay_hpp */
