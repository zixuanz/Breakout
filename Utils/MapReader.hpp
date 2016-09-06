//
//  MapReader.hpp
//  Breakout
//
//  Created by Zixuan Zhao on 7/8/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#ifndef MapReader_hpp
#define MapReader_hpp

#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>

#include "tinyxml2.h"


using namespace tinyxml2;

class MapReader
{
private:
    XMLDocument map;
    XMLNode *root;
    XMLElement *currStage;
    XMLElement *currNum;
    
    
public:
    struct info {
        GLint stage;
        GLint num;
        const GLchar *stageName;
        const GLchar *numName;
        GLint types;
        GLint row;
        GLint col;
        const GLchar* pattern;
    } currMap;
    
    MapReader(const GLchar * path);
    
    //get stage and num element
    void setCurrMap(GLint stage, GLint num);
    void setCurrStage(GLint stage);
    void setCurrNum(GLint num);
};

#endif /* MapReader_hpp */
