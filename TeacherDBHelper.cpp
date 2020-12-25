#include "TeacherDBHelper.h"

void TeacherDBHelper::LayDuLieu(vector<Teacher*>& LOP)
{
	DBHelper::init();
	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT * FROM GIAOVIEN", SQL_NTS))
	{
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else
	{
		//declare output variable and pointer
		SQLINTEGER ptrSqlVersion;
		int  magiaovien;
		char hovaten[30];
		char ngaysinh[20];
		char dienthoai[20];
		char noicongtac[50];
		int i = 0;

		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &magiaovien, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, hovaten, sizeof(hovaten), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_CHAR, ngaysinh, sizeof(ngaysinh), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 4, SQL_CHAR, dienthoai, sizeof(dienthoai), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 5, SQL_CHAR, noicongtac, sizeof(noicongtac), &ptrSqlVersion);
			string hovaten_c(hovaten);
			string ngaysinh_c(ngaysinh);
			string dienthoai_c(dienthoai);
			string noicongtac_c(noicongtac);
			Teacher* TS = new Teacher(magiaovien, hovaten_c, ngaysinh_c, dienthoai_c, noicongtac_c);
			LOP.push_back(TS);
		}
	}
	SQLCancel(sqlStmtHandle);
	DBHelper::close();
}
int  TeacherDBHelper::TimKiemDulieu(vector<Teacher*>& LOP, int a)
{
	TeacherDBHelper::LayDuLieu(LOP);
	system("cls");
	for (size_t i = 0; i < LOP.size(); i++)
	{
		if (LOP[i]->getMaGiaoVien() == a)
		{
			cout << setw(5) << "Ma" << "|" << setw(25) << "Ho va ten" << "|"
				<< setw(11) << "Ngay sinh" <<"|" << setw(11) << "SDT" << "|"
				<< setw(20) << "Noi cong tac" << endl;
			cout << "============================================================================" << endl;
			return i;
		}
	}
	return -1;
	DBHelper::close();
}
void  TeacherDBHelper::XuatDuLieu(vector<Teacher*>& LOP)
{
	TeacherDBHelper::LayDuLieu(LOP);
	cout << setw(5) << "Ma" << "|" << setw(25) << "Ho va ten" << "|"
		<< setw(11) << "Ngay sinh" << "|" << setw(11) << "SDT" <<"|"
		<< setw(20) << "Noi cong tac" << endl;
	cout << "============================================================================" << endl;
	for (size_t i = 0; i < LOP.size(); i++)
		LOP[i]->Xuat();
	system("pause");
	DBHelper::close();
}

void TeacherDBHelper::thongKeMotGiaoVienDayBaoNhieuLop()
{
	int magv;
	cout << "Nhap ma giao vien muon xem: ";
	cin >> magv;
	DBHelper::init();
	string query = "select * from dbo.function_thongKeMotGiaoVienDayBaoNhieuLop(" + to_string(magv) + ")";
	const char* SQLQuery = query.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle,
		(SQLCHAR*)SQLQuery,
		SQL_NTS))
	{
		cout << "Du lieu dua vao khong chinh xac! Kiem tra lai." << endl;
		cout << "\n";
		close();
	}
	else
	{
		SQLINTEGER ptrSqlVersion;
		int check;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
		{
			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &check, 1, &ptrSqlVersion);
			cout << "Giao vien co ma giao vien la " << magv << " day " << check << " lop!" << endl;
		}
	}
	system("pause");
	DBHelper::close();
}

