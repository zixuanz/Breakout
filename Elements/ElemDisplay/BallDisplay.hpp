//
//  BallDisplay.hpp
//  New-Breakout
//
//  Created by Zixuan Zhao on 8/3/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#ifndef BallDisplay_hpp
#define BallDisplay_hpp

#include "Ball.hpp"
#include "ElemDisplay.hpp"


class BallDisplay: public Ball, public ElemDisplay{
    
public:
    
    BallDisplay(const GLchar *vp, const GLchar *fp, const GLchar *gp);
    
    //prepare buffers for sending data
    void prepVertices();
    void prepTextureVert();
    void prepDataArray();
    
    //prepare for render
    void prepRender(const GLchar *vp, const GLchar *fp, const GLchar *gp = NULL);
    
    //render
    void render();
    
    //shift ball at beginning with board if board is shifting
    void shift(float dist);

    //keyboard input solution
    void keyboardInput(int key, int action);    //may delete

};


#endif /* BallDisplay_hpp */
