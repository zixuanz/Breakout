//
//  MapReader.cpp
//  Breakout
//
//  Created by Zixuan Zhao on 7/8/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#include "MapReader.hpp"

MapReader:: MapReader(const GLchar * path)
{
    XMLError xmlRes = map.LoadFile(path);
    if (xmlRes != XML_SUCCESS)
    {
        std::cout << "ERROR: Failed to read data. Error NO. is "<< xmlRes << std::endl;
        exit(EXIT_FAILURE);
    }
    
    root = map.FirstChild();
}

//get stage and num element
void MapReader:: setCurrMap(GLint stage, GLint num)
{
    setCurrStage(stage);
    setCurrNum(num);
    
    currMap.stage = stage;
    currMap.num = num;
    currMap.stageName = currStage->FirstChildElement("name")->Value();
    currMap.numName = currNum->FirstChildElement("name")->Value();
    currMap.types = currStage->IntAttribute("types");
    currMap.row = currNum->FirstChildElement("bricks")->IntAttribute("row");
    currMap.col = currNum->FirstChildElement("bricks")->IntAttribute("col");
    currMap.pattern = currNum->Value();
}

void MapReader:: setCurrStage(GLint stage)
{
    if (root == nullptr) {
        std::cout << "ERROR: Failed to read data. Data is wrong. "<< std::endl;
        exit(EXIT_FAILURE);
    }
    
    currStage = root->FirstChildElement("stage");
    
    while(currStage->IntAttribute("no") != stage)
    {
        currStage = currStage->NextSiblingElement("stage");
    }
}

void MapReader:: setCurrNum(GLint num)
{
    if (currStage == NULL) {
        std::cout << "ERROR: Failed to read data. Data is wrong. "<< std::endl;
        exit(EXIT_FAILURE);
    }
    
    currNum = currStage->FirstChildElement("num");
    while (currNum->IntAttribute("no") != num) {
        currNum = currNum->NextSiblingElement("num");
    }
}






























