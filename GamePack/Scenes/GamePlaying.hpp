//
//  GamePlaying.hpp
//  New-Breakout
//
//  Created by Zixuan Zhao on 8/3/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#ifndef GamePlaying_hpp
#define GamePlaying_hpp

#include <cmath>

#include "Scenes.hpp"
#include "MapReader.hpp"
#include "BallDisplay.hpp"
#include "BoardDisplay.hpp"
#include "BricksDisplay.hpp"



//deal with the case when game is playing
class GamePlaying : public Scenes{
    
private:
    GLint stage;        //current stage
    GLint num;          //in current stage, the number of scene
    GLint level;
    
    BallDisplay *ball;
    BoardDisplay *board;
    BricksDisplay *bricks;
    MapReader *map;
    
    GLdouble startTime;
    GLdouble duration;
    
public:
    GamePlaying(GLint stage, GLint num, GLint level);
    
    void reset();
    
    //impact actions
    void isCollision();                 //whether impact with other
    GLboolean isHitWall();              //whether hit the wall
    GLboolean isIn(GLfloat small, GLfloat large, GLfloat val);
    
    void impact();                //draw moves
    
    void render();
    
    //keyboard input solution
    void keyboardInput(GLint key, GLint action);
    
    
};


#endif /* GamePlaying_hpp */
