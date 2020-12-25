#pragma once
#include <iomanip>
#include <string>
#include <iostream>

using namespace std;

class Person
{
protected:
	string hovaten;
	string ngaysinh;
	string dienthoai;
public:
	string getHoVaTen();
	void setHoVaTen(string);
	string getNgaySinh();
	void setNgaySinh(string);
	string getDienThoai();
	void setDienThoai(string);
	Person();
	Person(string, string, string);
	~Person();
	virtual void Nhap();
	virtual void Xuat();
};

