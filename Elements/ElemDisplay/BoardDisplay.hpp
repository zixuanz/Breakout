//
//  BoardDisplay.hpp
//  New-Breakout
//
//  Created by Zixuan Zhao on 8/3/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#ifndef BoardDisplay_hpp
#define BoardDisplay_hpp

#include "Board.hpp"
#include "ElemDisplay.hpp"

class BoardDisplay: public Board, public ElemDisplay{

public:
    
    BoardDisplay(const GLchar *vp, const GLchar *fp, const GLchar *gp);
    
    //prepare buffers for sending data
    void prepVertices();
    void prepTextureVert();
    void prepDataArray();
    
    //prepare for render
    void prepRender(const GLchar *vp, const GLchar *fp, const GLchar *gp = NULL);
    
    //render
    void render();
    
    //shift board
    void shift(float dist);

    //keyboard input solution
    void keyboardInput(int key, int action);    //may delete
    
};

#endif /* BoardDisplay_hpp */
