#pragma once

#ifndef _MYSTRING_
#define _MYSTRING_

//1.前置声明
#include <cstring>
#include <iostream>


//2.类-声明
class myString
{
public:
	myString(const char* cstr = 0);//构造函数
	myString(const myString& str);//拷贝构造
	myString& operator = (const myString& str);//拷贝复制
	~myString();//析构函数

	char* get_c_str() const { return m_data; }

private:
	char* m_data;
};

#endif // !_MYSTRING_
