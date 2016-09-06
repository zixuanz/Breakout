//
//  BallDisplay.cpp
//  New-Breakout
//
//  Created by Zixuan Zhao on 8/3/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#include "BallDisplay.hpp"

BallDisplay:: BallDisplay(const GLchar *vp, const GLchar *fp, const GLchar *gp){
    
    randomRadian();

    shader = new Shader(vp, fp, gp);
    prepRender();
}

void BallDisplay:: reset(){
    
    randomRadian();

    Ball::reset();
    prepRender();
}

void BallDisplay:: setImpactDirect(GLint index, GLint direct){
    this->impactDirect[index] = direct;
}

void BallDisplay:: setRadian(GLfloat radian){
    this->radian = radian;
}

GLfloat BallDisplay:: getRadian(){
    return this->radian;
}

void BallDisplay:: randomRadian(){
    
    GLint neg[2] = {-1, 1};
    srand(time(NULL));
    //GLfloat temp = ((float) rand()) / (float) RAND_MAX * 0.5 * M_PI * neg[(rand() % 2)];
    GLfloat temp = -1 * M_PI / 4;
    this->setRadian(temp);
    std::cout<< temp <<std::endl;
}

void BallDisplay:: prepVertices(){
    
    vertices[0].x = -getWidth();
    vertices[0].y = -getHeight();
    vertices[1].x = -getWidth();
    vertices[1].y = getHeight();
    vertices[2].x = getWidth();
    vertices[2].y = getHeight();
    vertices[3].x = getWidth();
    vertices[3].y = -getHeight();
    
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
    model = glm::translate(model, glm::vec3(pos.x, pos.y, 0.f));
}


void BallDisplay:: render(glm::mat4 view){
    
    GLint coor = glGetUniformLocation(shader->Program, "viewCoor");
    shader->runShader();
    glUniformMatrix4fv(coor, 1, GL_FALSE, glm::value_ptr(view * model));
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);       //unbind
    glUseProgram(0);
    
}

/*
void BallDisplay:: move(GLdouble duration){
    
    GLfloat xDist = velocity * sinf(radian) * duration;
    GLfloat yDist = velocity * cosf(radian) * duration - 0.5 * 9.8 * duration * duration;
    
    model = glm::translate(model, glm::vec3(xDist, yDist, 0.f));
    
    updatePos(getPosX()+xDist, getPosY() + yDist);
    
    //std::cout<< "Ball Radian: " << radian << "; Ball pos:" << pos.x << " " << pos.y << std::endl;
    
}
 */

void BallDisplay:: move(GLdouble duration){
    GLfloat xDist = velocity * sinf(radian) * duration;
    GLfloat yDist = velocity * cosf(radian) * duration - 0.5 * 9.8 * duration * duration;

    
    model = glm::translate(model, glm::vec3(xDist, yDist, 0.f));
    updatePos(getPosX()+xDist, getPosY() + yDist);
    //model = glm::rotate(model, (GLfloat)(5.f * duration), glm::vec3(pos, 1));
    
    
    std::cout<< "Ball Radian: " << radian << "; Ball pos:" << pos.x << " " << pos.y << std::endl;
    
}


void BallDisplay:: updateVelocity(GLdouble duration){

    GLfloat tempVelocity = glm::length( glm::vec2(0, velocity * cosf(radian) - 9.8 * duration)
                                       + glm::vec2(velocity * sinf(radian), 0) );
    GLfloat tempRadian = acosf((GLfloat)velocity * sinf(radian) / (GLfloat)tempVelocity);
    
    setRadian(tempRadian);
    setVelocity(tempVelocity);
 
    
}


/* try to simplify it but not easy for first one
void BallDisplay:: rebound(){
    
    radian = impactDirect[0] != 0 ? (sinf(radian) * M_PI - radian): radian;
    
    radian *= impactDirect[1] != 0 ? (-1) : 1;
    
    impactDirect[0] = 0;
    impactDirect[1] = 0;
}
*/



void BallDisplay:: rebound(){
    
    if (impactDirect[0] != 0) {
        if(radian <= 0){
            radian = -(M_PI + radian);
        }else{
            radian = M_PI - radian;
        }
    }
    
    if (impactDirect[1] != 0) {
        radian *= -1;
    }
    std::cout << "impact direction:" << impactDirect[0] << " " << impactDirect[1] << std::endl;
    impactDirect[0] = 0;
    impactDirect[1] = 0;
    
}



/*
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

*/

void BallDisplay:: shiftBall(GLfloat bump, GLfloat dist){
    
    ElemShift::shift(model, pos.x, bump, dist);
    
}


