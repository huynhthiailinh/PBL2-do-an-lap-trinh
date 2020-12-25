#pragma once
#include "Person.h"
#include <string>

class Student : public Person
{
private:
	int mahocsinh;
public:
	int getMaHocSinh();
	Student();
	Student(int, string, string, string);
	~Student();
	void Nhap();
	void Xuat();
	Student& operator = (const Student&);
};

