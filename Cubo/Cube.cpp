#include "Application.h"
#include <iostream>
#include <vector>

#define PI  3.1516

std::vector<vect3> vertices;
std::vector<vect3> verticesT;


int CreateHash(int dx, int dy)
{
	int ret = 0;
	dx >= 0 ? ++ret : --ret;
	dy >= 0 ? ret += 2 : ret -= 2;
	ret = abs(dx) >= abs(dy) ? ret << 1 : ret << 2;
	return ret;
}

void Application::crearPoligonos(int lados, int radio)
{
	int		angulo = 0;

	int		incremento = 360 / lados;
	vect3	mV;
	mV.v[2] = 1;
	for (int i = lados + 1; --i;) {
		mV.v[0] = cx;
		mV.v[1] = cy;
		mV.v[0] += radio * cos(angulo * PI / 180);
		mV.v[1] += radio * sin(angulo * PI / 180);
		vertices.push_back(mV);
		angulo += incremento;
	}
}

vect3 Application::puntoMedio(vect3 o, vect3 p)
{
	vect3 result;
	result.v[0] = (o.v[0] + p.v[0]) / 2;
	result.v[1] = (o.v[1] + p.v[1]) / 2;
	result.v[2] = 1;
	return result;
}

void Application::sierpinskyAlgorithm(vect3 a, vect3 b, vect3 c, int subDiv)
{
	std::vector<vect3> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);


	if (subDiv > 0) {
		vect3 ab = puntoMedio(a, b),
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

Mat3 Application::Rotation(const float& angulo)
{
	Mat3 matrizAngulo;
	matrizAngulo.m[0][0] = cos(angulo);
	matrizAngulo.m[0][1] = -sin(angulo);
	matrizAngulo.m[0][2] = 0;

	matrizAngulo.m[1][0] = sin(angulo);
	matrizAngulo.m[1][1] = cos(angulo);
	matrizAngulo.m[1][2] = 0;

	matrizAngulo.m[2][0] = 0;
	matrizAngulo.m[2][1] = 0;
	matrizAngulo.m[2][2] = 1;


	return matrizAngulo;
}

Mat3 Application::Translation(const float &x, const float & y)
{
	Mat3 matrizTras;
	matrizTras.m[0][0] = 1;
	matrizTras.m[0][1] = 0;
	matrizTras.m[0][2] = x;

	matrizTras.m[1][0] = 0;
	matrizTras.m[1][1] = 1;
	matrizTras.m[1][2] = y;

	matrizTras.m[2][0] = 0;
	matrizTras.m[2][1] = 0;
	matrizTras.m[2][2] = 1;


	return matrizTras;
}

Mat4 Application::Traslacion(const float & x, const float & y, const float & z)
{
	Mat4 matrizTras;
	matrizTras.m[0][0] = 1;
	matrizTras.m[0][1] = 0;
	matrizTras.m[0][2] = 0;
	matrizTras.m[0][3] = x;

	matrizTras.m[1][0] = 0;
	matrizTras.m[1][1] = 1;
	matrizTras.m[1][2] = 0;
	matrizTras.m[1][3] = y;

	matrizTras.m[2][0] = 0;
	matrizTras.m[2][1] = 0;
	matrizTras.m[2][2] = 1;
	matrizTras.m[2][3] = z;

	matrizTras.m[3][0] = 0;
	matrizTras.m[3][1] = 0;
	matrizTras.m[3][2] = 0;
	matrizTras.m[3][3] = 1;


	return matrizTras;
}

Mat4 Application::RotationX(const float & angulo)
{
	Mat4 matrizAngulo;
	matrizAngulo.m[0][0] = 1;
	matrizAngulo.m[0][1] = 0;
	matrizAngulo.m[0][2] = 0;
	matrizAngulo.m[0][3] = 0;

	matrizAngulo.m[1][0] = 0;
	matrizAngulo.m[1][1] = cos(angulo);
	matrizAngulo.m[1][2] = -sin(angulo);
	matrizAngulo.m[1][3] = 0;

	matrizAngulo.m[2][0] = 0;
	matrizAngulo.m[2][1] = sin(angulo);
	matrizAngulo.m[2][2] = cos(angulo);
	matrizAngulo.m[2][3] = 0;

	matrizAngulo.m[3][0] = 0;
	matrizAngulo.m[3][1] = 0;
	matrizAngulo.m[3][2] = 0;
	matrizAngulo.m[3][3] = 1;
	
	return matrizAngulo;
}

Mat4 Application::RotationY(const float & angulo)
{
	Mat4 matrizAngulo;
	matrizAngulo.m[0][0] = cos(angulo);
	matrizAngulo.m[0][1] = 0;
	matrizAngulo.m[0][2] = sin(angulo);
	matrizAngulo.m[0][3] = 0;

	matrizAngulo.m[1][0] = 0;
	matrizAngulo.m[1][1] = 1;
	matrizAngulo.m[1][2] = 0;
	matrizAngulo.m[1][3] = 0;

	matrizAngulo.m[2][0] = -sin(angulo);
	matrizAngulo.m[2][1] = 0;
	matrizAngulo.m[2][2] = cos(angulo);
	matrizAngulo.m[2][3] = 0;
	
	matrizAngulo.m[3][0] = 0;
	matrizAngulo.m[3][1] = 0;
	matrizAngulo.m[3][2] = 0;
	matrizAngulo.m[3][3] = 1;

	return matrizAngulo;
}

Mat4 Application::RotationZ(const float & angulo)
{
	Mat4 matrizAngulo;
	matrizAngulo.m[0][0] = cos(angulo);
	matrizAngulo.m[0][1] = -sin(angulo);
	matrizAngulo.m[0][2] = 0;
	matrizAngulo.m[0][3] = 0;

	matrizAngulo.m[1][0] = sin(angulo);
	matrizAngulo.m[1][1] = cos(angulo);
	matrizAngulo.m[1][2] = 0;
	matrizAngulo.m[1][3] = 0;

	matrizAngulo.m[2][0] = 0;
	matrizAngulo.m[2][1] = 0;
	matrizAngulo.m[2][2] = 1;
	matrizAngulo.m[2][3] = 0;

	matrizAngulo.m[3][0] = 0;
	matrizAngulo.m[3][1] = 0;
	matrizAngulo.m[3][2] = 0;
	matrizAngulo.m[3][3] = 1;

	return matrizAngulo;
}

std::vector<vect4> Application::crearCubo()
{
	std::vector<vect4> vertices1;

	vect4 a = vect4(cx - 100.0, cy - 100.0, 100.0);
	vect4 b = vect4(cx + 100.0, cy - 100.0, 100.0);
	vect4 c = vect4(cx + 100.0, cy + 100.0, 100.0);
	vect4 d = vect4(cx - 100.0, cy + 100.0, 100.0);
	vect4 e = vect4(cx - 100.0, cy - 100.0, -100.0);
	vect4 f = vect4(cx + 100.0, cy - 100.0, -100.0);
	vect4 g = vect4(cx + 100.0, cy + 100.0, -100.0);
	vect4 h = vect4(cx - 100.0, cx + 100.0, -100.0);
	vertices1.push_back(a);
	vertices1.push_back(b);
	vertices1.push_back(c);
	vertices1.push_back(d);
	vertices1.push_back(e);
	vertices1.push_back(f);
	vertices1.push_back(g);
	vertices1.push_back(h);
	return vertices1;
}

vect4 Application::Normalize(const vect4 & v)
{
	float distance = sqrt((v.v[0] * v.v[0]) +
		(v.v[1] * v.v[1]) +
		(v.v[2] * v.v[2]));
	if (distance != 0)
		return vect4(v.v[0] / distance, v.v[1] / distance, v.v[2] / distance);
	else
		return v;
}

Mat4 Application::LookAt(vect4 eye, vect4 target, vect4 up)
{
	vect4 rest = Resta(target, eye);
	vect4 ejez = Normalize(rest);
	vect4 ejex = Normalize(Cross(ejez, up));
	vect4 ejey = Normalize(Cross(ejex, ejez));
	//Mat4 RotY = RotationY(rad); esto no va
	Mat4 rot;
	rot.m[0][0] = ejex.v[0];  rot.m[0][1] = ejex.v[1];   rot.m[0][2] = ejex.v[2];   rot.m[0][3] = 0;  //renglon 1
	rot.m[1][0] = ejey.v[0];  rot.m[1][1] = ejey.v[1];   rot.m[1][2] = ejey.v[2];   rot.m[1][3] = 0;  //renglon 2
	rot.m[2][0] = ejez.v[0];  rot.m[2][1] = ejez.v[1];   rot.m[2][2] = ejez.v[2];   rot.m[2][3] = 0;  //renglon 4
	rot.m[3][0] = 0;		rot.m[3][1] = 0;   rot.m[3][2] = 0;   rot.m[3][3] = 1;  //renglon 4


	Mat4 translate = Traslacion(-eye.v[0], -eye.v[1], -eye.v[2]);
	return translate * rot;
}

vect4 Application::Resta(const vect4 & v1, const vect4 & v2)
{
	vect4 vecRes;
	vecRes.v[0] = v1.v[0] - (v2.v[0]);
	vecRes.v[1] = v1.v[1] - (v2.v[1]);
	vecRes.v[2] = v1.v[2] - (v2.v[2]);
	return vecRes;
}
Mat4 Application::Perspectiva(float fovyInDegrees, float aspectRatio, float znear, float zfar)
{
	float ymax, xmax;
	float temp, temp2, temp3, temp4;
	ymax = znear * tanf(fovyInDegrees *PI / 360.0);
	//ymin = -ymax;
	//xmin = -ymax * aspectRatio;
	xmax = ymax * aspectRatio;
	Mat4 m = glhFrustumf2(-xmax, xmax, -ymax, ymax, znear, zfar);
	return m;
}

Mat4 Application::glhFrustumf2(float left, float right, float bottom, float top, float znear, float zfar)
{
	Mat4 matrix;
	float temp, temp2, temp3, temp4;
	temp = 2.0 * znear;
	temp2 = right - left;
	temp3 = top - bottom;
	temp4 = zfar - znear;
	matrix.m[0][0] = temp / temp2;
	matrix.m[0][1] = 0.0;
	matrix.m[0][2] = 0.0;
	matrix.m[0][3] = 0.0;


	matrix.m[1][0] = 0.0;
	matrix.m[1][1] = temp / temp3;
	matrix.m[1][2] = 0.0;
	matrix.m[1][3] = 0.0;


	matrix.m[2][0] = (right + left) / temp2;
	matrix.m[2][1] = (top + bottom) / temp3;
	matrix.m[2][2] = (-zfar - znear) / temp4;
	matrix.m[2][3] = -1.0;

	matrix.m[3][0] = 0.0;
	matrix.m[3][1] = 0.0;
	matrix.m[3][2] = (-temp * zfar) / temp4;
	matrix.m[3][3] = 0.0;
	return matrix;
}

//Mat4 Application::LookAtRh(vect3 eye, vect3 target, vect3 up)
//{
//	/*vect3 zaxis = normal(eye - target);
//	vect3 xaxis = normal(cross(up, zaxis)); 
//	vect3 yaxis = cross(zaxis, xaxis);
//	return Mat4();*/
//}

void Application::setUp() {
	moveTo(255, 255);
	vertices1 = crearCubo();
}

void Application::update()
{
	
	float contador = 1.0f;
	x += contador;
	angulo = 0;
	angulo = angulo + 1 % 360;
	rad += angulo * PI / 180.0f;
	Mat3 trans1, trans2;
	trans1 = Translation(-255, -255);
	trans2 = Translation(255, 255);
	RotateMatrix = Rotation(rad);
	TransMatrxi = Translation(y, x);
	Final = mtrx * trans2 * RotateMatrix * trans1;
	/*for (vect3 &v : vertices) {
		v1 = mtrx.multi(v, Final);
		verticesT.push_back(v1);
	}*/
	Mat4 RotX = RotationX(rad);
	Mat4 RotY = RotationY(rad);
	Mat4 RotZ = RotationZ(rad);
	//(float fovyInDegrees, float aspectRatio, float znear, float zfar)
	Mat4 perspectiva = Perspectiva(45, WIDTH/HEIGHT, 1, 100); //esto esta mal

	Mat4 m1;
	vect4 v2;
	Mat4 Trans1, Trans2,Trans3;
	Trans1 = Traslacion(-255, -255, 1);
	Trans2 = Traslacion(255, 255, 1);
	Trans3 = Traslacion(170, 170, 1);
	//Aqui los parametros deben ser Ojo, Target, Up
	Mat4 Look = LookAt(vect4(15.0, 15.0, 15.0), vect4(0.0, 0.0, 0.0), vect4(0.0, 1.0, 0.0)); //Solo recibe 3 
	//Mat4 Look = LookAt(vertices1.at(0), vertices1.at(1), vertices1.at(2)); //esto esta mal. 
	//Mat4 Final1 =Trans2* Trans3* perspectiva *Look*RotY*RotZ*Trans1; //esto tambien esta mal. Tendria que ser algo como :
	Mat4 Final1 = perspectiva *Look*RotY*RotX * Trans1;
	verticesF.clear();
	for (vect4 &v : vertices1) {
		v2 = m1.multiP(v, Final1);
		verticesF.push_back(v2);
	}

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

	//setColor(0, 255, 255, 0);
	//circle( 100);
	clearScreen();
	setColor(0, 255, 132, 0);
	FUNCIONCHINGONA();

	//for (int i = vertices1.size(); i--;)
	//{
	//	for (int j = vertices1.at(i).size(); j--;)
	//	{
	//		moveTo(vertices1.at(i).at(j).v[0], vertices1.at(i).at(j).v[1]);
	//		lineTo(vertices1.at(i).at((j + 1) % vertices1.at(i).size()).v[0],
	//			vertices1.at(i).at((j + 1) % vertices1.at(i).size()).v[1]);
	//	}
	//}

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
		while (x <= x1) {
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
