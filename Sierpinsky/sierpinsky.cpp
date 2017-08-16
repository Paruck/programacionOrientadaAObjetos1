#include "Application.h"
#include <iostream>
#include <vector>

#define PI  3.1516

std::vector<vec2> vertices;

int CreateHash(int dx, int dy)
{
	int ret = 0;
	dx >= 0 ? ++ret : --ret;
	dy >= 0 ? ret += 2 : ret -= 2;
	ret = abs(dx) >= abs(dy) ? ret << 1 : ret << 2;
	return ret;
}

void Application::crearPoligonos(int lados)
{
	/*int		angulo = 0,
			radio = 50;

	int		incremento = 360 / lados;
	vec2	mV;

	moveTo(255, 255);
	mV.x = cx;
	mV.y = cy;
	for (int i = lados + 1; --i;) {

		mV.x += radio * cos(angulo * PI / 180);
		mV.y += radio * sin(angulo * PI / 180);
		vertices.push_back(mV);
		angulo += incremento;
	}*/
}

vec2 Application::puntoMedio(vec2 o, vec2 p)
{
	vec2 result;
	result.x = (o.x + p.x) / 2;
	result.y = (o.y + p.y) / 2;
	return result;
}

void Application::sierpinskyAlgorithm(vec2 a, vec2 b, vec2 c, int subDiv)
{
	if (subDiv > 0) {
		vec2 ab = puntoMedio(a, b),
			 bc = puntoMedio(b, c),
			 ca = puntoMedio(c, a);

		sierpinskyAlgorithm(a, ab, ca, subDiv - 1);
		sierpinskyAlgorithm(ab, b, bc, subDiv - 1);
		sierpinskyAlgorithm(ca, bc, c, subDiv - 1);
	}
	else {
		vertices.push_back(a);
		vertices.push_back(b);
		vertices.push_back(c);
	}
}

void Application::setUp() {

	int		lados = 3,
			angulo = 0,
			radio = 150;

	int		incremento = 360 / lados;
	vec2	mV;


	moveTo(255, 255);
	mV.x = cx;
	mV.y = cy;
	for (int i = lados + 1; --i;) {

		mV.x += radio * cos(angulo * PI / 180);
		mV.y += radio * sin(angulo * PI / 180);
		vertices.push_back(mV);
		angulo += incremento;
	}

	sierpinskyAlgorithm(vertices.at(0), vertices.at(1), vertices.at(2), 5);

}

void Application::update()
{

}

void Application::draw()
{
	//int x0 = 255,
	//	y0 = 255,
	//	x1 = 200,
	//	y1 = 270;
	//int numRand = rand();
	//moveTo(255, 255);
	//setColor(0, 255, 0,0);
	///*lineTo(500, 0);*/
	//for (int i = 360; i--;)
	//{
	//	setColor(0, 255, 255, 0);
	//	linea(x0, y0, (x1 * cos(i*(PI / 180))) + x0, (x1 * sin(i*(PI / 180))) + y0);
	//}

	//moveTo(255, 255);
	//setColor(0, 255, 255, 0);
	//circle( 100);

	setColor(0, 255, 132, 0);
	for (int i = vertices.size(); --i;) {
		lineTo(vertices[i].x, vertices[i].y);
		moveTo(vertices[i].x, vertices[i].y);
	}

}

void Application::linea(int x0, int y0, int x1, int y1)
{
	int dy = y1 - y0,
		dx = x1 - x0,
		x = x0 + 1,//256 
		y = y0,
		caseHash = CreateHash(dx, dy);

	dx = abs(dx);
	dy = abs(dy);
	switch (caseHash)
	{
	case 6:
	{// dx > dy 
		int E = 2 * (dy),
			nE = 2 * (dy - dx),
			d = 2 * dy - dx;//0
		while (x != x1) {
			(d > 0) ? y++, d += nE : d += E;
			putPixel(x, y, R, G, B, A);
			++x;
		}
		break;
	}
	case -2: // dx > -dy
	{
		int E = 2 * (dy),
			nE = 2 * (dy - dx),
			d = 2 * dy - dx;//0
		while (x != x1) {
			(d > 0) ? y--, d += nE : d += E;
			putPixel(x, y, R, G, B, A);
			++x;
		}
		break;
	}

	case -4: // -dy > dx
	{
		int E = 2 * (dx),
			nE = 2 * (dx - dy),
			d = 2 * dx - dy;//0
		while (y != y1) {
			(d > 0) ? x++, d += nE : d += E;
			putPixel(x, y, R, G, B, A);
			--y;
		}
		break;
	}
	case -12: //-dy > -dx
	{
		int E = 2 * (dx),
			nE = 2 * (dx - dy),
			d = 2 * dx - dy;//0
		while (y != y1) {
			(d > 0) ? x--, d += nE : d += E;
			putPixel(x, y, R, G, B, A);
			--y;
		}
		break;
	}

	case -6: //-dx > -dy
	{
		int E = 2 * (dy),
			nE = 2 * (dy - dx),
			d = 2 * dy - dx;//0
		while (x != x1) {
			(d > 0) ? y--, d += nE : d += E;
			putPixel(x, y, R, G, B, A);
			--x;
		}
		break;
	}
	case 2: //-dx> dy
	{
		int E = 2 * (dy),
			nE = 2 * (dy - dx),
			d = 2 * dy - dx;//0
		while (x != x1) {
			(d > 0) ? y++, d += nE : d += E;
			putPixel(x, y, R, G, B, A);
			--x;
		}
		break;
	}
	case 4: //dy > -dx
	{
		int E = 2 * (dx),
			nE = 2 * (dx - dy),
			d = 2 * dx - dy;//0
		while (y != y1) {
			(d > 0) ? --x, d += nE : d += E;
			putPixel(x, y, R, G, B, A);
			++y;
		}
		break;
	}
	case 12: //dy > dx
	{
		int E = 2 * (dx),
			nE = 2 * (dx - dy),
			d = 2 * dx - dy;//0
		while (y != y1) {
			(d > 0) ? ++x, d += nE : d += E;
			putPixel(x, y, R, G, B, A);
			++y;
		}
		break;
	}
	}
}

void Application::circle(int r)
{
	int x = 0,
		y = r,
		d = 3 - 2 * (r);

	while (x <= y) {
		putPixel(cx + x, cy + y);
		putPixel(cx - x, cy + y);
		putPixel(cx + x, cy - y);
		putPixel(cx - x, cy - y);
		putPixel(cx + y, cy + x);
		putPixel(cx - y, cy + x);
		putPixel(cx + y, cy - x);
		putPixel(cx - y, cy - x);
		++x;

		if (d <= 0) {
			d += 2 * (x)+3;
		}
		else {
			d += 2 * (x - y) - 5;
			--y;
		}

		/*(d <= 0)? d += (7* x) + 200: --y, d += 2* (x-y) - 100;*/
	}
}
