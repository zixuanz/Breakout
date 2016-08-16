#version 330 core
layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 tex;

uniform mat4 backCoor;

out vec2 TexCoor;

void main()
{
    gl_Position = backCoor * vec4(pos, 1.0f);
    TexCoor = tex;

}
