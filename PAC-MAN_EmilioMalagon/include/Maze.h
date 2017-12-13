#pragma once
#include "glm/glm.hpp"
#include <vector>
#include <string>
#include <fstream>
#include "Object.h"
#include "ShaderFuncs.h"


enum blockType
{
	Muro = 0,
	Camino = 1,
	Pellets = 3,
	SupperPellets = 4,
	Enemigos = 5,
	Personaje = 6
};

class Maze
{
private:

	Object3D	Piso,
				Pared,
				Pellet,
				SupperPellet;

	glm::mat4	transform,
				transform2,
				transform3,
				transform4;

	glm::mat4	pisoTrans,
				pisoScale,
				pisoRotate;

	glm::mat4	paredTrans,
				paredScale,
				paredRotate;

	glm::mat4	pelletTrans,
				pelletScale,
				pelletRotate;

	glm::mat4	SupelletTrans,
				SupelletScale,
				SupelletRotate;

public:

	int Width, Heigth;

	std::fstream ArchivoMapa;

	std::vector <std::vector< char>> Mapa;

	void setup(std::string Paredes, std::string Pellets);
	void cargarMapa(const std::string nameFile);
	void setSquare(int block, int posx, int posy);
	void drawMap(glm::mat4 camera, glm::mat4 transforms);
	void editMap(glm::mat4 camera, int posy, int pox, bool FLAGX, bool FLAGX1, bool FLAGZ, bool FLAGZ1);
	void printMapToConsole();

	Maze();
	~Maze();
};

