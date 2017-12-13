
#pragma once
#include "Object.h"
#include "ShaderFuncs.h"
#include <fstream>
#include "Maze.h"
#include <math.h>
#include <vector>
class PacMan
{
public:
	void setupPacman(std::string pacman);
	void setPacman(blockType block, int posx, int posy);
	void drawPacman(glm::mat4 camera,glm::mat4 transforms, Maze& Mz, bool &FLAGX, bool &FLAGX1, bool &FLAGZ, bool &FLAGZ1);
	inline float getPacPosX() {
		return PacmanPos.x;
	}
	inline float getPacPosY() {
		return PacmanPos.y;
	}
	inline glm::vec3 getPacPos() {
		return PacmanPos;
	}

	glm::mat4	Rotacion;

	PacMan();
	~PacMan();

private:
	glm::vec3	PacmanPos;
	float indice = 0;
	Object3D	Pacman;
	glm::mat4	transform;
	glm::mat4	Traslacion,
				Escala;

	bool Power;
};

