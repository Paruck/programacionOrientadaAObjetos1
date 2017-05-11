#pragma once
#include <string>

class Complex {
private:
	float real, imaginario;
public:
	Complex();
	Complex(const float &r, const float &i);
	Complex(const Complex &c);
	Complex &operator = (const Complex &c);
	Complex operator + (const Complex &c) const;
	Complex operator - (const Complex &c) const;
	Complex operator * (const Complex &c) const;
	Complex operator / (const Complex &c) const;
	Complex &operator += (const Complex &c);
	std::string print();
}; 
