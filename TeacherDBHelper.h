#pragma once
#include "DBHelper.h"
#include "Person.h"
#include "Teacher.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>

using namespace std;

class TeacherDBHelper : public DBHelper
{
public:
	void LayDuLieu(vector<Teacher*>&);
	void XuatDuLieu(vector<Teacher*>&);
	int TimKiemDulieu(vector<Teacher*>&, int);
	void thongKeMotGiaoVienDayBaoNhieuLop();
};

