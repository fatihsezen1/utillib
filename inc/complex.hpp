#ifndef COMPLEX_HPP_
#define COMPLEX_HPP_

class Complex {
public:
	Complex() = default;
	Complex(double real, double imag = 0);
	Complex operator +(const Complex &r) const;
	Complex operator +(double real) const;
	Complex operator -(const Complex &r) const;
	Complex operator *(const Complex &r) const;

	Complex &operator ++();			// prefix
	const Complex operator ++(int);	// postfix

	Complex &operator --();			// prefix
	const Complex operator --(int);	// postfix

	void disp() const;
private:
	double m_real;
	double m_imag;
};

#endif