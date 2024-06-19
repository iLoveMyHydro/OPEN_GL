#version 330 core

in vec3 aPosition;
in vec4 aColor;

out vec4 vertexColor;

void main()
{
    gl_Position = vec4(aPosition.x, aPosition.y, aPosition.z, 1.0);
    vertexColor = aColor;
}