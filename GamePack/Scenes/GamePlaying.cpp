//
//  GamePlaying.cpp
//  New-Breakout
//
//  Created by Zixuan Zhao on 8/3/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#include "GamePlaying.hpp"

MapReader* GamePlaying:: map = new MapReader("../../New-Breakout/Data/map.xml");

GamePlaying:: GamePlaying(GLint stage, GLint num, GLint level){
    
    this->stage = stage;
    this->num = num;
    this->level = level;
    
    //load map
    map->setCurrMap(stage, num);
    
    //setup all game elements
    board = new BoardDisplay("../../New-Breakout/Shaders/Board.vertex", "../../New-Breakout/Shaders/Board.fragment", NULL);
    ball = new BallDisplay("../../New-Breakout/Shaders/Ball.vertex", "../../New-Breakout/Shaders/Ball.fragment", NULL);
    bricks = new BricksDisplay("../../New-Breakout/Shaders/Bricks.vertex", "../../New-Breakout/Shaders/Bricks.fragment", NULL, map->currMap.row, map->currMap.col, map->currMap.pattern);
    
    
    //change status of current game process
    Scenes::status = READY;
    
}

void GamePlaying:: reset(){
    
    board->reset();
    ball->reset();
    bricks->reset();
    
}


GLboolean GamePlaying:: isHitWith(BallDisplay *ball, GameElem *elem){
    
    GLboolean res = false;
    
    if( isIn(elem->getPosY()-elem->getHeight(), elem->getPosY()+elem->getHeight(),
             ball->getPosY()+cosf(ball->getRadian()) * (ball->getHeight() + ELEM_BUMP_SIZE))  &&
                isIn(elem->getPosX()-elem->getWidth(), elem->getPosX()+elem->getWidth(), ball->getPosX()) )
    {
       if(isIn( 0.f, 1.f, cosf(ball->getRadian()) ) ){
           ball->setImpactDirect(0, BOTTOM);
           res = true;
           std::cout<<1<<std::endl;
       } else if( isIn( -1.f, 0.f, cosf(ball->getRadian()))){
           ball->setImpactDirect(0, TOP);
           res = true;
           std::cout<<2<<std::endl;
       }
    }
    
    if( isIn(elem->getPosX()-elem->getWidth(), elem->getPosX()+elem->getWidth(),
             ball->getPosX()+sinf(ball->getRadian()) * (ball->getWidth() + ELEM_BUMP_SIZE)) &&
                isIn(elem->getPosY()-elem->getHeight(), elem->getPosY()+elem->getHeight(), ball->getPosY()) )
    {
       if( isIn( 0.f, 1.f, sinf(ball->getRadian()) ) ){
           ball->setImpactDirect(1, LEFT);
           res = true;
           std::cout<<3<<std::endl;
       }else if( isIn( -1.f, 0.f, sinf(ball->getRadian()) ) ){
           ball->setImpactDirect(1, RIGHT);
           res = true;
           std::cout<<4<<std::endl;
       }
    }
    
    return res;

    
}

GLboolean GamePlaying:: isHitCornerWith(BallDisplay *ball, GameElem *elem){
    
    if(fabsf(ball->getRadian()) == M_PI/4 || fabsf(ball->getRadian()) == M_PI/4*3){
        
        if(
            glm::distance(ball->getPos(),
                glm::vec2(elem->getPosX()-elem->getWidth(), elem->getPosY()-elem->getHeight())) <= ball->getRadian() ||
            glm::distance(ball->getPos(),
                glm::vec2(elem->getPosX()+elem->getWidth(), elem->getPosY()-elem->getHeight())) <= ball->getRadian() ||
            glm::distance(ball->getPos(),
                glm::vec2(elem->getPosX()-elem->getWidth(), elem->getPosY()+elem->getHeight())) <= ball->getRadian() ||
            glm::distance(ball->getPos(),
                         glm::vec2(elem->getPosX()+elem->getWidth(), elem->getPosY()+elem->getHeight())) <= ball->getRadian()
           ){
            ball->setImpactDirect(0, 1);
            ball->setImpactDirect(1, 1);
            return true;
        }
        
    }
    
    return false;
}

GLboolean GamePlaying:: isHitBricks(BallDisplay *ball){
    
    
    return false;
}


GLboolean GamePlaying:: isHitBoard(BallDisplay *ball){
    return (isHitWith(ball, board) || isHitCornerWith(ball, board));
}


GLboolean GamePlaying:: isHitWall(BallDisplay *ball){
    
    GLboolean res = false;
    
    if( (ball->getPosY() + ball->getHeight() + ELEM_BUMP_SIZE > Scenes::winScale)
                                        && isIn( 0.f, 1.f, cosf(ball->getRadian()) ) ){
        ball->setImpactDirect(0, TOP);
        res = true;
    }else if( (ball->getPosY() - ball->getHeight() - ELEM_BUMP_SIZE < -Scenes::winScale)
                                        && isIn( -1.f, 0.f, cosf(ball->getRadian()) ) ){
        //Scenes::status = END;
        ball->setImpactDirect(0, BOTTOM);
        res = true;
    }
    
    if( (ball->getPosX() + ball->getWidth() + ELEM_BUMP_SIZE > 1.f)
                                        && isIn( 0.f, 1.f, sinf(ball->getRadian()) ) ){
        ball->setImpactDirect(1, RIGHT);
        res = true;
    }else if( (ball->getPosX() - ball->getWidth() - ELEM_BUMP_SIZE < -1.f)
                                        && isIn( -1.f, 0.f, sinf(ball->getRadian()) ) ){
        ball->setImpactDirect(1, LEFT);
        res = true;
    }
    
    return res;
}

GLboolean GamePlaying:: isIn(GLfloat small, GLfloat large, GLfloat val){
    
    if(val >= small && val <= large)
        return true;
    return false;
    
}

void GamePlaying:: impact(){
    
    if (Scenes::status == START) {
        
        if(isHitWall(ball) || isHitBoard(ball)){
            ball->rebound();
            std::cout << "impact" << std::endl;
        }
        
        duration = glfwGetTime() - startTime;
        ball->move(duration);
        
    }
    
}


void GamePlaying:: render(){
    
    impact();

    board->render(view);
    ball->render(view);
    bricks->render(view);
    startTime = glfwGetTime();
}

void GamePlaying:: keyboardInput(GLint key, GLint action){
    
    GLfloat dist = ELEM_SHIFT_DIST * board->getVelocity();
    
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
    

    //std::cout<<"Game Status: "<<Scenes::status<<std::endl;
    
}