#include <iostream>
#include <cstring>
#include "string.hpp"

using namespace std;

String::String()
{
	m_str = nullptr;
	m_len = 0;
}

String::String(const char *str)
{
	m_len = strlen(str);

	m_str = new char[m_len + 1];
	strcpy(m_str, str);
}

String::String(const String &r)
{
	if (r.m_str != nullptr) {
		m_str = new char[r.m_len + 1];
		strcpy(m_str, r.m_str);
	}
	else
		m_str = nullptr;
	m_len = r.m_len;
}

String::String(String &&r)
{
	m_str = r.m_str;
	m_len = r.m_len;
	r.m_str = nullptr;
}

void String::disp() const
{
	cout << m_str << endl;
}

String &String::operator =(const String &r)
{
	if (this == &r)		/* nesne kendisine atanmış mı? */
		return *this;

	delete[] m_str;

	m_len = r.m_len;
	m_str = new char[m_len + 1];
	strcpy(m_str, r.m_str);

	return *this;
}

String &String::operator =(const char *str)
{
	delete[] m_str;

	m_len = strlen(str);
	m_str = new char[m_len + 1];
	strcpy(m_str, str);

	return *this;
}

String &String::operator =(String &&r)
{
	delete m_str;

	m_len = r.m_len;
	m_str = r.m_str;

	r.m_str = nullptr;

	return *this;
}

String::~String()
{
	delete[] m_str;
}