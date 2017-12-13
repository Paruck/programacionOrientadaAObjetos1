#include "PacMan.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"


void PacMan::setupPacman(std::string pacman)
{
	std::string strVertexShader = loadTextFile("Shaders\\vertex.vs");
	std::string strFragmentShader = loadTextFile("Shaders\\fragment.fs");
	Pacman.CreateShaderProgram(strVertexShader.c_str(), strFragmentShader.c_str());
	Pacman.LoadFromObj(pacman);
	Escala = glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f));

}

void PacMan::setPacman(blockType block, int posx, int posy)
{

}

void PacMan::drawPacman(glm::mat4 camera, glm::mat4 transforms, Maze& Mz, bool &FLAGX, bool &FLAGX1, bool &FLAGZ, bool &FLAGZ1)
{

	transform = transforms * camera * Rotacion *Traslacion* Escala;
	Pacman.Draw(transform, 920, 640, glm::vec4(1, 1, 0, 1));

	for (int i = 0; i < 13; ++i)
	{
		for (int j = 0; j < 22; ++j) {
			if (Mz.Mapa.at(i).at(j) == Personaje + 48) {
				PacmanPos.x = j;
				PacmanPos.y = i;
				Traslacion = glm::translate(glm::mat4(1.0f), glm::vec3(((i * 2) - 12), 0.5f, ((j * 2) - 20)));
					if ((Mz.Mapa.at(i).at((j + 1)) == Pellets + 48 && FLAGZ1 == true) || (Mz.Mapa.at(i).at((j + 1)) == Camino + 48 && FLAGZ1 == true)) {
						Mz.setSquare('0' + Camino, j, i);
						Mz.setSquare('0' + Personaje, j + 1, i);
						/*Traslacion = glm::translate(glm::mat4(1.0f), glm::vec3(((i * 2) - 12), 0.5f, ((j * 2) - 20) + 1.0f));*/

						//Traslacion += glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 1));
						PacmanPos.x = j + 1;
			
						FLAGX = FLAGX1 = FLAGZ = FLAGZ1 = false;
					}
					else if(Mz.Mapa.at(i).at((j + 1)) == SupperPellets + 48 && FLAGZ1 == true){
						Mz.setSquare('0' + Camino, j, i);
						Mz.setSquare('0' + Personaje, j + 1, i);
						/*Traslacion = glm::translate(glm::mat4(1.0f), glm::vec3(((i * 2) - 12), 0.5f, ((j * 2) - 20) + 1.0f));*/

						//Traslacion += glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 1));
						PacmanPos.x = j + 1;

						FLAGX = FLAGX1 = FLAGZ = FLAGZ1 = false;
						Power = true;


					}
					else if (Power == true && (Mz.Mapa.at(i).at((j + 1)) == Enemigos + 48 && FLAGZ1 == true)) {
						Mz.setSquare('0' + Camino, j, i);
						Mz.setSquare('0' + Personaje, j + 1, i);

						PacmanPos.x = j + 1;

						FLAGX = FLAGX1 = FLAGZ = FLAGZ1 = false;
						Power = false;
					}
					else if ((Mz.Mapa.at(i).at((j - 1)) == Pellets + 48 && FLAGZ == true) || (Mz.Mapa.at(i).at((j - 1)) == Camino + 48 && FLAGZ == true)) {
						Mz.setSquare('0' + Camino, j, i);
						Mz.setSquare('0' + Personaje, j - 1, i);
						/*Traslacion = glm::translate(glm::mat4(1.0f), glm::vec3(((i * 2) - 12), 0.5f, ((j * 2) - 20) - 1.0f));*/
						//Traslacion -= glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 1));
						PacmanPos.x = j - 1;
						FLAGX = FLAGX1 = FLAGZ = FLAGZ1 = false;
			
					}
					else if ((Mz.Mapa.at(i).at((j - 1)) == SupperPellets + 48 && FLAGZ == true)){
						Mz.setSquare('0' + Camino, j, i);
						Mz.setSquare('0' + Personaje, j - 1, i);
						/*Traslacion = glm::translate(glm::mat4(1.0f), glm::vec3(((i * 2) - 12), 0.5f, ((j * 2) - 20) - 1.0f));*/
						//Traslacion -= glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 1));
						PacmanPos.x = j - 1;
						FLAGX = FLAGX1 = FLAGZ = FLAGZ1 = false;
						Power = true;
					}
					else if (Power == true && (Mz.Mapa.at(i).at((j - 1)) == Enemigos + 48 && FLAGZ == true)) {
						Mz.setSquare('0' + Camino, j, i);
						Mz.setSquare('0' + Personaje, j - 1, i);

						PacmanPos.x = j - 1;

						FLAGX = FLAGX1 = FLAGZ = FLAGZ1 = false;
						Power = false;
					}
					else if ((Mz.Mapa.at(i + 1).at((j)) == Pellets + 48 && FLAGX == true) || (Mz.Mapa.at(i + 1).at((j)) == Camino + 48 && FLAGX == true)) {
						Mz.setSquare('0' + Camino, j, i);
						Mz.setSquare('0' + Personaje, j, i + 1);

						//Traslacion += glm::translate(glm::mat4(1.0f), glm::vec3(1, 0, 0));
						PacmanPos.y = i + 1;
						FLAGX = FLAGX1 = FLAGZ = FLAGZ1 = false;
				
					}
					else if ((Mz.Mapa.at(i + 1).at((j)) == SupperPellets + 48 && FLAGX == true)) {
						Mz.setSquare('0' + Camino, j, i);
						Mz.setSquare('0' + Personaje, j, i + 1);

						//Traslacion += glm::translate(glm::mat4(1.0f), glm::vec3(1, 0, 0));
						PacmanPos.y = i + 1;
						FLAGX = FLAGX1 = FLAGZ = FLAGZ1 = false;
						Power = true;
					}
					else if (Power == true && (Mz.Mapa.at(i + 1).at((j)) == Enemigos + 48 && FLAGX == true)) {
						Mz.setSquare('0' + Camino, j, i);
						Mz.setSquare('0' + Personaje, j, i + 1);

						PacmanPos.y = i + 1;

						FLAGX = FLAGX1 = FLAGZ = FLAGZ1 = false;
						Power = false;
					}
					else if ((Mz.Mapa.at(i - 1).at((j)) == Pellets + 48 && FLAGX1 == true) || (Mz.Mapa.at(i - 1).at((j)) == Camino + 48 && FLAGX1 == true)) {

						Mz.setSquare('0' + Camino, j, i);
						Mz.setSquare('0' + Personaje,j, i - 1);

						//Traslacion -= glm::translate(glm::mat4(1.0f), glm::vec3(1, 0, 0));
						PacmanPos.y = i - 1;
						FLAGX = FLAGX1 = FLAGZ = FLAGZ1 = false;

					}
					else if ((Mz.Mapa.at(i - 1).at((j)) == SupperPellets + 48 && FLAGX1 == true)) {

						Mz.setSquare('0' + Camino, j, i);
						Mz.setSquare('0' + Personaje, j, i - 1);

						//Traslacion -= glm::translate(glm::mat4(1.0f), glm::vec3(1, 0, 0));
						PacmanPos.y = i - 1;
						FLAGX = FLAGX1 = FLAGZ = FLAGZ1 = false;
						Power = true;
					}

					else if (Power == true && (Mz.Mapa.at(i - 1).at((j)) == Enemigos + 48 && FLAGX1 == true)) {
						Mz.setSquare('0' + Camino, j, i);
						Mz.setSquare('0' + Personaje, j, i - 1);

						PacmanPos.y = i - 1;

						FLAGX = FLAGX1 = FLAGZ = FLAGZ1 = false;
						Power = false;
					}
				
			}
		}
	}
	FLAGX = FLAGX1 = FLAGZ = FLAGZ1 = false;
}

PacMan::PacMan(): Rotacion(glm::mat4(1.0f))
{
}
PacMan::~PacMan()
{
}
