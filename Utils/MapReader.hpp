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
    XMLElement *currNum;
    
    
public:
    struct info {
        int stage;
        int num;
        const char *stageName;
        const char *numName;
        int types;
        int row;
        int col;
        const char* pattern;
    } currMap;
    
    MapReader(const char * path);
    
    //get stage and num element
    void setCurrMap(int stage, int num);
    void setCurrStage(int stage);
    void setCurrNum(int num);
};

#endif /* MapReader_hpp */
