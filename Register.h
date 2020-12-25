#pragma once
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

class Register
{
private:
	int madangky;
	int mahocsinh;
	int malophoc;
	string tinhtrang;
public:
	int getMaDangKy();
	void setMaDangKy(int);
	int getMaHocSinh();
	void setMaHocSinh(int);
	int getMaLopHoc();
	void setMaLopHoc(int);
	string getTinhTrang();
	void setTinhTrang(string);
	Register();
	Register(int madangky, int mahocsinh, int malophoc, string tinhtrang);
	~Register();
	void Nhap();
	void Xuat();
	bool operator!=(Register& rg);
};

