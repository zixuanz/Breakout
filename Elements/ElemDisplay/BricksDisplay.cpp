//
//  BricksDisplay.cpp
//  New-Breakout
//
//  Created by Zixuan Zhao on 8/6/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#include "BricksDisplay.hpp"

BricksDisplay:: BricksDisplay(const GLchar *vp, const GLchar *fp, const GLchar *gp, GLint row, GLint col){
    
    this->row = row;
    this->col = col;
    
    shader = new Shader(vp, fp, gp);
    prepRender();
    
}

void BricksDisplay:: reset(){
    Brick::reset();
    prepRender();
}

void BricksDisplay:: prepOffset(){
    offset = (glm:: vec2 *)malloc(sizeof(glm::vec2) * row * col);
    for (GLint i=0; i<row; i++){
        for(GLint j=0; j<col; j++){
            
            if(j == 0){
                offset[i*row].x = 0;
                if(i != 0)
                    offset[i*row].y = offset[(i-1)*row].y - (GLfloat)getHeight() * 2;
                //std::cout<<i*row+j<<","<<offset[i*row+j].x <<","<<offset[i*row+j].y << std::endl;
                continue;
            }
            
            offset[i*row+j].x = offset[i*row+j-1].x + (GLfloat)getWidth() * 2;
            offset[i*row+j].y = offset[i*row].y;
            //std::cout<< "Bricks pos: \n" <<i*row+j<<","<<offset[i*row+j].x <<","<<offset[i*row+j].y << std::endl;
        }
    }
    
}

void BricksDisplay:: setBricks(){
    bricks = (Brick *)malloc(sizeof(Brick) * row * col);
    for(GLint i = 0; i<row*col; i++){
        bricks[i] = * new Brick();
    }
}

void BricksDisplay:: prepVertices(){
    
    vertices[0] = -getWidth();
    vertices[1] = -getHeight();
    vertices[2] = -getWidth();
    vertices[3] = getHeight();
    vertices[4] = getWidth();
    vertices[5] = getHeight();
    vertices[6] = getWidth();
    vertices[7] = -getHeight();
    
}


void BricksDisplay:: prepDataArray(){
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &vertexBuffer);
    glGenBuffers(1, &offsetBuffer);
    //glGenBuffers(1, &textureBuffer);
    glGenBuffers(1, &EBO);
    
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 8, vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GL_FLOAT), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER, offsetBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * 4, &offset[0], GL_STATIC_DRAW);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GL_FLOAT), (GLvoid*)0);
    glEnableVertexAttribArray(1);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLfloat) * 6, index, GL_STATIC_DRAW);
    
    /*
     glBindBuffer(GL_ARRAY_BUFFER, textureBuffer);
     glBufferData(GL_ARRAY_BUFFER, sizeof(textureVert), textureVert, GL_DYNAMIC_DRAW);
     glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GL_FLOAT), (GLvoid*)0);
     glEnableVertexAttribArray(1);
     */
    
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glVertexAttribDivisor(1, 1);
    glBindVertexArray(0);
    
}

void BricksDisplay::prepRender(){
    prepVertices();
    prepOffset();
    prepDataArray();
    model = glm::translate(model, glm::vec3(getWidth() * col * (-1), 0.7f, 0.f));     //--need to ajust it, may need a function
}

void BricksDisplay:: render(glm::mat4 view){
    
    GLint coor = glGetUniformLocation(shader->Program, "viewCoor");
    shader->runShader();
    glUniformMatrix4fv(coor, 1, GL_FALSE, glm::value_ptr(view * model));
    glBindVertexArray(VAO);
    glDrawElementsInstanced(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0, 4);
    glBindVertexArray(0);       //unbind
    glUseProgram(0);
    
}
