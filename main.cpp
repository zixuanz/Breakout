//
//  main.cpp
//  New-Breakout
//
//  Created by Zixuan Zhao on 8/2/16.
//  Copyright © 2016 Zixuan Zhao. All rights reserved.
//

#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// GLM Mathemtics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "GamePlaying.hpp"

const char *MAIN_WINDOW_TITLE = "Breakout";
const GLfloat MAIN_WINDOW_WIDTH = 480;
const GLfloat MAIN_WINDOW_HEIGHT = 640;

GLFWwindow *window;
GamePlaying *game;

//function signitures
static void error_callback(int error, const char* description);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);


int main(int argc, const char * argv[]) {
    
    //initilize and setup GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    
    glfwSetErrorCallback(error_callback);
    
    if (!glfwInit())
    {
        std::cout << "Failed to initialize GLFW" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    //create window
    window = glfwCreateWindow(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT, MAIN_WINDOW_TITLE, NULL, NULL);
    if (!window)
    {
        std::cout << "Failed to initialize window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    
    //initialize and setup GLEW. Has to be
    glewExperimental = GL_TRUE;
    GLenum initGlew = glewInit();
    if (initGlew != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    //events callback set
    glfwSetKeyCallback(window, key_callback);
    //glfwSetCursorPosCallback(window, cursor_position_callback);
    
    Scenes::setWinSize(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT);
    game = new GamePlaying(1, 1, 1);
    
    glViewport(0, 0, MAIN_WINDOW_WIDTH, -MAIN_WINDOW_HEIGHT);
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();                               //check events
        
        glDepthFunc(GL_LESS);
        glClearColor(0.f, 0.f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        game->render();
        
        glfwSwapBuffers(window);
        
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();                            //free resource
    
    
    exit(EXIT_SUCCESS);
}



static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    //exit game
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    
    game->keyboardInput(key, action);
}

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
    
}
