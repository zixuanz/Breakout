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
    
protected:
    //prepare buffers for sending data
    void prepVertices();
    void prepTextureVert();
    void prepDataArray();
    
    //prepare for render
    void prepRender();
    
public:
    
    BoardDisplay(const GLchar *vp, const GLchar *fp, const GLchar *gp);
    
    void reset();

    void render(glm::mat4 view);                            //render
    
    void shiftBoard(GLfloat bump, GLfloat dist);            //shift board

};

#endif /* BoardDisplay_hpp */
