#version 430 core

layout (location = 0) in vec4 vPosition;

uniform mat4 mTransform;
uniform float fTime;


void main()
{

	gl_Position = mTransform * vPosition;
}
	
	
	
	
