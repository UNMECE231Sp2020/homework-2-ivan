#include <iostream>

class Complex {
	private:
	
		double _real; 
		double _image;


	public:
		Complex();
		Complex(double x);
		Complex(double x, double y);
		Complex(const Complex *point);
		~Complex();

		double real() const;
		double image() const;

		void print();

		Complex add_complex(Complex);
		Complex sub_complex(Complex);
		Complex multiply_complex(Complex);
		Complex division_complex(Complex);
		Complex conjugate(Complex);

		double magnitude();
		double phase();

		Complex operator+(Complex x);
		Complex operator-(Complex x);
		Complex operator*(Complex x);
		Complex operator/(Complex x);
		Complex operator=(Complex x);

		friend std::ostream& operator<<(std::ostream &out, const Complex &x);
		friend std::istream& operator>>(std::istream &in, Complex &x);
};
