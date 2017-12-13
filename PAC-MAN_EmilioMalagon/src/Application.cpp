#include "Application.h"

#include "GL\glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "ShaderFuncs.h"
#define PI  3.1516

enum  Estados
{
	Menu = 0,
	Edit = 1,
	Juego = 2,
};

Estados estadoActual;

Application::Application() :	eye(0.0f, 0.0f, 0.0f),
								target(0.0f, 0.0f, 0.0f)
{
}


Application::~Application()
{
}


void Application::update()
{
	switch (estadoActual)
	{
	case Menu:
		Pausa = true;
		Play = false;
		//codigo menu.
		break;
	case Edit:
		Editor = true;
		Play = false;
		break;
	case Juego:
		Play = true;
		Editor = false;
		break;
	}

}




void Application::setup()
{
	maze.cargarMapa("map.txt");	
	maze.setup("Pared.obj", "sphere.obj");
	enem.setupEnemy("Space_Invader.obj");
	enem2.setupEnemy("Space_Invader.obj");
	enem3.setupEnemy("Space_Invader.obj");
	enem4.setupEnemy("Space_Invader.obj");
	pacman.setupPacman("Pacman01.obj");
	eye2 = glm::vec3(-41, 40, 1);
	target2 = glm::vec3(-1,-171,-29);
}


void Application::display()
{

	if (Play == true) {
		eye = glm::vec3((pacman.getPacPosY() * 2) - 12, 0.5f, (pacman.getPacPosX() * 2) - 20);
		target = eye;
		target.z -= 1.0f;

		glm::mat4 transform = glm::perspective(45.0f, 920.0f / 640.0f, 0.1f, 1000.0f);

		camera = glm::lookAt(eye, target, glm::vec3(0.0f, 1.0f, 0.0f));

		Game(camera, transform);

	}
	if (Editor == true) {

		glm::mat4 transform = glm::ortho(0.0f, 50.0f, 50.0f, 0.0f, 0.1f, 1000000.0f);
		camera2 = glm::lookAt(eye2, target2, glm::vec3(0.0f, 1.0f, 0.0f));
		EditMode(camera2, transform);
	}
}

void Application::display2()
{
	glm::mat4 transform = glm::ortho(0.0f, 50.0f, 50.0f, 0.0f, 0.1f, 1000000.0f);
	camera2 = glm::lookAt(eye2, target2, glm::vec3(0.0f, 1.0f, 0.0f));
	EditMode(camera2, transform);
	Game(camera2, transform);
}
void Application::cursor_position(double xpos, double ypos)
{
	//if (xpos >= 0 && xpos <= 410)
	//	camera = glm::rotate(camera, glm::radians((float)xpos / 4), glm::vec3(0.0f, -1.0f, 0.0f));
	//else if (xpos >= 410 && xpos <= 920)
	//	camera = glm::rotate(camera, glm::radians((float)xpos / 4), glm::vec3(0.0f, 1.0f, 0.0f));
}

void Application::keyboardInput(int key, int scancode, int actions, int mods)
{
	flagX = flagX1 = flagZ = flagZ1 = false;
	if (actions == GLFW_PRESS)
	{
		switch (key)
		{

		case GLFW_KEY_1:
			estadoActual = Menu;
			break;
		case GLFW_KEY_2:
			estadoActual = Edit;
			break;
		case GLFW_KEY_3:
			estadoActual = Juego;
			break;

		case GLFW_KEY_E:
			editar = true;
			break;

		case GLFW_KEY_W:
			flagX1 = true;
	/*		target2.y -= 1;*/
			break;

		case GLFW_KEY_S:
			flagX = true;
		/*	target2.y += 1;*/
			break;

		case GLFW_KEY_D:
			flagZ1 = true;
			/*target2.x += 1;*/
			break;

		case GLFW_KEY_A:
		/*	target2.x -= 1;*/
			flagZ = true;
			break;
		}
	}
	else if (actions == GLFW_RELEASE) {
		switch (key)
		{
		case GLFW_KEY_E:
			editar = false;
			break;
		case GLFW_KEY_W:
			flagZ = false;
			break;

		case GLFW_KEY_S:
			flagZ1 = false;
			break;

		case GLFW_KEY_D:
			flagX = false;
			break;
		case GLFW_KEY_A:
			flagX1 = false;
			break;
		}
	}

}

void Application::Game(glm::mat4 camera, glm::mat4 transforms)
{
	maze.drawMap(camera, transforms);
	enem.drawEnemy(camera, transforms, maze, pacman);
	enem2.drawEnemy(camera,transforms, maze, pacman);
	enem3.drawEnemy(camera, transforms, maze, pacman);
	enem4.drawEnemy(camera, transforms, maze, pacman);
	pacman.drawPacman(camera,transforms,maze, flagX, flagX1, flagZ, flagZ1);
}

void Application::EditMode(glm::mat4 camera, glm::mat4 transforms)
{
	
	maze.drawMap(camera, transforms);

	int Posx, Posy;
	int objeto;
	if (editar == true) {

		std::cout << "\nEscibe la posicion en Y, del 0 al 13  : \n";
		std::cin >> Posy;

		std::cout << "Escibe la posicion en X, del 0 al 22 : \n";
		std::cin >> Posx;

		std::cout << "Escribe ahora que elemento quieres colocar en ese espacio. \n";
		std::cout << " 0. para muro.\n1. para camino.\n3. pellets.\n4. SupperPellets.\n5. Enemigos.\n";

		std::cin >> objeto;

		maze.setSquare(objeto + 48,Posx, Posy);
	}
	

	//enem.drawEnemy(camera, maze, pacman);
	//enem2.drawEnemy(camera, maze, pacman);
}

