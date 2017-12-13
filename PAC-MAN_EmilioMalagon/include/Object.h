#pragma once
#include <iostream>
#include "GL\glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "glm/glm.hpp"
#include "ShaderFuncs.h"


#define siaut std::cout 
#define nuevalinea std::endl

class Object3D {
public:
	GLuint	vao, //Vertex Array Object
			vbo,
			idTransform,
			ibo, 
			indexSize, 
			colorID; //Vertex Buffer Object

	bool Bandera;
	/*glm::mat4	transform,
				escala,
				traslacion,
				rotacion;*/

	void Draw(glm::mat4 transform, float width, float height, glm::vec4 color);
	int numVertex; //numero de vertices para este objeto
	void Setup(std::vector< GLfloat >& vertex, std::vector<GLuint>* indexes/*, int numVertexP, std::vector< GLfloat >& color, int numColor*/);
	void CreateShaderProgram(const char* vertexS, const char* fragmentS);
	void LoadFromObj(std::string file);
	GLuint shader; //referencia a los shaders
	Object3D();
	std::string name;
	int posx, posy, hash;
	float size;
	bool indexed = false;
				   //Object3D();

};
 