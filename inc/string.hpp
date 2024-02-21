#ifndef STRING_HPP_
#define STRING_HPP_

#include <cstddef>
#include <ostream>

class String {
public:
	String();
	String(const char *str);
	String(const String &r);		// copy constructor
	String(String &&r);				// move constructor
	void String::disp() const;
    ~String();

	String operator +(const String &r) const;
	String operator +(const char *str) const;
	String operator *(int n) const;
	char &operator[] (std::size_t index) { return m_str[index]; }
	const char &operator[] (std::size_t index) const { return m_str[index]; }
	
	String &operator =(const String &r);
	String &operator =(const char *str);
	String &operator =(String &&r);

	friend std::ostream &operator <<(std::ostream &os, const String &r);
	
private:
	char *m_str;
	std::size_t m_len;
};

String operator +(const char *str, const String &r);
String operator *(int n, const String &r);

#endif