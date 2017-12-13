#include "Object.h"
#include <GL\GLU.h>
#pragma comment(lib, "glu32")
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "OBJ_Loader.h"

Object3D::Object3D() /*: transform(glm::mat4(1.0f)),
escala(glm::mat4(1.0f)),traslacion(glm::mat4(1.0f)),rotacion(glm::mat4(1.0f))*/
{

}

void Object3D::Draw(glm::mat4 transform, float width, float height, glm::vec4 color)
{

	glUseProgram(shader);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glEnableVertexAttribArray(0);

	glUniformMatrix4fv(idTransform, 1, GL_FALSE, glm::value_ptr(transform));
	glUniform4fv(colorID, 1, glm::value_ptr(color));
	if(!indexed)
		glDrawArrays(GL_TRIANGLES, 0, numVertex);
	else
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glDrawElements(GL_TRIANGLES, indexSize, GL_UNSIGNED_INT, (void*)0);
	}
}

void Object3D::Setup(std::vector< GLfloat >& vertex, std::vector<GLuint>* indexes)
{
	numVertex = vertex.size() / 4;
	idTransform = glGetUniformLocation(shader, "transform");
	colorID = glGetUniformLocation(shader, "color");
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	if (indexes != nullptr)
	{
		indexSize = indexes->size();
		glGenBuffers(1, &ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexes->size() * sizeof(GLuint), &indexes->at(0), GL_STATIC_DRAW);
		indexed = true;
	}
	glBufferData(GL_ARRAY_BUFFER, (sizeof(GLfloat) * vertex.size()), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat) * vertex.size(), vertex.data());
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
		
}

void Object3D::CreateShaderProgram(const char * vertexS, const char * fragmentS)
{
	InitializeProgram(shader, vertexS, fragmentS);
}

void Object3D::LoadFromObj(std::string file)
{
	objl::Loader loader;
	std::vector<GLfloat> vertex;
	std::vector<GLuint> indexes;
	objl::Mesh mesh;
	int indexOffset = 0;
	bool result = loader.LoadFile(file);
	if (result)
	{
		for (int k = 0; k < loader.LoadedMeshes.size(); ++k)
		{
			mesh = loader.LoadedMeshes.at(k);
			for (int i = 0; i < mesh.Vertices.size(); ++i)
			{
				vertex.push_back(mesh.Vertices.at(i).Position.X);
				vertex.push_back(mesh.Vertices.at(i).Position.Y);
				vertex.push_back(mesh.Vertices.at(i).Position.Z);
				vertex.push_back(1);
			}
			indexOffset = 0;
			for (int i = 0; i < k; ++i)
				indexOffset += loader.LoadedMeshes.at(0).Vertices.size();
			for (int i = 0; i < mesh.Indices.size(); ++i)
			{
				indexes.push_back(indexOffset + mesh.Indices.at(i));
			}
		}
	}
	Setup(vertex, &indexes);
}

