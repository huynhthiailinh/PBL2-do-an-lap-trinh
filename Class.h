#pragma once
#include <iomanip>
#include <iostream>

using namespace std;

class Class
{
protected:
	int malophoc;
	int magiaovien;
	int mamonhoc;
	int malichhoc;
	int hocphi;
	string thoigianbatdau;
	string phonghoc;
	int soluong;
	int toida;
public:
	int getMaLopHoc();
	Class();
	Class(int, int, int, int, int, string, string, int, int);
	~Class();
	void Xuat();
};

