#include "ScheduleDBHelper.h"
#include "Schedule.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void ScheduleDBHelper::LayDuLieu(vector<Schedule*>& LOP)
{
	DBHelper::init();
	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT * FROM LICHHOC", SQL_NTS))
	{
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else
	{
		//declare output variable and pointer
		SQLINTEGER ptrSqlVersion;
		int malichhoc;
		char ngayhoc[25];
		char giohoc[20];
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &malichhoc, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, ngayhoc, sizeof(ngayhoc), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_CHAR, giohoc, sizeof(giohoc), &ptrSqlVersion);
			string ngayhoc_c(ngayhoc);
			string giohoc_c(giohoc);
			Schedule* St = new Schedule(malichhoc, ngayhoc_c, giohoc_c);
			LOP.push_back(St);
		}
	}
	SQLCancel(sqlStmtHandle);
}
int  ScheduleDBHelper::TimKiemDulieu(vector<Schedule*>& LOP, int a)
{

	ScheduleDBHelper::LayDuLieu(LOP);
	for (int i = 0; i < LOP.size(); i++)
	{
		if (LOP[i]->getMaLichHoc() == a)
		{
			cout << setw(5) << "Ma" << "|" << setw(11) << "Ngay hoc" << "|"
				<< setw(11) << "Gio hoc" << endl;
			cout << "=============================" << endl;
			return i;
		}

	}
	return -1;
	DBHelper::close();
}
void  ScheduleDBHelper::XuatDuLieu(vector<Schedule*>& LOP)
{
	ScheduleDBHelper::LayDuLieu(LOP);
	cout << setw(5) << "Ma" << "|" << setw(11) << "Ngay hoc" << "|"
		<< setw(11) << "Gio hoc" << endl;
	cout << "=============================" << endl;
	for (int i = 0; i < LOP.size(); i++)
		LOP[i]->Xuat();
	system("pause");
	DBHelper::close();
}