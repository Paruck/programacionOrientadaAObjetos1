#include "Maze.h"
#include <iostream>
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

float time = 0.0f;

void Maze::setup(std::string Paredes, std::string Pellets)
{
	std::string strVertexShader = loadTextFile("Shaders\\vertex.vs");
	std::string strFragmentShader = loadTextFile("Shaders\\fragment.fs");

	Piso.CreateShaderProgram(strVertexShader.c_str(), strFragmentShader.c_str());
	std::vector<GLfloat> planeVertex{
		1.0f, 0.1f, 1.0f, 1.0f,
		-1.0f, 0.1f, -1.0f, 1.0f,
		1.0f, 0.1f, -1.0f, 1.0f,

		-1.0f, 0.1f, 1.0f, 1.0f,
		-1.0f, 0.1f, -1.0f, 1.0f,
		1.0f, 0.1f, 1.0f, 1.0f,
	};
	Piso.Setup(planeVertex, nullptr);

	Pared.CreateShaderProgram(strVertexShader.c_str(), strFragmentShader.c_str());
	std::vector<GLfloat> cubeVertex{
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f,-1.0f,-1.0f, 1.0f,
		1.0f, 1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f, 1.0f,

		1.0f,-1.0f, 1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f, 1.0f,
		1.0f,-1.0f,-1.0f, 1.0f,
		1.0f, 1.0f,-1.0f, 1.0f, // triángulo 2 : comienza
		-1.0f,-1.0f,-1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f, 1.0f,

		-1.0f,-1.0f,-1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f, 1.0f, // triángulo 1 : comienza
		-1.0f,-1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f, 1.0f,

		//Cara Amarilla


		// triángulo 1 : termina
		// triángulo 2 : termina

		1.0f,-1.0f, 1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f, 1.0f,


		-1.0f, 1.0f, 1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f, 1.0f,
		1.0f, 1.0f,-1.0f, 1.0f,
		1.0f,-1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f, 1.0f,

		1.0f,-1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f, 1.0f,

		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f,-1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f, 1.0f,
	};
	
	Pared.Setup(cubeVertex, nullptr);

	Pellet.CreateShaderProgram(strVertexShader.c_str(), strFragmentShader.c_str());
	Pellet.LoadFromObj(Pellets);

	SupperPellet.CreateShaderProgram(strVertexShader.c_str(), strFragmentShader.c_str());
	SupperPellet.LoadFromObj(Pellets);
	
	pisoScale = glm::scale(glm::mat4(1.0f), glm::vec3(Heigth, 0.3f, Width));

	paredScale = glm::scale(glm::mat4(1.0f), glm::vec3(1, 1, 1));

	pelletScale = glm::scale(glm::mat4(1.0f), glm::vec3(0.0001f, 0.0001f, 0.0001f));

	SupelletScale = glm::scale(glm::mat4(1.0f), glm::vec3(0.0002f, 0.0002f, 0.0002f));
}

void Maze::cargarMapa(const std::string nameFile)
{
	std::string getter;
	ArchivoMapa.open(nameFile, std::ios::in);
	std::getline(ArchivoMapa, getter);
	Width = atoi(getter.c_str());
	std::getline(ArchivoMapa, getter);
	Heigth = atoi(getter.c_str());

	for (int i = 0; i < Heigth; ++i) {
		Mapa.push_back(std::vector<char>());
		std::getline(ArchivoMapa, getter);
		for (int j = 0; j < Width; ++j) {
			Mapa.at(i).push_back(getter.at(j));
		}
	}

	ArchivoMapa.close();
}

void Maze::setSquare(int block, int posx, int posy)
{
	this->Mapa.at(posy).at(posx) = block;
}

void Maze::drawMap(glm::mat4 camera, glm::mat4 transforms)
{
	/*pisoRotate = glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(0,0,1));*/
	transform = transforms *  //es WIDTH :P
		camera * /*traslacion * rotacion * */ pisoScale /*traslacion **/;


	Piso.Draw(transform, 920, 640, glm::vec4(0, 0, 0, 0.5f));

	for (int i = 0; i < Heigth; ++i)
	{
		for (int j = 0; j < Width; ++j) {
			paredTrans = glm::translate(glm::mat4(1.0f), glm::vec3((i * 2)-12, 1, (j *2) - 20));
			transform2 = transforms *  //es WIDTH :P
			camera * paredTrans */** rotacion * */ paredScale /*traslacion **/;

			pelletTrans = glm::translate(glm::mat4(1.0f), glm::vec3((i * 2) - 12, 0.3f, (j * 2) - 20));
			transform3 = transforms *  //es WIDTH :P
				camera * pelletTrans */** rotacion * */ pelletScale /*traslacion **/;

			SupelletTrans = glm::translate(glm::mat4(1.0f), glm::vec3((i * 2) - 12, 0.3f, (j * 2) - 20));
			transform4 = transforms *  //es WIDTH :P
				camera * SupelletTrans */** rotacion * */ SupelletScale /*traslacion **/;

			if (Mapa.at(i).at(j) == Muro + 48) {
				Pared.Draw(transform2, 920, 640, glm::vec4(0, 0, 1, 1));
			}
			else if (Mapa.at(i).at(j) == Pellets + 48) {
				Pellet.Draw(transform3, 920, 640, glm::vec4(1, 1, 0, 1));
			}
			else if (Mapa.at(i).at(j) == SupperPellets + 48) {
				SupperPellet.Draw(transform4, 920, 640, glm::vec4(1, 0, 0, 1));
			}
		}
	}

}

void Maze::editMap(glm::mat4 camera, int posy, int posx, bool FLAGX, bool FLAGX1, bool FLAGZ, bool FLAGZ1)
{
	if (FLAGX) {
		setSquare(posy, posx, Camino);
	}
	else if (FLAGX1) {
		setSquare(posy, posx, Camino);
	}
	else if (FLAGX1) {
		setSquare(posy, posx, Camino);
	}
}



void Maze::printMapToConsole()
{
	for (int i = 0; i < Heigth; ++i)
	{
		for (int j = 0; j < Width; ++j)
			std::cout << Mapa.at(i).at(j);
		std::cout << std::endl;
	}
}

Maze::Maze() : pisoTrans(glm::mat4(1.0f)), pisoScale(glm::mat4(1.0f)), pisoRotate(glm::mat4(1.0f))
{

}


Maze::~Maze()
{
}
