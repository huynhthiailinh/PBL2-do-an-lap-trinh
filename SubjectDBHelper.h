#pragma once
#include "DBHelper.h"
#include "Subject.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class SubjectDBHelper : public DBHelper
{
public:
	void  LayDuLieu(vector<Subject*>&);
	void  XuatDuLieu(vector<Subject*>&);
	int  TimKiemDulieu(vector<Subject*>&, int);
};

