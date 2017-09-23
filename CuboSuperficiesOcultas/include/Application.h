#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <iostream>
#include "Object3D.h"
#include "Plane.h"
#include <stack>
#include "GLFW\glfw3.h"
#include <vector>

class vec2{
public:
	float	x,
			y;
};

class vect3 {
public:
	float 	v[3];
	/*vect3 operator*(const Mat3& m2);*/
	vect3(int x, int y, int z = 1);
	vect3();

};

class vect4 {
public:
	float v[4];

	vect4(float x, float y, float z);
	vect4();
};

class Mat3 {
public:
	float m[3][3];
	Mat3 operator*(const Mat3  &m1);
	vect3 multi(const vect3& v1, const Mat3& m2);
};

class Mat4 {
public:
	float m[4][4];
	Mat4 operator*(const Mat4 &m);
	vect4 multiP(const vect4 &v1, const Mat4& m2);
};

class Application {
public:

	static const int WIDTH = 512;
	static const int HEIGHT = 512;
	static const int RGB = 3;
	static const int RGBA = 4;

	Application();
	~Application();

	void init();
	void display();
	void reshape(int w, int h);
	void keyboard(int key, int scancode, int action, int mods);
	void update();
	void setUp();
	void swapbuffers();
	void cursor_position(double xpos, double ypos);
	void putPixel(GLubyte *buffer, int x, int y, unsigned char R, unsigned char G, unsigned char B, unsigned char A);
	void putPixel(int x, int y, unsigned char R, unsigned char G, unsigned char B, unsigned char A);
	void draw();
	void linea(int x0, int y0, int x, int y);
	void circle(int r);
	void crearPoligonos(int lados, int radio);
	vect3 puntoMedio(vect3 o, vect3 p);
	void sierpinskyAlgorithm(vect3 a, vect3 b, vect3 c, int subDiv);
	static Mat3 Rotation(const float& angulo);
	static Mat3 Translation(const float &x, const float &y);
	static Mat4 RotationX(const float & angulo);
	static Mat4 RotationY(const float & angulo);
	static Mat4 RotationZ(const float & angulo);
	std::vector<vect4> crearCubo();
	Mat4 LookAtRh(vect3 eye, vect3 target, vect3 up);


	Mat3 mtrx;
	Mat3 RotateMatrix;
	vect3 v1;
	vect3 vecTrans;
	std::stack<glm::mat4> mStack;
	glm::mat4 mProjectionMatrix, mTransform;
	glm::vec3 vEye;
	//std::vector<vect4> vertices1;
	GLFWwindow* window;
	unsigned char Buffers[2][WIDTH*HEIGHT*RGBA];
	void FUNCIONCHINGONA();
	void setColor(int r, int g, int b, int a);
	void moveTo(int x, int y);
	void putPixel(int x, int y);
	void lineTo(int x, int y);
	void clearScreen();

private:	
	GLuint texturesID[2], pboID[2];
	GLuint shaderID;
	GLuint VAO, VBO;
	GLuint sampler;
	GLuint uTransform;
	GLubyte* _screenBuffer;
	int _currentBuffer, 
		_nextBuffer;

	float cx, cy;
	float x = 0;
	float y = 0;
	int	R, G, B, A;
	float angulo = 0, rad = 0;
	Mat3 TransMatrxi;
	Mat3 Final;
	std::vector<vect4> vertices1;
	std::vector<vect4> verticesF;

	glm::vec3 myLightPosition;
	GLuint uMyLightPosition[2];	

	Plane oPlane;
	float fTime;
	void initTextures();
	void processPBO();
	void initPBOs();
	void updatePixels(GLubyte *buffer);
	int _drawMode,
		shader;
	bool moveLight;

	void fakeBuffers();
};


#endif //__APPLICATION_H__