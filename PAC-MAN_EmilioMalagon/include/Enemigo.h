#pragma once
#include "Object.h"
#include "ShaderFuncs.h"
#include <fstream>
#include "Maze.h"
#include <math.h>
#include <vector>
#include "PacMan.h"

enum Estado {
	Chase,
	Scatter,
	Frightened
};


class Enemigo : Maze
{
private:


	std::vector<glm::vec2> visitados;

	Estado estadoActual = Scatter;

	Object3D	Fantasma;

	glm::mat4	transform;

	int indice = 0;


	glm::mat4	Traslacion,
				Rotacion,
				Escala;

	glm::vec2 fantasmaPos;

public:

	void setupEnemy(std::string enemy);
	void setEnemy(blockType block, int posx, int posy);
	void drawEnemy(glm::mat4 camera,glm::mat4 transforms, Maze& Mz, PacMan& Pac);
	void EnemAI();

	bool visitado(int y, int x);


	bool Arriba(Maze& Mz,int y, int x);
	bool Abajo(Maze& Mz,int y, int x);
	bool Derecha(Maze& Mz, int y, int x);
	bool Izquierda(Maze& Mz, int y, int x);

	float distance(float x1, float y1, float x2, float y2);

	Enemigo();
	~Enemigo();

};

