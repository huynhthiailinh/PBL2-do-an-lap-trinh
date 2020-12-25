#pragma once
#include "DBHelper.h"
#include "Class.h"
#include <conio.h>

#include <vector>
#include <iomanip>
#include <string>
#include <iostream>

using namespace std;

class ClassDBHelper : public DBHelper
{
public:
	void LayDuLieu(vector<Class*>&);
	int TimKiemDuLieu(vector<Class*>&, int);
	void xemTatCaLopHoc(vector<Class*>&);
	void xemLopHocTheoKhoiLop();
	void xemLopHocTheoMaGiaoVien();
	void xemLopHocConTrong();
	void xemLopHocTheoMaLopHoc();
};

