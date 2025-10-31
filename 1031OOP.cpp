#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//面向对象三大特性：封装、继承、多态
//类的引入
// 类本质就是结构体
//在C语言中，结构体内只能定义变量
//在C++中，结构体内不止可以定义变量，还可以定义函数
//这样在结构体中既定义变量又定义函数的结构体就可以被称为类（Class）


//类的定义
class className
{
	//成员变量
	//成员函数
};
//所以简单来说，类就是属性和方法的集合，属性就是类中的数据，方法就是调用这些数据进行操作的函数


//类的两种定义方式
//1.声明和定义全部放在类体中
//要注意，成员函数如果在类中定义，编译器会将其当作内联函数处理
class Person
{
public:
	void showinfo()
	{
		std::cout << _name << std::endl;
		std::cout << _sex << std::endl;
		std::cout << _age << std::endl;
	}
private:
	char* _name;
	char* _sex;
	int _age;
};
//2.定义和声明分开放（推荐）
//在头文件中声明类的成员变量与成员函数；在源文件中定义类的成员函数

//类的访问限定符及封装
//限定符
//public(公有)、protected(保护)、private(私有)
//public修饰的成员可以在类的外面直接被访问；private和protected修饰的在类的外面不可以被直接访问

//注：
//1.访问限定符的作用域是从该访问限定符出现的位置开始直到下一个访问限定符为止
//2.class的默认访问权限为private，struct则为public
//3.访问限定符限制的是外面，就像锁防的是外人

//封装
//封装本质是一种管理手段，将属性（数据）和方法（接口）有机结合起来，再隐藏他们，只对外公开接口（函数）来和对象进行交互
//不想给别人看的，使用protected/private进行修饰，而开放一些公有函数对成员进行合理访问
//合理访问可以理解为阅读，不合理访问可以理解为改写（不准确的理解）
//stack.h
#include <iostream>
class Stack
{
public:
	void Init(int capacity);
private:
	int* _arr;
	int _length;
	int _capacity;
};
//stack.cpp
#include "Stack.h"
void Stack::Init(int capacity)
{
	_arr = (int*)malloc(sizeof(int) * capacity);
	_length = 0;
	_capacity = capacity;
}


//类的实例化
//test.cpp
#include <iostream>
#include "Stack.h"
int main()
{
	Stack s;
	s.Init(1145);

	return 0;
}

//面向对象与面向过程
//面向过程关注的是解决问题的步骤
//面向对象关注的是对象，将一个问题拆分为不同对象，依靠参数完成对象之间的交互
//面向过程正如雕版印刷、做数学题一样，一旦中间某个环节出现需求变更，那么整个工程几乎需要大改
//面向对象正如活字印刷，如果需求变化了，可能只是修改其中的一部分，也就是一个对象，而且最关键的一点是这些对象可以复用（被其他工程所用）


//类对象存储方式
//只保存成员变量，成员函数存放在公共的代码段（常量区）
//注：一般情况下，一个类的大小，实际就是该类中的成员变量和内存对齐。但要注意的是，空类大小是0，编译器为空类提供了一个字节表示它存在


//this指针
//引入
class Date
{
public:
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;
	Date d2;
	d1.SetDate(2021, 2, 20);
	d2.SetDate(2022, 8, 19);

	return 0;
}
//上述代码看似没有问题，但是很容易忽略一个细节，类中成员函数是公用的，它并不存在于类中，那么 d1.SetDate(2021, 2, 20); ，编译器怎么知道给d1这个类去设置
//而不会给d2去设置。这里可能会问：不是函数前面写了一个d1吗，这里大家一定要跳出这个误区，函数只是放在了公用的代码段，不知道函数的地址

//定义：
//C++编译器给每个非静态的成员函数增加了一个隐藏的指针参数，让该指针指向当前函数（函数运行时调用该函数的对象），在函数体中所有成员变量的操作，都是通过该指针访问
//完整代码应该是这样（不要这样写，会报错，这里只是演示）
class Date
{
public:
	void SetDate(Date* this,int year, int month, int day)
	{
		this->_year = year;
		this->_month = month;
		this->_day = day;//通过指针的指向来辨别对象
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;
	Date d2;
	d1.SetDate(&d1,2021, 2, 20);
	d2.SetDate(&d2,2022, 8, 19);//所以实参里，其实就是类的地址

	return 0;
}

