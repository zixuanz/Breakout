//
//  MapReader.cpp
//  Breakout
//
//  Created by Zixuan Zhao on 7/8/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#include "MapReader.hpp"

MapReader:: MapReader(const char * path)
{
    XMLError xmlRes = map.LoadFile(path);
    if (xmlRes != XML_SUCCESS)
    {
        std::cout << "ERROR: Failed to read data. Error NO. is "<< xmlRes << std::endl;
        exit(EXIT_FAILURE);
    }
    
    root = map.FirstChild();
}

//get stage and level element
void MapReader:: setCurrMap(int stage, int level)
{
    setCurrStage(stage);
    setCurrLevel(level);
    
    currMap.stage = stage;
    currMap.level = level;
    currMap.stageName = currStage->FirstChildElement("name")->Value();
    currMap.levelName = currLevel->FirstChildElement("name")->Value();
    currMap.types = currStage->IntAttribute("types");
    currMap.row = currLevel->FirstChildElement("bricks")->IntAttribute("row");
    currMap.col = currLevel->FirstChildElement("bricks")->IntAttribute("col");
    currMap.pattern = currLevel->Value();
}

void MapReader:: setCurrStage(int stage)
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

void MapReader:: setCurrLevel(int level)
{
    if (currStage == NULL) {
        std::cout << "ERROR: Failed to read data. Data is wrong. "<< std::endl;
        exit(EXIT_FAILURE);
    }
    
    currLevel = currStage->FirstChildElement("level");
    while (currLevel->IntAttribute("no") != level) {
        currLevel = currLevel->NextSiblingElement("level");
    }
}






























