//
//  BallDisplay.cpp
//  New-Breakout
//
//  Created by Zixuan Zhao on 8/3/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#include "BallDisplay.hpp"

BallDisplay:: BallDisplay(const GLchar *vp, const GLchar *fp, const GLchar *gp){
    prepRender(vp, fp, gp);
}

void BallDisplay:: prepVertices(){
    
    vertices[0] = -width;
    vertices[1] = -height;
    vertices[2] = -width;
    vertices[3] = height;
    vertices[4] = width;
    vertices[5] = height;
    vertices[6] = width;
    vertices[7] = -height;
    
}


void BallDisplay:: prepDataArray(){
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &vertexBuffer);
    //glGenBuffers(1, &textureBuffer);
    glGenBuffers(1, &EBO);
    
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
    
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index), index, GL_DYNAMIC_DRAW);
    
    
    
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GL_FLOAT), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    /*
     glBindBuffer(GL_ARRAY_BUFFER, textureBuffer);
     glBufferData(GL_ARRAY_BUFFER, sizeof(textureVert), textureVert, GL_DYNAMIC_DRAW);
     glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GL_FLOAT), (GLvoid*)0);
     glEnableVertexAttribArray(1);
     */
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
}

void BallDisplay::prepRender(const GLchar *vp, const GLchar *fp, const GLchar *gp){
    shader = new Shader(vp, fp, gp);
    prepVertices();
    prepDataArray();
    model = glm::translate(model, glm::vec3(0.f, posY, 0.f));
}

void BallDisplay:: render(){
    
    GLint coor = glGetUniformLocation(shader->Program, "viewCoor");
    shader->runShader();
    glUniformMatrix4fv(coor, 1, GL_FALSE, glm::value_ptr(ortho * camera * model));
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);       //unbind
    glUseProgram(0);
    
}


void BallDisplay:: keyboardInput(int key, int action){
    //ball motion
    float dist = ELEM_SHIFT_DIST;
    if ((key == GLFW_KEY_LEFT || key == GLFW_KEY_A) && (action == GLFW_REPEAT || action == GLFW_PRESS))
    {
        ElemShift::shift(model, posX, ELEM_BOARD_WIDTH, -dist);
        std::cout<< "ball"<<posX<<std::endl;
    }
    if ((key == GLFW_KEY_RIGHT || key == GLFW_KEY_D) && (action == GLFW_REPEAT || action == GLFW_PRESS))
    {
        ElemShift::shift(model, posX, ELEM_BOARD_WIDTH, dist);
        std::cout<< "ball"<<posX<<std::endl;
    }
}



