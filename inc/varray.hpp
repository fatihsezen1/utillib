#ifndef VARRAY_HPP_
#define VARRAY_HPP_

#include <cstddef>
#include <initializer_list>
#include <cmath>

class VArray {
public:
	VArray() = default;
	VArray(size_t size);
	VArray(const double* v, size_t size);
	VArray(const VArray& va);// copy constructer
	VArray(std::initializer_list<double> il); // initializer list constructer(daha islemedik)
	~VArray();
	VArray add(const VArray& va) const;
	VArray add(double d) const;
	VArray sub(const VArray& va) const;
	VArray sub(double d) const;
	VArray mul(const VArray& va) const;
	VArray mul(double d) const;
	VArray div(const VArray& va) const;
	VArray div(double d) const;
	VArray pow(double d) const;


	void disp() const;
	double sum() const;
	double mean() const;
	
	size_t size() const { return m_size; }
private:
	double* m_v;
	size_t m_size;
};


#endif // VARRAY_HPP_
