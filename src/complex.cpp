// #include <iostream>
// #include "Complex.hpp"

// using namespace std;

// ostream &operator <<(ostream &os, const Complex &r)
// {
// 	os << r.m_real << '+' << r.m_imag << 'i';

// 	return os;
// }

// // app.cpp

// #include <iostream>
// #include "complex.hpp"

// using namespace std;

// int main()
// {	
// 	Complex z(3, 2);

// 	cout << z << endl;

// 	return 0;
// }

#include <iostream>
#include "complex.hpp"

using namespace std;

Complex::Complex(double real, double imag)
{
	m_real = real;
	m_imag = imag;
}

void Complex::disp() const
{
	cout << m_real << '+' << m_imag << 'i' << endl;
}

Complex Complex::operator +(const Complex &r) const
{
	Complex result;

	result.m_real = m_real + r.m_real;
	result.m_imag = m_imag + r.m_imag;

	return result;
}

Complex Complex::operator +(double real) const
{
	Complex result;

	result.m_real = m_real + real;
	result.m_imag = m_imag;

	return result;
}

Complex Complex::operator -(const Complex &r) const
{
	Complex result;

	result.m_real = m_real - r.m_real;
	result.m_imag = m_imag - r.m_imag;

	return result;
}

Complex Complex::operator *(const Complex &r) const
{
	Complex result;

	result.m_real = m_real * r.m_real - m_imag * r.m_imag;
	result.m_imag = m_real * r.m_imag + m_imag * r.m_real;

	return result;
}

Complex &Complex::operator ++()
{
	++m_real;

	return *this;
}

const Complex Complex::operator ++(int)	
{
	Complex z = *this;

	++m_real;

	return z;
}

Complex &Complex::operator --()
{
	--m_real;

	return *this;
}

const Complex Complex::operator --(int)
{
	Complex z = *this;

	--m_real;

	return z;
}
