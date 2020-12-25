#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Subject
{
private:
	int mamonhoc;
	string tenmonhoc;
	int khoilop;
public:
	int getMaMonHoc();
	Subject();
	Subject(int, string, int);
	~Subject();
	void Xuat();
};

