//

//  HelloCube

//

//  Created by Pedro  Cervantes Pintor on 11/Oct/14.

//
#define GLM_FORCE_RADIANS
#include "Application.h"
#include <iostream>
#include <vector>

#include "GL\glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GLFW\glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "ShaderFuncs.h"
#include "Plane.h"



Application::Application() : vEye(0.0f, 50.0f, 100.0f),
							_drawMode (0),
							shader(0),
							_currentBuffer(0),
							_nextBuffer(1)
							
{
}

Application::~Application()
{
	glDeleteTextures(2, texturesID);
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(2, pboID);
}

void Application::FUNCIONCHINGONA()
{

	//INDICES 1 Primer cuadrado FRONT------------------------------
	moveTo(verticesF.at(1).v[0], verticesF.at(1).v[1]); // b
	lineTo(verticesF.at(3).v[0], verticesF.at(3).v[1]);// d
	moveTo(verticesF.at(3).v[0], verticesF.at(3).v[1]); //d
	lineTo(verticesF.at(0).v[0], verticesF.at(0).v[1]);//a
	moveTo(verticesF.at(0).v[0], verticesF.at(0).v[1]);//a
	lineTo(verticesF.at(1).v[0], verticesF.at(1).v[1]);//b
	//END DE INDICES 1

	moveTo(verticesF.at(1).v[0], verticesF.at(1).v[1]); // b
	lineTo(verticesF.at(2).v[0], verticesF.at(2).v[1]);//c
	moveTo(verticesF.at(2).v[0], verticesF.at(2).v[1]);//c
	lineTo(verticesF.at(3).v[0], verticesF.at(3).v[1]);//d
	moveTo(verticesF.at(3).v[0], verticesF.at(3).v[1]);//d
	lineTo(verticesF.at(1).v[0], verticesF.at(1).v[1]);//b
	 //Fin de FRONT


	 //INDICES 2 Segundo cuadrado FRONT------------------------------
	moveTo(verticesF.at(5).v[0], verticesF.at(5).v[1]); // f
	lineTo(verticesF.at(0).v[0], verticesF.at(0).v[1]);// a
	moveTo(verticesF.at(0).v[0], verticesF.at(0).v[1]); //a
	lineTo(verticesF.at(4).v[0], verticesF.at(4).v[1]);//e
	moveTo(verticesF.at(4).v[0], verticesF.at(4).v[1]);//e
	lineTo(verticesF.at(5).v[0], verticesF.at(5).v[1]);//f
    //END DE INDICES 2

	moveTo(verticesF.at(5).v[0], verticesF.at(5).v[1]); // f
	lineTo(verticesF.at(1).v[0], verticesF.at(1).v[1]);//b
	moveTo(verticesF.at(1).v[0], verticesF.at(1).v[1]);//b
	lineTo(verticesF.at(0).v[0], verticesF.at(0).v[1]);//a
	moveTo(verticesF.at(0).v[0], verticesF.at(0).v[1]);//a
	lineTo(verticesF.at(5).v[0], verticesF.at(5).v[1]);//f
	 //Fin de BOT

	 //INDICES 3 Tercer cuadrado Left------------------------------
	moveTo(verticesF.at(0).v[0], verticesF.at(0).v[1]); // a
	lineTo(verticesF.at(5).v[0], verticesF.at(5).v[1]);// k
	moveTo(verticesF.at(5).v[0], verticesF.at(5).v[1]); //k
	lineTo(verticesF.at(4).v[0], verticesF.at(4).v[1]);//l
	moveTo(verticesF.at(4).v[0], verticesF.at(4).v[1]);//l
	lineTo(verticesF.at(0).v[0], verticesF.at(0).v[1]);//a
	
	//END DE INDICES 3

	moveTo(verticesF.at(0).v[0], verticesF.at(0).v[1]); // a
	lineTo(verticesF.at(3).v[0], verticesF.at(3).v[1]);//d
	moveTo(verticesF.at(3).v[0], verticesF.at(3).v[1]);//d
	lineTo(verticesF.at(5).v[0], verticesF.at(5).v[1]);//k
	moveTo(verticesF.at(5).v[0], verticesF.at(5).v[1]);//k
	lineTo(verticesF.at(0).v[0], verticesF.at(0).v[1]);//a
	 //Fin de Left


	 //INDICES 4 Cuarto cuadrado Right------------------------------
	moveTo(verticesF.at(5).v[0], verticesF.at(5).v[1]); // j
	lineTo(verticesF.at(2).v[0], verticesF.at(2).v[1]);// c
	moveTo(verticesF.at(2).v[0], verticesF.at(2).v[1]); //c
	lineTo(verticesF.at(1).v[0], verticesF.at(1).v[1]);//b
	moveTo(verticesF.at(1).v[0], verticesF.at(1).v[1]);//b
	lineTo(verticesF.at(5).v[0], verticesF.at(5).v[1]);//j
													   
    //END DE INDICES 4

	moveTo(verticesF.at(5).v[0], verticesF.at(5).v[1]); // j
	lineTo(verticesF.at(6).v[0], verticesF.at(6).v[1]);//i
	moveTo(verticesF.at(6).v[0], verticesF.at(6).v[1]);//i
	lineTo(verticesF.at(2).v[0], verticesF.at(2).v[1]);//c
	moveTo(verticesF.at(2).v[0], verticesF.at(2).v[1]);//c
	lineTo(verticesF.at(5).v[0], verticesF.at(5).v[1]);//j
	//Fin de Right


	//INDICES 5 Cuarto cuadrado Top------------------------------
	moveTo(verticesF.at(2).v[0], verticesF.at(2).v[1]); // c
	lineTo(verticesF.at(7).v[0], verticesF.at(7).v[1]);// h
	moveTo(verticesF.at(7).v[0], verticesF.at(7).v[1]); //h
	lineTo(verticesF.at(3).v[0], verticesF.at(3).v[1]);//d
	moveTo(verticesF.at(3).v[0], verticesF.at(3).v[1]);//d
	lineTo(verticesF.at(2).v[0], verticesF.at(2).v[1]);//c

	 //END DE INDICES 5

	moveTo(verticesF.at(2).v[0], verticesF.at(2).v[1]); // c
	lineTo(verticesF.at(6).v[0], verticesF.at(6).v[1]);//g
	moveTo(verticesF.at(6).v[0], verticesF.at(6).v[1]);//g
	lineTo(verticesF.at(7).v[0], verticesF.at(7).v[1]);//h
	moveTo(verticesF.at(7).v[0], verticesF.at(7).v[1]);//h
	lineTo(verticesF.at(2).v[0], verticesF.at(2).v[1]);//c

	//Fin de Top


	//INDICES 6 Cuarto cuadrado Back------------------------------
	moveTo(verticesF.at(6).v[0], verticesF.at(6).v[1]); // g
	lineTo(verticesF.at(4).v[0], verticesF.at(4).v[1]);// m
	moveTo(verticesF.at(4).v[0], verticesF.at(4).v[1]); //m
	lineTo(verticesF.at(7).v[0], verticesF.at(3).v[1]);//h
	moveTo(verticesF.at(7).v[0], verticesF.at(3).v[1]);//h
	lineTo(verticesF.at(6).v[0], verticesF.at(6).v[1]);//g

     //END DE INDICES 6

	moveTo(verticesF.at(6).v[0], verticesF.at(6).v[1]); // g
	lineTo(verticesF.at(5).v[0], verticesF.at(5).v[1]);//n
	moveTo(verticesF.at(5).v[0], verticesF.at(5).v[1]);//n
	lineTo(verticesF.at(4).v[0], verticesF.at(4).v[1]);//m
	moveTo(verticesF.at(4).v[0], verticesF.at(4).v[1]);//m
	lineTo(verticesF.at(6).v[0], verticesF.at(6).v[1]);//g

	 //Fin de Back


}

void Application::setColor(int r, int g, int b, int a)
{
	R = r;
	G = g;
	B = b;
	A = a;
}

void Application::moveTo(int x, int y)
{
	cx = x;
	cy = y;
}

void Application::putPixel(int x, int y)
{
	putPixel(x, y, R, G, B, A);
}

void Application::lineTo(int x, int y)
{
	linea(cx, cy, x, y);

}

void Application::clearScreen()
{
	for (int i = 0; i < WIDTH * HEIGHT * RGBA; i++)
		_screenBuffer[i] = 0;
}

vect4 Application::Cross(const vect4 & v1, const vect4 & v2)
{
	vect4 vectorResultante;
	vectorResultante.v[0] = v1.v[1] * v2.v[2] - v1.v[2] * v2.v[0];
	vectorResultante.v[1] = (v1.v[0] * v2.v[2] - v1.v[2] * v2.v[2]) * -1;
	vectorResultante.v[2] = v1.v[0] * v2.v[1] - v2.v[0] * v1.v[1];

	return vectorResultante;
}

void Application::initTextures()
{
	int img_width, img_height;
	int channels;
	
	glGenTextures(2, texturesID);
	//Textura 0
	glBindTexture(GL_TEXTURE_2D, texturesID[0]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, WIDTH, HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, Buffers[0]);
	//glTexStorage2D(GL_TEXTURE_2D, 0, GL_RGB, img_width, img_height);
	//glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, img_width, img_height, GL_RGB, GL_UNSIGNED_BYTE, img);

	//Sin promediar
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	//Textura 1
	glBindTexture(GL_TEXTURE_2D, texturesID[1]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, WIDTH, HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, Buffers[1]);
	//glTexStorage2D(GL_TEXTURE_2D, 0, GL_RGB, img_width, img_height);
	//glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, img_width, img_height, GL_RGB, GL_UNSIGNED_BYTE, img);

	//Sin promediar
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	
	glBindTexture(GL_TEXTURE_2D, 0);
	

}

void Application::initPBOs()
{
	// create 2 pixel buffer objects, you need to delete them when program exits.
	// glBufferData with NULL pointer reserves only memory space.
	glGenBuffers(2, pboID);
	glBindBuffer(GL_PIXEL_UNPACK_BUFFER, pboID[0]);
	glBufferData(GL_PIXEL_UNPACK_BUFFER, WIDTH * HEIGHT * RGBA, 0, GL_STREAM_DRAW);
	glBindBuffer(GL_PIXEL_UNPACK_BUFFER, pboID[1]);
	glBufferData(GL_PIXEL_UNPACK_BUFFER, WIDTH * HEIGHT * RGBA, 0, GL_STREAM_DRAW);
	glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);
}

void Application::init()
{
	fakeBuffers();
	initTextures();
	initPBOs();
	GLfloat vertices[]
	{
		//triangulo 0


		-1.0f, -1.0f, 0.0f, 1.0f,

		1.0f, -1.0f, 0.0f, 1.0f,

		-1.0f, 1.0f, 0.0f, 1.0f,

		//triangulo2
		//-1.0f, 1.0f, 0.0f, 1.0f,

		//1.0f, -1.0f, 0.0f, 1.0f,

		1.0f, 1.0f, 0.0f, 1.0f,
	};
	GLfloat texCoords[] 
	{
		0.0f, 1.0f, 0.0f, 0.0f,  //TEX
		1.0f, 1.0f, 0.0f, 0.0f,//TEX
		0.0f, 0.0f, 0.0f, 0.0f, //TEX

		1.0f, 0.0f, 0.0f, 0.0f//TEX

		//0.0f, 1.0f, 0.0f, 0.0f,//TEX
		//1.0f, 0.0f, 0.0f, 0.0f,//TEX
	};

	vEye = glm::vec3(0.0f, 50.0f, 50.0f);

	std::string sVertex, sFragment;
	sVertex = loadTextFile("shaders/passThru.v");
	sFragment = loadTextFile("shaders/passThru.f");
	InitializeProgram(shaderID, sVertex, sFragment);
	
	uTransform = glGetUniformLocation(shaderID, "mTransform");
	sampler = glGetUniformLocation(shaderID, "theTexture");

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) + sizeof(texCoords), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(texCoords), texCoords);
	
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)(sizeof(vertices)));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	setUp();
}


void Application::display()
{
	processPBO();

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glUseProgram(shaderID);

	mProjectionMatrix = glm::mat4(1.0f);// glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f);
	mTransform = glm::mat4(1.0f) * mProjectionMatrix;

	glUniformMatrix4fv(uTransform, 1, GL_FALSE, glm::value_ptr(mTransform));

	//pasamos parametros de textura
	glBindTexture(GL_TEXTURE_2D, texturesID[_currentBuffer]);
	glUniform1i(sampler, _currentBuffer);
	glActiveTexture(_currentBuffer==0? GL_TEXTURE0 : GL_TEXTURE1);
	//glActiveTexture(GL_TEXTURE0);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	swapbuffers();
}

void Application::processPBO()
{
	// bind the texture and PBO
	glBindTexture(GL_TEXTURE_2D, texturesID[_currentBuffer]); //solo se necesita una textura
	glBindBuffer(GL_PIXEL_UNPACK_BUFFER, pboID[_currentBuffer]);

	// copy pixels from PBO to texture object
	// Use offset instead of pointer.
	glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, WIDTH, HEIGHT, GL_RGBA, GL_UNSIGNED_BYTE, 0);


	// bind PBO to update texture source
	glBindBuffer(GL_PIXEL_UNPACK_BUFFER, pboID[_nextBuffer]);

	// Note that glMapBufferARB() causes sync issue.
	// If GPU is working with this buffer, glMapBufferARB() will wait(stall)
	// until GPU to finish its job. To avoid waiting (idle), you can call
	// first glBufferDataARB() with NULL pointer before glMapBufferARB().
	// If you do that, the previous data in PBO will be discarded and
	// glMapBufferARB() returns a new allocated pointer immediately
	// even if GPU is still working with the previous data.
	glBufferData(GL_PIXEL_UNPACK_BUFFER, WIDTH * HEIGHT * RGBA, 0, GL_STREAM_DRAW);

	// map the buffer object into client's memory

	_screenBuffer = (GLubyte*)glMapBuffer(GL_PIXEL_UNPACK_BUFFER, GL_READ_WRITE);
	if (_screenBuffer)
	{
		// update data directly on the mapped buffer
		//updatePixels(ptr);
		draw();
		glUnmapBuffer(GL_PIXEL_UNPACK_BUFFER); // release the mapped buffer
	}

	// it is good idea to release PBOs with ID 0 after use.
	// Once bound with 0, all pixel operations are back to normal ways.
	glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);
}

//Called whenever the window is resized. The new window size is given, in pixels.
//This is an opportunity to call glViewport or glScissor to keep up with the change in size.
void Application::reshape(int w, int h)
{
	//glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	//mProjectionMatrix = glm::perspective(45.0f, (float)w / (float)h, 1.0f, 10000.f);
}


void Application::keyboard(int key, int scancode, int action, int mods)
{
	const float inc = 1.0;
	switch (action)
	{		
	case GLFW_PRESS:
		switch (key)
		{
		
		case GLFW_KEY_ESCAPE: glfwSetWindowShouldClose(window, GL_TRUE); break;		
		case GLFW_KEY_T: _currentBuffer = 1 - _currentBuffer; break;
		case GLFW_KEY_P:
			_drawMode = ++_drawMode % 3;
			switch (_drawMode)
			{
				case 0: glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); break;
				case 1: glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); break;
				case 2:	glPolygonMode(GL_FRONT, GL_FILL);
						glPolygonMode(GL_BACK, GL_LINE);
						break;
			}
		case GLFW_KEY_LEFT:
			mtrx.m[0][2] -= 3;
			break;
		case GLFW_KEY_RIGHT:
			mtrx.m[0][2] += 3;
			break;
		case GLFW_KEY_UP:
			mtrx.m[1][2] -= 3;
			break;
		case GLFW_KEY_DOWN:
			mtrx.m[1][2] += 3;
			break;
		}
		//break;
		
	} //switch (action)
}

//void Application::setUp()
//{
//}





void Application::cursor_position(double xpos, double ypos)
{
	int width, heigth;

	glfwGetWindowSize(window, &width, &heigth);
}


void Application::fakeBuffers()
{
	for (int i = 0; i < WIDTH*HEIGHT*RGBA; i+=4)
	{
		Buffers[1][i] = 255;
		Buffers[1][i + 1] = 0;
		Buffers[1][i + 2] = 0;
		Buffers[1][i + 3] = 255;

		Buffers[0][i] = 0;
		Buffers[0][i + 1] = 255;
		Buffers[0][i + 2] = 0;
		Buffers[0][i + 3] = 255;
	}
}

void Application::swapbuffers()
{
	_currentBuffer = 1 - _currentBuffer;
	_nextBuffer = 1 - _currentBuffer;
}


void Application::putPixel(GLubyte *buffer, int x, int y, unsigned char R, unsigned char G, unsigned char B, unsigned char A)
{
	int offset = (x + (y * WIDTH)) * RGBA;
	if (offset < 0 || offset >= (WIDTH * HEIGHT *RGBA))
		return;

	buffer[offset]	 = R;
	buffer[offset + 1] =  G;
	buffer[offset + 2] =  B;
	buffer[offset + 3] =  A;

}

void Application::putPixel(int x, int y, unsigned char R, unsigned char G, unsigned char B, unsigned char A)
{
	putPixel(_screenBuffer, x, y, R, G, B, A);
}


///////////////////////////////////////////////////////////////////////
/*
00 01 02
10 11 12
20 21 22
*/

Mat3 Mat3:: operator*(const Mat3 &m1)
{
	Mat3 matFinal;
	matFinal.m[0][0] = this->m[0][0] * m1.m[0][0] + (this->m[0][1] * m1.m[1][0] + (this->m[0][2] * m1.m[2][0]));
	matFinal.m[0][1] = this->m[0][0] * m1.m[0][1] + (this->m[0][1] * m1.m[1][1] + (this->m[0][2] * m1.m[2][1]));
	matFinal.m[0][2] = this->m[0][0] * m1.m[0][2] + (this->m[0][1] * m1.m[1][2] + (this->m[0][2] * m1.m[2][2]));

	matFinal.m[1][0] = this->m[1][0] * m1.m[0][0] + (this->m[1][1] * m1.m[1][0] + (this->m[1][2] * m1.m[2][0]));
	matFinal.m[1][1] = this->m[1][0] * m1.m[0][1] + (this->m[1][1] * m1.m[1][1] + (this->m[1][2] * m1.m[2][1]));
	matFinal.m[1][2] = this->m[1][0] * m1.m[0][2] + (this->m[1][1] * m1.m[1][2] + (this->m[1][2] * m1.m[2][2]));

	matFinal.m[2][0] = this->m[2][0] * m1.m[0][0] + (this->m[2][1] * m1.m[1][0] + (this->m[2][2] * m1.m[2][0]));
	matFinal.m[2][1] = this->m[2][0] * m1.m[0][1] + (this->m[2][1] * m1.m[1][1] + (this->m[2][2] * m1.m[2][1]));
	matFinal.m[2][2] = this->m[2][0] * m1.m[0][2] + (this->m[2][1] * m1.m[1][2] + (this->m[2][2] * m1.m[2][2]));

	return matFinal;
}

vect3 Mat3::multi(const vect3 & v1, const Mat3 & m2)
{
	vect3 vectorFinal;
	vectorFinal.v[0] = v1.v[0] * m2.m[0][0] + (v1.v[1] * m2.m[0][1] + (v1.v[2] * m2.m[0][2]));
	vectorFinal.v[1] = v1.v[0] * m2.m[1][0] + (v1.v[1] * m2.m[1][1] + (v1.v[2] * m2.m[1][2]));
	vectorFinal.v[2] = v1.v[0] * m2.m[2][0] + (v1.v[1] * m2.m[2][1] + (v1.v[2] * m2.m[2][2]));
	return vectorFinal;
}


//vect3 vect3:: operator*(const Mat3 &m2)
//{
//	vect3 vectorFinal;
//	vectorFinal.v[0] = this->v[0] * m2.m[0][0] + (this->v[1] * m2.m[0][1] + (this->v[2] * m2.m[0][2]));
//	vectorFinal.v[1] = this->v[0] * m2.m[1][0] + (this->v[1] * m2.m[1][1] + (this->v[2] * m2.m[1][2]));
//	vectorFinal.v[2] = this->v[0] * m2.m[2][0] + (this->v[1] * m2.m[2][1] + (this->v[2] * m2.m[2][2]));
//
//	return vectorFinal;
//}

vect3::vect3(int x, int y, int z)
{
	v[0] = x;
	v[1] = y;
	v[2] = z;
}

vect3::vect3()
{

}


vect4::vect4(float x, float y, float z)
{
	v[0] = x;
	v[1] = y;
	v[2] = z;
	v[3] = 1;
}

vect4::vect4()
{
}

Mat4 Mat4::operator*(const Mat4 & m1)
{
	Mat4 matFinal;
	matFinal.m[0][0] = this->m[0][0] * m1.m[0][0] + (this->m[0][1] * m1.m[1][0] + (this->m[0][2] * m1.m[2][0] + (this->m[0][3] * m1.m[3][0])));
	matFinal.m[0][1] = this->m[0][0] * m1.m[0][1] + (this->m[0][1] * m1.m[1][1] + (this->m[0][2] * m1.m[2][1] + (this->m[0][3] * m1.m[3][1])));
	matFinal.m[0][2] = this->m[0][0] * m1.m[0][2] + (this->m[0][1] * m1.m[1][2] + (this->m[0][2] * m1.m[2][2] + (this->m[0][3] * m1.m[3][2])));
	matFinal.m[0][3] = this->m[0][0] * m1.m[0][3] + (this->m[0][1] * m1.m[1][3] + (this->m[0][2] * m1.m[2][3] + (this->m[0][3] * m1.m[3][3])));

	matFinal.m[1][0] = this->m[1][0] * m1.m[0][0] + (this->m[1][1] * m1.m[1][0] + (this->m[1][2] * m1.m[2][0] + (this->m[1][3] * m1.m[3][0])));
	matFinal.m[1][1] = this->m[1][0] * m1.m[0][1] + (this->m[1][1] * m1.m[1][1] + (this->m[1][2] * m1.m[2][1] + (this->m[1][3] * m1.m[3][1])));
	matFinal.m[1][2] = this->m[1][0] * m1.m[0][2] + (this->m[1][1] * m1.m[1][2] + (this->m[1][2] * m1.m[2][2] + (this->m[1][3] * m1.m[3][2])));
	matFinal.m[1][3] = this->m[1][0] * m1.m[0][3] + (this->m[1][1] * m1.m[1][3] + (this->m[1][2] * m1.m[2][3] + (this->m[1][3] * m1.m[3][3])));

	matFinal.m[2][0] = this->m[2][0] * m1.m[0][0] + (this->m[2][1] * m1.m[1][0] + (this->m[2][2] * m1.m[2][0] + (this->m[2][3] * m1.m[3][0])));
	matFinal.m[2][1] = this->m[2][0] * m1.m[0][1] + (this->m[2][1] * m1.m[1][1] + (this->m[2][2] * m1.m[2][1] + (this->m[2][3] * m1.m[3][1])));
	matFinal.m[2][2] = this->m[2][0] * m1.m[0][2] + (this->m[2][1] * m1.m[1][2] + (this->m[2][2] * m1.m[2][2] + (this->m[2][3] * m1.m[3][2])));
	matFinal.m[2][3] = this->m[2][0] * m1.m[0][3] + (this->m[2][1] * m1.m[1][3] + (this->m[2][2] * m1.m[2][3] + (this->m[2][3] * m1.m[3][3])));

	matFinal.m[3][0] = this->m[3][0] * m1.m[0][0] + (this->m[3][1] * m1.m[1][0] + (this->m[3][2] * m1.m[2][0] + (this->m[3][3] * m1.m[3][0])));
	matFinal.m[3][1] = this->m[3][0] * m1.m[0][1] + (this->m[3][1] * m1.m[1][1] + (this->m[3][2] * m1.m[2][1] + (this->m[3][3] * m1.m[3][1])));
	matFinal.m[3][2] = this->m[3][0] * m1.m[0][2] + (this->m[3][1] * m1.m[1][2] + (this->m[3][2] * m1.m[2][2] + (this->m[3][3] * m1.m[3][2])));
	matFinal.m[3][3] = this->m[3][0] * m1.m[0][3] + (this->m[3][1] * m1.m[1][3] + (this->m[3][2] * m1.m[2][3] + (this->m[3][3] * m1.m[3][3])));

	return matFinal;
}

vect4 Mat4::multiP(const vect4 & v1, const Mat4 & m2)
{
	vect4 vectorFinal;
	vectorFinal.v[0] = v1.v[0] * m2.m[0][0] + (v1.v[1] * m2.m[0][1] + (v1.v[2] * m2.m[0][2] + (v1.v[3] * m2.m[0][3])));
	vectorFinal.v[1] = v1.v[0] * m2.m[1][0] + (v1.v[1] * m2.m[1][1] + (v1.v[2] * m2.m[1][2] + (v1.v[3] * m2.m[1][3])));
	vectorFinal.v[2] = v1.v[0] * m2.m[2][0] + (v1.v[1] * m2.m[2][1] + (v1.v[2] * m2.m[2][2] + (v1.v[3] * m2.m[2][3])));
	vectorFinal.v[3] = v1.v[0] * m2.m[3][0] + (v1.v[1] * m2.m[3][1] + (v1.v[2] * m2.m[3][2] + (v1.v[3] * m2.m[3][3])));
	return vectorFinal;
}
