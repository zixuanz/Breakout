//
//  BallDisplay.cpp
//  New-Breakout
//
//  Created by Zixuan Zhao on 8/3/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#include "BallDisplay.hpp"

BallDisplay:: BallDisplay(const GLchar *vp, const GLchar *fp, const GLchar *gp){
    shader = new Shader(vp, fp, gp);
    prepRender();
}

void BallDisplay:: reset(){
    Ball::reset();
    prepRender();
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

void BallDisplay::prepRender(){
    prepVertices();
    prepDataArray();
    model = glm::translate(model, glm::vec3(posX, posY, 0.f));
}


void BallDisplay:: render(){
    
    GLint coor = glGetUniformLocation(shader->Program, "viewCoor");
    shader->runShader();
    glUniformMatrix4fv(coor, 1, GL_FALSE, glm::value_ptr(ortho * camera * model));
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);       //unbind
    glUseProgram(0);
    
}

void BallDisplay:: move(GLfloat radian, GLdouble duration, GLint direction){
    
    GLfloat xDist = velocity * sinf(radian) * duration;
    GLfloat yDist = velocity * cosf(radian) * duration;
    GLfloat gDist = 0.5 * 9.8 * duration * duration;
    
    GLfloat x = 0;
    GLfloat y = 0;
    
    std::cout<< "Direction1: " << direction << " "<< sinf(radian) <<std::endl;
    if (direction %2 != 0) {
        y = yDist - gDist;
        direction -= UP;
    }else if(direction >= DOWN){
        y -= yDist + gDist;
        direction -= DOWN;
    }
    
    std::cout<< "Direction2: " << direction <<std::endl;
    if(direction == LEFT){
        x -= xDist;
    }else if(direction == RIGHT){
        x = xDist;
    }
    posY += y;
    posX += x;
    
    std::cout<< "Ball Posx: " << posX << ", PosY: " << posY <<std::endl;
    
    model = glm::translate(model, glm::vec3(x, y, 0.f));
    
}


void BallDisplay:: shiftBall(GLfloat bump, GLfloat dist){
    
    ElemShift::shift(model, posX, bump, dist);
    
}


