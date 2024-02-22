#ifndef MATRIX_HPP_
#define MATRIX_HPP_

#include <iostream>
#include <cstring>

class Matrix {

public:
	Matrix(size_t rowsize, size_t colsize);
	Matrix(const Matrix& r);
	~Matrix();
	void disp() const;
	Matrix add(const Matrix& r) const;
	Matrix sub(const Matrix& r) const;
	Matrix mul(const Matrix& r) const;
	Matrix matmul(const Matrix& r) const;
	Matrix div(const Matrix& r) const;
	double& at(size_t row, size_t col);
	const double& at(size_t row, size_t col) const;
	
	size_t rowsize() const { return m_rowsize; }
	size_t colsize() const { return m_colsize; }
	void set_all_elements(double val);

private:
	double* m_matrix;
	size_t m_rowsize;
	size_t m_colsize;

};

#endif // MATRIX_HPP_