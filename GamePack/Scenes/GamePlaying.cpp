//
//  GamePlaying.cpp
//  New-Breakout
//
//  Created by Zixuan Zhao on 8/3/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#include "GamePlaying.hpp"


GamePlaying:: GamePlaying(GLint stage, GLint num, GLint level){
    
    this->stage = stage;
    this->num = num;
    this->level = level;
    
    map = new MapReader("../../New-Breakout/Data/map.xml");
    map->setCurrMap(stage, num);
    board = new BoardDisplay("../../New-Breakout/Shaders/Board.vertex", "../../New-Breakout/Shaders/Board.fragment", NULL);
    ball = new BallDisplay("../../New-Breakout/Shaders/Ball.vertex", "../../New-Breakout/Shaders/Ball.fragment", NULL);
    bricks = new BricksDisplay("../../New-Breakout/Shaders/Bricks.vertex", "../../New-Breakout/Shaders/Bricks.fragment", NULL, map->currMap.row, map->currMap.col);
    
    Scenes::status = READY;
    
}

void GamePlaying:: reset(){
    
    board->reset();
    ball->reset();
    bricks->reset();
    
}

void GamePlaying:: isCollision(){
    
    
    
}


void GamePlaying:: render(){
    
    if (Scenes::status == START) {
        duration = glfwGetTime() - startTime;
        ball->move(M_PI/4, duration, UP+LEFT);
        std::cout<< UP << std::endl;
        startTime = glfwGetTime();
    }
    
    
    board->render();
    ball->render();
    bricks->render();
}

void GamePlaying:: keyboardInput(GLint key, GLint action){
    std::cout<<Scenes::status<<std::endl;
    GLfloat dist = ELEM_SHIFT_DIST * board->getSpeed();
    
    switch (Scenes::status) {
        case READY:
        {
            /*
             After load everthing, game enter READY progress.
             In this progress, only board and ball can be moved by arrows.
             When space is pressed, game will enter START progress.
             Ball will be sent out from current place and move.
             */
            if(key == GLFW_KEY_SPACE && action == GLFW_PRESS){
                Scenes::status = START;
                startTime = glfwGetTime();
            }
            
            if ((key == GLFW_KEY_LEFT || key == GLFW_KEY_A) && (action == GLFW_REPEAT || action == GLFW_PRESS))
            {
                //ball shift
                ball->shiftBall(board->getWidth(), -dist);
                //std::cout<< "ball posX:"<<ball->getPosX()<<std::endl;
                
            }
            
            if ((key == GLFW_KEY_RIGHT || key == GLFW_KEY_D) && (action == GLFW_REPEAT || action == GLFW_PRESS))
            {
                //ball shift
                ball->shiftBall(board->getWidth(), dist);
                //std::cout<< "ball posX:"<<ball->getPosX()<<std::endl;
            }

        }
            
        case START:{
            /*
             In START progress, only board can be moved by arrows.
             */
            
            if ((key == GLFW_KEY_LEFT || key == GLFW_KEY_A) && (action == GLFW_REPEAT || action == GLFW_PRESS))
            {
                //board shift
                board->shiftBoard(board->getWidth(), -dist);
                //std::cout<< "board posX:"<<board->getPosX()<<std::endl;
            }
            
            if ((key == GLFW_KEY_RIGHT || key == GLFW_KEY_D) && (action == GLFW_REPEAT || action == GLFW_PRESS))
            {
                //board shift
                board->shiftBoard(board->getWidth(), dist);
                //std::cout<< "board posX:"<<board->getPosX()<<std::endl;
                
            }
            
            break;
        }
            
        default:
            break;
    }
    

}