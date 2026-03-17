#define _CRT_SECURE_NO_WARNINGS
#include "myString.h"

inline myString::myString(const char* cstr = 0)
{
	if (cstr)
	{
		m_data = new char[strlen(cstr) + 1];
		strcmp(m_data, cstr);
	}
	else//未定义初值
	{
		m_data = new char[1];
		*m_data = '\0';
	}
}

inline myString::~myString()
{
	delete[] m_data;
}

inline myString::myString(const myString& str)
{
	m_data = new char[strlen(str.m_data) + 1];
	strcpy(m_data, str.m_data);
}

inline myString& myString::operator=(const myString& str)
{
	if (this == &str)//检测自我赋值  非常重要！！！
		return *this;

	delete[] m_data;
	m_data = new char[(strlen(str.m_data) + 1)];
	strcpy(m_data, str.m_data);
	return *this;
}

