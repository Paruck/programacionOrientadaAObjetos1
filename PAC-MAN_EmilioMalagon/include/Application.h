#pragma once

#include <iostream>
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "ShaderFuncs.h"
#include "glm/glm.hpp"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Object.h"
#include <math.h>
#include <stdio.h>
#include "Maze.h"
#include "Enemigo.h"
#include <fstream>
#include <istream>
#include "PacMan.h"

class Application
{
public:
	void setup();
	void update();
	void display();
	void display2();

	void cursor_position(double xpos, double ypos);
	void keyboardInput(int key, int scancode, int actions, int mods);

	void Game(glm::mat4 camera, glm::mat4 transforms);
	void EditMode(glm::mat4 camera, glm::mat4 transforms);

	Application();
	~Application();
private:
	
	bool flagX = false;
	bool flagX1 = false;
	bool flagZ = false;
	bool flagZ1 = false;

	bool editar = false;

	bool Play, Editor, Pausa;
	float posx, posy;

	glm::mat4	camera,
				camera2;
	glm::vec3	eye,
				target,
				eye2,
				target2;

	Enemigo enem,
			enem2,
			enem3,
			enem4;
	PacMan	pacman;


	Maze maze;
	std::vector<Object3D> objArr;
};




