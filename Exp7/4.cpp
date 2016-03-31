#include <algorithm>

class Complex
{
public:
	double real;
	double imag;
	Complex():real(0),imag(0)
	{
	}
	Complex(int a):real(a),imag(0)
	{
	}
	Complex(int a, int b) :real(a), imag(b)
	{
	}
	bool operator==(const Complex& T) const {
		return (real == T.real)&&(imag == T.imag);
	}
	bool operator!=(const Complex& T) const {
		return (real != T.real)||(imag != T.imag);
	}
	Complex operator+(const Complex& T) const &{
		Complex rst(*this);
		rst.real += T.real;
		rst.imag += T.imag;
		return std::move(rst);
	}
	Complex operator-(const Complex& T) const &{
		Complex rst(*this);
		rst.real -= T.real;
		rst.imag -= T.imag;
		return std::move(rst);
	}
	Complex operator+(const Complex& T) && {
		real += T.real;
		imag += T.imag;
		return std::move(*this);
	}
	Complex operator-(const Complex& T) && {
		real -= T.real;
		imag -= T.imag;
		return std::move(*this);
	}
	Complex operator+=(const Complex& T) {
		real += T.real;
		imag += T.imag;
		return std::move(*this);
	}
	Complex operator-=(const Complex& T) {
		real -= T.real;
		imag -= T.imag;
		return std::move(*this);
	}
	Complex operator*(const Complex& T) const {
		Complex rst;
		rst.real = T.real*real - T.imag*imag;
		rst.imag = T.real*imag + T.imag*real;
		return std::move(rst);
	}
	Complex operator/(const Complex& T) const {
		Complex rst;
		rst.real = (T.real*real + T.imag*imag) / (T.real*T.real + T.imag*T.imag);
		rst.imag = - (T.real*imag - T.imag*real) / (T.real*T.real + T.imag*T.imag);
		rst.imag = T.real*imag + T.imag*real;
		return std::move(rst);
	}
	Complex operator*=(const Complex& T) &&{
		*this = *this*T;
		return std::move(*this);
	}
	Complex operator*=(const Complex& T) & {
		*this = *this*T;
		return *this;
	}
	Complex operator/=(const Complex& T) && {
		*this = *this/T;
		return std::move(*this);
	}
	Complex operator/=(const Complex& T) & {
		*this = *this/T;
		return *this;
	}
};
