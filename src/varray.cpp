#include <iostream>
#include <stdexcept>
#include <cstring>
#include "varray.hpp"

VArray::VArray(size_t size)
{
	m_v = new double[size];
	m_size = size;
}
VArray::VArray(const double* v, size_t size) : VArray(size)
{
	::memcpy(m_v,v, sizeof(double) * size);
}

VArray::~VArray()
{
	delete[] m_v;
}

VArray::VArray(std::initializer_list<double> il)
{
	m_v = new double[il.size()];
	m_size = il.size();

	size_t i = 0;
	for (auto val : il) {
		m_v[i++] = val;
	}
}

VArray VArray::add(const VArray& va) const
{
	if (m_size != va.m_size)
		throw std::invalid_argument("VArrays must be the same size");

	VArray result(m_size);
	
	for (size_t i = 0; i < m_size; ++i) {
		result.m_v[i] = m_v[i] + va.m_v[i];
	}

	return result; //burada copy const cag�r�l�r. yazmazsan
}

VArray VArray::add(double d) const
{
	VArray result(m_size);

	for (size_t i = 0; i < m_size; ++i) {
		result.m_v[i] = m_v[i] + d;
	}

	return result;
}

VArray VArray::sub(const VArray& va) const
{
	if (m_size != va.m_size)
		throw std::invalid_argument("VArrays must be the same size");

	VArray result(m_size);

	for (size_t i = 0; i < m_size; ++i) {
		result.m_v[i] = m_v[i] - va.m_v[i];
	}

	return result; //burada copy const cag�r�l�r. yazmazsan
}

VArray VArray::sub(double d) const
{
	VArray result(m_size);

	for (size_t i = 0; i < m_size; ++i) {
		result.m_v[i] = m_v[i] - d;
	}

	return result;
}

VArray VArray::mul(const VArray& va) const
{
	if (m_size != va.m_size)
		throw std::invalid_argument("VArrays must be the same size");

	VArray result(m_size);

	for (size_t i = 0; i < m_size; ++i) {
		result.m_v[i] = m_v[i] * va.m_v[i];
	}

	return result;
}

VArray VArray::mul(double d) const
{
	VArray result(m_size);

	for (size_t i = 0; i < m_size; ++i) {
		result.m_v[i] = m_v[i] * d;
	}

	return result;
}

VArray VArray::div(const VArray& va) const
{
	if (m_size != va.m_size)
		throw std::invalid_argument("VArrays must be the same size");

	VArray result(m_size);

	for (size_t i = 0; i < m_size; ++i) {
		result.m_v[i] = m_v[i] / va.m_v[i];
	}

	return result;
}

VArray VArray::div(double d) const
{
	VArray result(m_size);

	for (size_t i = 0; i < m_size; ++i) {
		result.m_v[i] = m_v[i] / d;
	}

	return result;
}

VArray VArray::pow(double d) const
{
	VArray result(m_size);

	for (size_t i = 0; i < m_size; ++i) {
		result.m_v[i] = ::pow(m_v[i], d); //burada gloal pow cagrildi
	}

	return result;
}

void VArray::disp() const
{
	std::cout << '[';
	for (size_t i = 0; i < m_size; ++i) {
		std::cout << m_v[i] << " ";
	}
	std::cout << ']';
	std::cout << std::endl;
}

VArray::VArray(const VArray& va)
{
	m_v = new double[va.m_size];
	m_size = va.m_size;

	::memcpy(m_v, va.m_v, sizeof(double) * m_size);
}

double VArray::sum() const
{
	double total = 0;
	for (size_t i = 0; i < m_size; ++i)
		total += m_v[i];

	return total;
}

double VArray::mean() const
{
	return sum() / m_size;
}