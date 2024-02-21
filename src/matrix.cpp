#include "matrix.hpp"

using namespace std;

Matrix::Matrix(size_t rowsize, size_t colsize)
{
	cout << "Matrix::Matrix parametreli\n";
	m_matrix = new double [rowsize * colsize];
	m_rowsize = rowsize;
	m_colsize = colsize;
}

Matrix::Matrix(const Matrix& r)
{
	cout << "Matrix::Matrix copy constructer\n";
	m_matrix = new double [r.m_rowsize * r.m_colsize];

	::memcpy(m_matrix, r.m_matrix, sizeof(double) * r.m_rowsize * r.m_colsize);
	m_rowsize = r.m_rowsize;
	m_colsize = r.m_rowsize;
}

Matrix::~Matrix()
{
	cout << "Matrix::~Matrix\n";
	delete[] m_matrix;
}

void Matrix::disp() const
{
	cout << "Matrix::disp() \n";
	cout << '[';
	for (size_t i = 0; i < m_rowsize; ++i) {
		for (size_t j = 0; j < m_rowsize; ++j) {
			cout << m_matrix + m_colsize * i + j << " ";
		}
	}
	cout << ']' << endl;
}

Matrix Matrix::add(const Matrix& r) const
{
	cout << "Matrix::add\n";
	if (rowsize() != r.rowsize() || colsize() != r.colsize())
		throw invalid_argument("invalid matrix dimensions");

	Matrix result(r.m_rowsize, r.m_colsize);
	
	for (size_t i = 0; i < m_rowsize * m_colsize; ++i) 
		result.m_matrix[i] = m_matrix[i] + r.m_matrix[i];
		
	return result;
}

Matrix Matrix::mul(const Matrix& r) const
{
	cout << "Matrix::mul\n";
	if (rowsize() != r.rowsize() || colsize() != r.colsize())
		throw invalid_argument("invalid matrix dimensions");

	Matrix result(r.m_rowsize, r.m_colsize);

	for (size_t i = 0; i < m_rowsize * m_colsize; ++i)
		result.m_matrix[i] = m_matrix[i] * r.m_matrix[i];

	return result;
}

Matrix Matrix::matmul(const Matrix& r) const
{
	cout << "Matrix::matmul\n";
	if (m_colsize != r.m_colsize)
		throw invalid_argument("invalid matrix dimensions");

	Matrix result(m_rowsize, r.m_colsize);

	double sum = 0.0;
	for (size_t i = 0; i < m_rowsize; ++i) {
		for (size_t j = 0; j < r.m_colsize; ++j) {
			for (size_t k = 0; k < m_colsize; ++k) {
				sum += m_matrix[i * m_colsize + k] * r.m_matrix[k * r.m_colsize + j];
			}
			result.m_matrix[i * result.m_colsize + j] = sum;
		}
	}

	return result;
}

Matrix Matrix::div(const Matrix& r) const
{
	cout << "Matrix::div\n";
	if (rowsize() != r.rowsize() || colsize() != r.colsize())
		throw invalid_argument("invalid matrix dimensions");

	if (rowsize() != r.rowsize() || colsize() != r.colsize())
		throw invalid_argument("invalid matrix dimensions");

	Matrix result(r.m_rowsize, r.m_colsize);

	for (size_t i = 0; i < m_rowsize * m_colsize; ++i)
		result.m_matrix[i] = m_matrix[i] / r.m_matrix[i];

	return result;
}

double& Matrix::at(size_t row, size_t col)
{
	cout << "Matrix::at setter\n";
	if (rowsize() <= row || colsize() <= col)
		throw invalid_argument("invalid index");

	return m_matrix[row * m_colsize + col];
}

const double& Matrix::at(size_t row, size_t col) const
{
	cout << "Matrix::at getter\n";
	if (rowsize() <= row || colsize() <= col)
		throw invalid_argument("invalid index");

	return m_matrix[row * m_colsize + col];
}

void Matrix::set_all_elements(double val)
{
	for (size_t i = 0; i < m_rowsize; ++i) {
		for (size_t j = 0; j < m_colsize; ++j) {
			m_matrix[i * m_colsize + j] = val;
		}
	}
}