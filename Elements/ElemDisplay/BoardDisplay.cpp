//
//  BoardDisplay.cpp
//  New-Breakout
//
//  Created by Zixuan Zhao on 8/3/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#include "BoardDisplay.hpp"

BoardDisplay:: BoardDisplay(const GLchar *vp, const GLchar *fp, const GLchar *gp){
    shader = new Shader(vp, fp, gp);
    prepRender();
}

void BoardDisplay:: prepVertices(){
    
    vertices[0].x = -getWidth();
    vertices[0].y = -getHeight();
    vertices[1].x = -getWidth();
    vertices[1].y = getHeight();
    vertices[2].x = getWidth();
    vertices[2].y = getHeight();
    vertices[3].x = getWidth();
    vertices[3].y = -getHeight();
    
}

void BoardDisplay:: reset(){
    Board::reset();
    prepRender();
}


void BoardDisplay:: prepDataArray(){
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &vertexBuffer);
    //glGenBuffers(1, &textureBuffer);
    glGenBuffers(1, &EBO);
    
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 8, vertices, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GL_FLOAT), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLfloat) * 6, index, GL_DYNAMIC_DRAW);
    
    
    /*
    glBindBuffer(GL_ARRAY_BUFFER, textureBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(textureVert), textureVert, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GL_FLOAT), (GLvoid*)0);
    glEnableVertexAttribArray(1);
    */
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
}



void BoardDisplay:: prepRender(){
    prepVertices();
    prepDataArray();
    model = glm::translate(model, glm::vec3(pos.x, pos.y, 0.f));
}

void BoardDisplay:: render(glm::mat4 view){
    
    GLint coor = glGetUniformLocation(shader->Program, "viewCoor");
    shader->runShader();
    glUniformMatrix4fv(coor, 1, GL_FALSE, glm::value_ptr(view * model));
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);       //unbind
    glUseProgram(0);

}

void BoardDisplay:: shiftBoard(GLfloat bump, GLfloat dist){
    
    ElemShift::shift(model, pos.x, bump, dist);

}










