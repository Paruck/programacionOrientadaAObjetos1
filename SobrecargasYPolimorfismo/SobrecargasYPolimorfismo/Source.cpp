#include "Header.h"
#include <iostream>
#include "string"
#include "sstream"
using std::string;
using std::stringstream;
using std::ostringstream;

Complex::Complex() : real(0), imaginario(0)
{}
Complex::Complex(const float &r, const float &i) : real(r), imaginario(i)
{}
Complex::Complex(const Complex &c) : real(c.real), imaginario(c.imaginario)
{}
Complex &Complex:: operator =(const Complex &c)
{
	if (this == &c)
     return *this;
	real = c.real;
	imaginario = c.imaginario;
	return *this;
}
Complex Complex:: operator +(const Complex &c) const
{
	return Complex(this->real + c.real, this->imaginario + c.imaginario);
}
Complex Complex:: operator -(const Complex &c) const
{
	return Complex(this->real - c.real, this->imaginario - c.imaginario);
}
Complex Complex:: operator *(const Complex &c)const
{
	return Complex(this->real * c.real, this->imaginario * c.imaginario);
}
Complex Complex:: operator /(const Complex &c)const
{
	return Complex(this->real / c.real, this->imaginario / c.imaginario);
}
Complex &Complex:: operator +=(const Complex &c)
{
    real += c.real;
    imaginario += c.imaginario;
	return *this;
}
    
string print() {
	ostringstream ss;
	ostringstream si;
	return Complex(real = ss.str(), imaginario = si.str());
}


void main() {
	Complex c1(2, 2), c2(3, 3);
	Complex c3 = (c1 + (c2));
	std::cout << print() << "\n";
}