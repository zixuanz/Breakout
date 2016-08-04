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

#include "tinyxml2.h"

using namespace tinyxml2;

class MapReader
{
private:
    XMLDocument map;
    XMLNode *root;
    XMLElement *currStage;
    XMLElement *currLevel;
    
    
public:
    struct info {
        int stage;
        int level;
        const char *stageName;
        const char *levelName;
        int types;
        int row;
        int col;
        const char* pattern;
    } currMap;
    
    MapReader(const char * path);
    
    //get stage and level element
    void setCurrMap(int stage, int level);
    void setCurrStage(int stage);
    void setCurrLevel(int level);
};

#endif /* MapReader_hpp */
