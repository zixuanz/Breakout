#version 330 core

in vec2 TexCoor;

uniform sampler2D backTex;

out vec4 color;

void main()
{
    color = texture(backTex, TexCoor);
}