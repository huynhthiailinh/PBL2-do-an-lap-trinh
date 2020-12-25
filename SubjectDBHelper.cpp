#include "SubjectDBHelper.h"

void SubjectDBHelper::LayDuLieu(vector<Subject*>& LOP)
{
	DBHelper::init();
	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT * FROM MONHOC", SQL_NTS))
	{
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else
	{
		//declare output variable and pointer
		SQLINTEGER ptrSqlVersion;
		int mamonhoc;
		char tenmonhoc[25];
		int khoilop;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &mamonhoc, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, tenmonhoc, sizeof(tenmonhoc), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_INTEGER, &khoilop, sizeof(khoilop), &ptrSqlVersion);
			string tenmonhoc_c(tenmonhoc);
			Subject* St = new Subject(mamonhoc, tenmonhoc_c, khoilop);
			LOP.push_back(St);
		}
	}
	SQLCancel(sqlStmtHandle);
}
int  SubjectDBHelper::TimKiemDulieu(vector<Subject*>& LOP, int a)
{
	SubjectDBHelper::LayDuLieu(LOP);
	for (int i = 0; i < LOP.size(); i++)
	{
		if (LOP[i]->getMaMonHoc() == a)
		{
			cout << setw(5) << "Ma" << "|" << setw(5) << "Mon" << "|" << setw(5) << "Khoi" << endl;
			cout << "=================" << endl;
			return i;
		}
	}
	return -1;
	DBHelper::close();
}
void  SubjectDBHelper::XuatDuLieu(vector<Subject*>& LOP)
{
	SubjectDBHelper::LayDuLieu(LOP);
	cout << setw(5) << "Ma" << "|" << setw(5) << "Mon" << "|" << setw(5) << "Khoi" << endl;
	cout << "=================" << endl;
	for (int i = 0; i < LOP.size(); i++)
		LOP[i]->Xuat();
	system("pause");
	DBHelper::close();
}