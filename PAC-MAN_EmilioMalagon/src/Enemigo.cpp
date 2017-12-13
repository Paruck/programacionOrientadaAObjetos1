#include "Enemigo.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"


void Enemigo::setupEnemy(std::string enemy)
{
	std::string strVertexShader = loadTextFile("Shaders\\vertex.vs");
	std::string strFragmentShader = loadTextFile("Shaders\\fragment.fs");
	Fantasma.CreateShaderProgram(strVertexShader.c_str(), strFragmentShader.c_str());
	Fantasma.LoadFromObj(enemy);
	Escala = glm::scale(glm::mat4(1.0f), glm::vec3(0.01f, 0.01f, 0.01f));
}

void Enemigo::setEnemy(blockType block, int posx, int posy)
{
	Mapa.at(posy).at(posx) = block;
}

void Enemigo::drawEnemy(glm::mat4 camera, glm::mat4 transforms, Maze& Mz, PacMan& Pac)
{
	transform = transforms * camera * Traslacion * Escala;

	Fantasma.Draw(transform, 920, 640, glm::vec4(0, 1, 0, 1));

	for (int i = 0; i < 13; ++i)
	{
		for (int j = 0; j < 22; ++j) {
			if (Mz.Mapa.at(i).at(j) == Enemigos + 48) {
				Traslacion = glm::translate(glm::mat4(1.0f), glm::vec3(((i * 2) - 12), 0.5f, ((j * 2) - 20)));
				fantasmaPos.x = j;
				fantasmaPos.y = i;

				if (distance(fantasmaPos.x, fantasmaPos.y - 1, Pac.getPacPosX(), Pac.getPacPosY()) < 
					distance(fantasmaPos.x, fantasmaPos.y + 1, Pac.getPacPosX(), Pac.getPacPosY()) && Arriba(Mz, i, j)) {
					fantasmaPos.y = i - 1;
					fantasmaPos.x = j;

					}

				else if (distance(fantasmaPos.x, fantasmaPos.y - 1, Pac.getPacPosX(), Pac.getPacPosY()) >
					distance(fantasmaPos.x, fantasmaPos.y + 1, Pac.getPacPosX(), Pac.getPacPosY()) && Abajo(Mz, i, j)) {
					fantasmaPos.y = i + 1;
					fantasmaPos.x = j;
			
				}
				else if (distance(fantasmaPos.x - 1, fantasmaPos.y, Pac.getPacPosX(), Pac.getPacPosY()) <
					distance(fantasmaPos.x + 1, fantasmaPos.y, Pac.getPacPosX(), Pac.getPacPosY()) && Derecha(Mz, i, j)) {
					fantasmaPos.y = i;
					fantasmaPos.x = j - 1;
			
				}
				else if (distance(fantasmaPos.x - 1, fantasmaPos.y, Pac.getPacPosX(), Pac.getPacPosY()) >
					distance(fantasmaPos.x + 1, fantasmaPos.y, Pac.getPacPosX(), Pac.getPacPosY()) && Izquierda(Mz, i, j)) {
					fantasmaPos.y = i;
					fantasmaPos.x = j + 1;
			
				}
	

				//else {
				//	Abajo(Mz, i, j);
				//}

				//if (distance(fantasmaPos.x - 1, fantasmaPos.y, pacPosX, pacPosY) <
				//	distance(fantasmaPos.x + 1, fantasmaPos.y, pacPosX, pacPosY)) {
				//	Derecha(Mz, i, j);
				//}
				//else {
				//	Izquierda(Mz, i, j);

				//}
				//else if (Derecha(Mz, i, j)) {
				//	fantasmaPos.y = i;
				//	fantasmaPos.x = j - 1;
				//	break;
				//	//std::cout << "Fantasma pos: " << fantasmaPos.x << ", " << fantasmaPos.y << "\n";
				//	
				//}
				//else if (Izquierda(Mz, i, j)) {
				//	fantasmaPos.y = i;
				//	fantasmaPos.x = j + 1;
				//	break;
				//	//std::cout << "Fantasma pos: " << fantasmaPos.x << ", " << fantasmaPos.y << "\n";
				//	
				//}

				else if (Arriba(Mz, i, j) == false && Abajo(Mz, i, j) == false
					&& Derecha(Mz, i, j) == false && Izquierda(Mz, i, j) == false) {
					visitados.clear();
					break;
				}
			}
		}
	}
}

void Enemigo::EnemAI()
{

}

bool Enemigo::visitado(int y, int x)
{
	for (int i = 0; i < visitados.size(); i++) {
		if (visitados.at(i).y == y && visitados.at(i).x == x) {
			return true;
		}
	}
	return false;
}

bool Enemigo::Arriba(Maze& Mz,int y, int x)
{
	if (Mz.Mapa.at(y - 1).at(x) == Camino + 48 && visitado(y-1 ,x) == false) {
		Mz.Mapa.at(y).at(x) = Camino + 48;
		Mz.Mapa.at(y - 1).at(x) = Enemigos + 48;
		visitados.push_back(fantasmaPos);

		return true;
	}

	else if (Mz.Mapa.at(y - 1).at(x) == Pellets + 48 && visitado(y - 1, x) == false) {
		Mz.Mapa.at(y).at(x) = Pellets + 48;
		Mz.Mapa.at(y - 1).at(x) = Enemigos + 48;
		visitados.push_back(fantasmaPos);
		fantasmaPos.y = y - 1;
		fantasmaPos.x = x;
		return true;
	}
	else if (Mz.Mapa.at(y - 1).at(x) == SupperPellets + 48 && visitado(y - 1, x) == false) {
		Mz.Mapa.at(y).at(x) = SupperPellets + 48;
		Mz.Mapa.at(y - 1).at(x) = Enemigos + 48;
		visitados.push_back(fantasmaPos);
		fantasmaPos.y = y - 1;
		fantasmaPos.x = x;
		return true;
	}
	return false;
}

bool Enemigo::Abajo(Maze& Mz,int y, int x)
{
	if (Mz.Mapa.at(y + 1).at(x) == Camino + 48 && visitado(y + 1, x) == false) {
		Mz.Mapa.at(y).at(x) = Camino + 48;
		Mz.Mapa.at(y + 1).at(x) = Enemigos + 48;
		visitados.push_back(fantasmaPos);
		fantasmaPos.y = y + 1;
		fantasmaPos.x = x;
		return true;
	}

	else if (Mz.Mapa.at(y + 1).at(x) == Pellets + 48 && visitado(y + 1, x) == false) {
		Mz.Mapa.at(y).at(x) = Pellets + 48;
		Mz.Mapa.at(y + 1).at(x) = Enemigos + 48;
		visitados.push_back(fantasmaPos);
		fantasmaPos.y = y + 1;
		fantasmaPos.x = x;
		return true;
	}
	else if (Mz.Mapa.at(y + 1).at(x) == SupperPellets + 48 && visitado(y + 1, x) == false) {
		Mz.Mapa.at(y).at(x) = SupperPellets + 48;
		Mz.Mapa.at(y + 1).at(x) = Enemigos + 48;
		visitados.push_back(fantasmaPos);
		fantasmaPos.y = y + 1;
		fantasmaPos.x = x;
		return true;
	}
	return false;
}

bool Enemigo::Derecha(Maze & Mz, int y, int x)
{
	if (Mz.Mapa.at(y).at(x - 1) == Camino + 48 && visitado(y, x - 1) == false) {
		Mz.Mapa.at(y).at(x) = Camino + 48;
		Mz.Mapa.at(y).at(x - 1) = Enemigos + 48;
		visitados.push_back(fantasmaPos);
		fantasmaPos.y = y;
		fantasmaPos.x = x - 1;
		return true;
	}

	else if (Mz.Mapa.at(y).at(x - 1) == Pellets + 48 && visitado(y, x - 1) == false) {
		Mz.Mapa.at(y).at(x) = Pellets + 48;
		Mz.Mapa.at(y).at(x - 1) = Enemigos + 48;
		visitados.push_back(fantasmaPos);
		fantasmaPos.y = y;
		fantasmaPos.x = x - 1;
		return true;
	}
	else if (Mz.Mapa.at(y).at(x - 1) == SupperPellets + 48 && visitado(y, x - 1) == false) {
		Mz.Mapa.at(y).at(x) = SupperPellets + 48;
		Mz.Mapa.at(y).at(x - 1) = Enemigos + 48;
		visitados.push_back(fantasmaPos);
		fantasmaPos.y = y;
		fantasmaPos.x = x - 1;
		return true;
	}
	return false;
}

bool Enemigo::Izquierda(Maze & Mz, int y, int x)
{
	if (Mz.Mapa.at(y).at(x + 1) == Camino + 48 && visitado(y, x + 1) == false) {
		Mz.Mapa.at(y).at(x) = Camino + 48;
		Mz.Mapa.at(y).at(x + 1) = Enemigos + 48;
		visitados.push_back(fantasmaPos);
		fantasmaPos.y = y;
		fantasmaPos.x = x + 1;
		return true;
	}

	else if (Mz.Mapa.at(y).at(x + 1) == Pellets + 48 && visitado(y, x + 1) == false) {

		Mz.Mapa.at(y).at(x) = Pellets + 48;
		Mz.Mapa.at(y).at(x + 1) = Enemigos + 48;
		visitados.push_back(fantasmaPos);
		fantasmaPos.y = y;
		fantasmaPos.x = x + 1;
		return true;
	}
	else if (Mz.Mapa.at(y).at(x + 1) == SupperPellets + 48 && visitado(y, x + 1) == false) {

		Mz.Mapa.at(y).at(x) = SupperPellets + 48;
		Mz.Mapa.at(y).at(x + 1) = Enemigos + 48;
		visitados.push_back(fantasmaPos);
		fantasmaPos.y = y;
		fantasmaPos.x = x + 1;
		return true;
	}
	return false;
}

float Enemigo::distance(float x1, float y1, float x2, float y2)
{
	float distacia = sqrt((x1 - y1)*(x1 - y1) + (x2 - y2)*(x2 - y2));

	return distacia;
}



//bool Enemigo::Arriba(int y, int x)
//{
//	if (Mp[y - 1][x] != Muro)
//		return true;
//
//	else
//		return false;
//}
//
//bool Enemigo::Abajo(int y, int x)
//{
//	if (Mp[y + 1][x] != Muro)
//		return true;
//
//	else
//		return false;
//}
//
//bool Enemigo::Derecha(int y, int x)
//{
//	if (Mp[y][x + 1] != Muro)
//		return true;
//
//	else
//		return false;
//	return false;
//}
//
//bool Enemigo::Izquierda(int y, int x)
//{
//	if (Mp[y][x - 1] != Muro)
//		return true;
//
//	else
//		return false;
//}
//
//bool Enemigo::Final(int y, int x)
//{
//	return false;
//}

Enemigo::Enemigo()
{

}


Enemigo::~Enemigo()
{
}
