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
    GLint row = 0;
    GLint col = 0;
    const GLchar* pattern;
    
    glm::vec2 *offset;
    Brick **bricks;
    
    GLuint offsetBuffer;
    
    GLint *surroudings;          //indices to record the bricks which is outside of the bricks
    
    void applyPattern();
    void applySurroudings(GLint index, GLboolean pos);
    
protected:
    //prepare buffers for sending data
    void prepVertices();
    void prepOffset();
    void prepTextureVert();
    void prepDataArray();
    void prepModel();
    
    //prepare for render
    void prepRender();

    
public:
    
    BricksDisplay(const GLchar *vp, const GLchar *fp, const GLchar *gp, GLint row, GLint col, const GLchar* pattern);
    
    void reset();
    
    //prepare for bricks
    void setBricks();
    
    void negExisted(GLint index);
    
    //render
    void render(glm::mat4 view);

};


#endif /* BricksDisplay_hpp */
