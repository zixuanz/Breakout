//
//  BricksDisplay.hpp
//  New-Breakout
//
//  Created by Zixuan Zhao on 8/6/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#ifndef BricksDisplay_hpp
#define BricksDisplay_hpp

#include "Brick.hpp"
#include "ElemDisplay.hpp"

class BricksDisplay: public Brick, public ElemDisplay{
    
private:
    int row = 0;
    int col = 0;
    glm::vec2 *offset;
    Brick *bricks;
    
    GLuint offsetBuffer;

    
public:
    
    BricksDisplay(const GLchar *vp, const GLchar *fp, const GLchar *gp, int row, int col);
    
    //prepare for bricks
    void setBricks();
    
    //prepare buffers for sending data
    void prepVertices();
    void prepOffset();
    void prepTextureVert();
    void prepDataArray();
    
    //prepare for render
    void prepRender(const GLchar *vp, const GLchar *fp, const GLchar *gp = NULL);
    
    //render
    void render();

};


#endif /* BricksDisplay_hpp */
