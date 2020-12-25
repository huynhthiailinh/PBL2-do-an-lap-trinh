#pragma once
#include <iomanip>
#include <iostream>

using namespace std;

class Schedule
{
private:
	int malichhoc;
	string ngayhoc;
	string giohoc;
public:
	int getMaLichHoc();
	Schedule();
	Schedule(int, string, string);
	~Schedule();
	void Xuat();

};

