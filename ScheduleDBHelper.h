#pragma once
#include "DBHelper.h"
#include "Schedule.h"
#include <vector>

class ScheduleDBHelper :public DBHelper
{
public:
	void  LayDuLieu(vector<Schedule*>&);
	void  XuatDuLieu(vector<Schedule*>&);
	int  TimKiemDulieu(vector<Schedule*>&, int);
};

