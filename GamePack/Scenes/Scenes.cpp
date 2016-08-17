//
//  Scenes.cpp
//  New-Breakout
//
//  Created by Zixuan Zhao on 8/15/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#include "Scenes.hpp"



GLint Scenes:: status = INIT;
GLfloat Scenes:: winWidth = 480.f;
GLfloat Scenes:: winHeight = 640.f;
GLfloat Scenes:: winScale = 1.f;

glm::mat4 Scenes:: camera = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
glm::mat4 Scenes:: ortho = glm::ortho(-1.f, 1.f, -1.f * (GLfloat)winHeight / (GLfloat)winWidth, 1.f * (GLfloat)winWidth / (GLfloat)winHeight, 0.1f, 10.0f);
glm::mat4 Scenes:: view = ortho * camera;

void Scenes:: setWinSize(GLfloat width, GLfloat height){
    Scenes:: winWidth = width;
    Scenes:: winHeight = height;
    
    Scenes:: winScale = (GLfloat)winHeight / (GLfloat)winWidth;
    
    Scenes:: camera = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
    Scenes:: ortho = glm::ortho(-1.f, 1.f, -1.f * winScale, 1.f * winScale, 0.1f, 10.0f);
    Scenes:: view = ortho * camera;
}