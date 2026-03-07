#pragma once

#ifndef _COMPLEX_
#define _COMPLEX_

//1.前置声明
#include <cmath>
#include <iostream>
using std::ostream;

//2.类-声明
class complex
{
public:
	complex(double r = 0, double i = 0)//默认参数
		: re(r), im(i)
	{ }
	double real() const { return re; }
	double imag() const { return im; }
	complex& operator += (const complex&);

private:
	double re, im;
	friend complex& _doapl(complex*, const complex&);
};

//3.类-定义
inline complex& _doapl(complex* ths, const complex& r)
{
	ths->re += r.re;
	ths->im += r.im;
	return *ths;
}

inline complex& complex::operator+= (const complex& r)//成员函数操作符重载
{
	return _doapl(this, r);
}

ostream& operator << (ostream& os, const complex& x)
{
	return os << '(' << x.real() << ',' << x.imag() << ')';
}

inline complex operator + (const complex& x, const complex& y)//非成员函数操作符重载
{
	return complex(x.real() + y.real(), x.imag() + y.imag());//临时对象语法
}

inline complex operator + (const complex& x, double y)
{
	return complex(x.real() + y, x.imag());
}

inline complex operator + (double x, const complex& y)
{
	return complex(y.real() + x, y.imag());
}

inline complex operator + (const complex& x)//表正负号
{
	return x;
}

inline complex operator - (const complex& x)//表正负号	
{
	return complex(-x.real(), -x.imag());
}

inline bool operator == (const complex& x, const complex& y)
{
	return (x.real() == y.real()) && (x.imag() == y.imag());
}

inline bool operator == (const complex& x, double y)
{
	return (x.real() == y) && x.imag() == 0;
}

inline bool operator == (double x, const complex& y)
{
	return (x == y.real()) && y.imag() == 0;
}

inline bool operator != (const complex& x, const complex& y)
{
	return (x.real() != y.real()) || (x.imag() != y.imag());
}

inline bool operator != (const complex& x, double y)
{
	return (x.real() != y) || (x.imag() != 0);
}

inline bool operator != (double x, const complex& y)
{
	return (y.real() != x) || (y.imag() != 0);
}

inline complex conj(const complex& x)//共轭复数
{
	return complex(x.real(), -x.imag());
}

#endif // !_COMPLEX_
