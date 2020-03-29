#include <iostream>
#include "my_class.hpp"
#include <math.h>

Complex::Complex(){
	_real=0;
	_image=0;
	}

Complex::Complex(double x){
	_real = x;
	_image = 0;
	}

Complex::Complex(double x, double y){
	_real = x;
	_image = y;
	}

Complex::Complex(const Complex *point){
	_real = point._real;
	_image = point._image;
	}

Complex::~Complex(){}

void Complex::print (){
	if(_image < 0){
		printf("%.4lf - %.3lf\n", _real, -_image);
	}
	else{
		printf("%.4lf + %.4lf\n", _real, _image);
	}
}

Complex Complex::add_complex(Complex x){
	Complex z = { _real + x._real, _image + x._image};
	return z;
}

Complex Comlex::sub_complex(Complex x){
	Complex z = { _real- x._real, _image - x._image};
	return z;
}

Complex Complex::multiply_complex(Complex x){
	Complex z = {( _real * x._real) + ( _image * x._image*-1), ( -image * x._real) +  ( _real * x._image)};

	return z;
}

Complex Complex::division_complex(Complex x){
	double denom = magnitude(x._real)*magnitude(x._real);
	
	if(denom == 0){

		printf("undefined");
	}

	else{

		Complex z = multiply_complex(_real, conjugate(x)));
		z.real /= denom;
		z.image /= denom;
	}
	return z;

}

Complex Complex::conjugate(){
	_image *= -1;
	return _image;
}

double Complex::magnitude(){
	return sqrt((_real*_real) + (_image*_image));
}

double Complex::phase(){
	double p = atan(_image/_real);
	p = p * (180/M_PI);
	return (p<0) ? -p : p;
}
	

Complex Complex::operator+(Complex x){
	Complex z = { _real + x._real, _image + x._image};
	return z;
}

Complex Complex::operator-(Complex x){
	Complex z = { _real- x._real, _image - x._image};
	return z;
}

Complex Complex::operator*(Complex x){
	Complex z = {( _real * x._real) + ( _image * x._image*-1), ( -image * x._real) +  ( _real * x._image)};

	return z;
}

Complex Complex::operator/(Complex x){
	double denom = magnitude(x._real)*magnitude(x._real);
	
	if(denom == 0){

		printf("undefined");
	}

	else{

		Complex z = multiply_complex(_real, conjugate(x)));
		z._real /= denom;
		z._image /= denom;
	}
	return z;

}

Complex Complex::operator=(Complex x){
	_real = x._real;
	_image = x._image;

	return *this;
}

std::ostream &operator>>(std::istraem &in, Complex &Data{
	in >> Data._real >> Data._image;
	return in;
}

std::istream &operator>>(std::istream &in, Complex &Data){
	in>>Data._real>>Data._image;
	return in;
}



