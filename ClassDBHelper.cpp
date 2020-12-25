#include "ClassDBHelper.h"

void ClassDBHelper::LayDuLieu(vector<Class*>& lophoc)
{
	DBHelper::init();
	system("cls");
	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"select * from LOPHOC", SQL_NTS))
	{
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else
	{
		//declare output variable and pointer
		SQLINTEGER ptrSqlVersion;
		int malophoc;
		int magiaovien;
		int mamonhoc;
		int malichhoc;
		int hocphi;
		char thoigianbatdau[20];
		char phonghoc[5];
		int soluong;
		int toida;
		int i = 0;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &malophoc, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_INTEGER, &magiaovien, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_INTEGER, &mamonhoc, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 4, SQL_INTEGER, &malichhoc, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 5, SQL_INTEGER, &hocphi, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 6, SQL_CHAR, thoigianbatdau, sizeof(thoigianbatdau), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 7, SQL_CHAR, phonghoc, sizeof(phonghoc), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 8, SQL_INTEGER, &soluong, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 9, SQL_INTEGER, &toida, 1, &ptrSqlVersion);
			string thoigianbatdau_c(thoigianbatdau);
			string phonghoc_c(phonghoc);
			Class* St = new Class(malophoc, magiaovien, mamonhoc, malichhoc, hocphi, thoigianbatdau_c, phonghoc_c, soluong, toida);
			lophoc.push_back(St);
		}
	}
	SQLCancel(sqlStmtHandle);
}
int ClassDBHelper::TimKiemDuLieu(vector<Class*>& lophoc, int a)
{
	system("cls");
	ClassDBHelper::LayDuLieu(lophoc);
	for (size_t i=0; i<lophoc.size(); i++)
	{
		if (lophoc[i]->getMaLopHoc() == a)
		{
			cout << setw(5) << "MaLop" << "|" << setw(5) << "Ma GV" << "|"
				<< setw(5) << "MaMon" << "|" << setw(6) << "MaLich" << "|"
				<< setw(10) << "Hoc phi" << "|" << setw(11) << "ThGian BDau" << "|"
				<< setw(5) << "Phong" << "|" << setw(6) << "SLHTai" << "|"
				<< setw(5) << "SLTDa" << "|" << endl;
			return i;
		}
	}
	return -1;
	DBHelper::close();
}
void ClassDBHelper::xemTatCaLopHoc(vector<Class*>&)
{
	DBHelper::init();
	system("cls");
	string query = "select * from dbo.function_xemTatCaLopHoc()";
	const char* SQLQuery = query.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)SQLQuery, SQL_NTS))
	{
		cout << "Du lieu dua vao khong chinh xac! Kiem tra lai." << endl;
		cout << "\n";
		close();
	}
	else
	{
		//declare output variable and pointer
		SQLINTEGER ptrSqlVersion;
		int malophoc;
		char hovaten[50];
		char tenmonhoc[50];
		int khoilop;
		char ngayhoc[50];
		char giohoc[50];
		int hocphi;
		char thoigianbatdau[50];
		char phonghoc[5];
		int soluong;
		int toida;
		int i = 0;
		cout << setw(5) << "Ma" << "|" << setw(25) << "Ten giao vien" << "|"
			<< setw(5) << "Mon" << "|" << setw(5) << "Khoi" << "|"
			<< setw(11) << "Ngay hoc" << "|" << setw(11) << "Gio hoc" << "|"
			<< setw(10) << "Hoc phi" << "|" << setw(11) << "ThGian BDau" << "|"
			<< setw(5) << "Phong" << "|" << setw(6) << "SLHTai" << "|" 
			<< setw(5) << "SLTDa" << endl;
		cout << "=============================================================================================================" << endl;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
		{
			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &malophoc, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, hovaten, sizeof(hovaten), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_CHAR, tenmonhoc, sizeof(tenmonhoc), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 4, SQL_INTEGER, &khoilop, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 5, SQL_CHAR, ngayhoc, sizeof(ngayhoc), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 6, SQL_CHAR, giohoc, sizeof(giohoc), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 7, SQL_INTEGER, &hocphi, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 8, SQL_CHAR, thoigianbatdau, sizeof(thoigianbatdau), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 9, SQL_CHAR, phonghoc, sizeof(phonghoc), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 10, SQL_INTEGER, &soluong, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 11, SQL_INTEGER, &toida, 1, &ptrSqlVersion); 

			cout << setw(5) << malophoc << "|" << setw(25) << hovaten << "|" << setw(5) << tenmonhoc << "|" << setw(5) << khoilop << "|"
				<< setw(11) << ngayhoc << "|" << setw(11) << giohoc << "|" << setw(10) << hocphi << "|" << setw(11) << thoigianbatdau << "|"
				<< setw(5) << phonghoc << "|" << setw(6) << soluong << "|" << setw(5) << toida << endl;

			i++;
		}
		if (i == 0) cout << "Khong tim thay du lieu!" << endl;
	}
	system("pause");
	DBHelper::close();
}
void ClassDBHelper::xemLopHocTheoKhoiLop()
{
	int khoilop;
	cout << "Nhap khoi lop ban muon xem (10, 11, 12): ";	
	cin >> khoilop;
	DBHelper::init();
	system("cls");
	string query = "select * from dbo.function_xemLopHocTheoKhoiLop(" + to_string(khoilop) + ")";
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
		//declare output variable and pointer
		SQLINTEGER ptrSqlVersion;
		int malophoc;
		char hovaten[50];
		char tenmonhoc[50];
		int khoilop;
		char ngayhoc[50];
		char giohoc[50];
		int hocphi;
		char thoigianbatdau[50];
		char phonghoc[5];
		int soluong;
		int toida;
		int i = 0;
		cout << setw(5) << "Ma" << "|" << setw(25) << "Ten giao vien" << "|"
			<< setw(5) << "Mon" << "|" << setw(5) << "Khoi" << "|"
			<< setw(11) << "Ngay hoc" << "|" << setw(11) << "Gio hoc" << "|"
			<< setw(10) << "Hoc phi" << "|" << setw(11) << "ThGian BDau" << "|"
			<< setw(5) << "Phong" << "|" << setw(6) << "SLHTai" << "|"
			<< setw(5) << "SLTDa" << endl;
		cout << "=============================================================================================================" << endl;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
		{
			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &malophoc, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, hovaten, sizeof(hovaten), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_CHAR, tenmonhoc, sizeof(tenmonhoc), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 4, SQL_INTEGER, &khoilop, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 5, SQL_CHAR, ngayhoc, sizeof(ngayhoc), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 6, SQL_CHAR, giohoc, sizeof(giohoc), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 7, SQL_INTEGER, &hocphi, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 8, SQL_CHAR, thoigianbatdau, sizeof(thoigianbatdau), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 9, SQL_CHAR, phonghoc, sizeof(phonghoc), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 10, SQL_INTEGER, &soluong, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 11, SQL_INTEGER, &toida, 1, &ptrSqlVersion);

			cout << setw(5) << malophoc << "|" << setw(25) << hovaten << "|" << setw(5) << tenmonhoc << "|" << setw(5) << khoilop << "|"
				<< setw(11) << ngayhoc << "|" << setw(11) << giohoc << "|" << setw(10) << hocphi << "|" << setw(11) << thoigianbatdau << "|"
				<< setw(5) << phonghoc << "|" << setw(6) << soluong << "|" << setw(5) << toida << endl;
			i++;
		}
		if (i == 0) cout << "Khong tim thay du lieu!" << endl;
	}
	system("pause");
	DBHelper::close();
}
void ClassDBHelper::xemLopHocTheoMaGiaoVien()
{
	int magiaovien;
	cout << "Nhap ma giao vien can xem: ";
	cin >> magiaovien;
	DBHelper::init();
	string query = "select * from dbo.function_xemLopHocTheoMaGiaoVien(" + to_string(magiaovien) + ")";
	const char* SQLQuery = query.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)SQLQuery, SQL_NTS))
	{
		cout << "Du lieu dua vao khong chinh xac! Kiem tra lai." << endl;
		cout << "\n";
		close();
	}
	else
	{
		//declare output variable and pointer
		SQLINTEGER ptrSqlVersion;
		int malophoc;
		char hovaten[50];
		char tenmonhoc[50];
		int khoilop;
		char ngayhoc[50];
		char giohoc[50];
		int hocphi;
		char thoigianbatdau[50];
		char phonghoc[5];
		int soluong;
		int toida;
		int i = 0;
		cout << setw(5) << "Ma" << "|" << setw(25) << "Ten giao vien" << "|"
			<< setw(5) << "Mon" << "|" << setw(5) << "Khoi" << "|"
			<< setw(11) << "Ngay hoc" << "|" << setw(11) << "Gio hoc" << "|"
			<< setw(10) << "Hoc phi" << "|" << setw(11) << "ThGian BDau" << "|"
			<< setw(5) << "Phong" << "|" << setw(6) << "SLHTai" << "|"
			<< setw(5) << "SLTDa" << endl;
		cout << "=============================================================================================================" << endl;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
		{
			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &malophoc, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, hovaten, sizeof(hovaten), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_CHAR, tenmonhoc, sizeof(tenmonhoc), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 4, SQL_INTEGER, &khoilop, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 5, SQL_CHAR, ngayhoc, sizeof(ngayhoc), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 6, SQL_CHAR, giohoc, sizeof(giohoc), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 7, SQL_INTEGER, &hocphi, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 8, SQL_CHAR, thoigianbatdau, sizeof(thoigianbatdau), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 9, SQL_CHAR, phonghoc, sizeof(phonghoc), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 10, SQL_INTEGER, &soluong, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 11, SQL_INTEGER, &toida, 1, &ptrSqlVersion);

			cout << setw(5) << malophoc << "|" << setw(25) << hovaten << "|" << setw(5) << tenmonhoc << "|" << setw(5) << khoilop << "|"
				<< setw(11) << ngayhoc << "|" << setw(11) << giohoc << "|" << setw(10) << hocphi << "|" << setw(11) << thoigianbatdau << "|"
				<< setw(5) << phonghoc << "|" << setw(6) << soluong << "|" << setw(5) << toida << endl;
			i++;
		}
		if (i == 0) cout << "Khong tim thay du lieu!" << endl;
	}
	system("pause");
	DBHelper::close();
}
void ClassDBHelper::xemLopHocConTrong()
{
	DBHelper::init();
	system("cls");
	string query = "select * from dbo.function_xemLopHocConTrong()";
	const char* SQLQuery = query.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)SQLQuery, SQL_NTS))
	{
		cout << "Du lieu dua vao khong chinh xac! Kiem tra lai." << endl;
		cout << "\n";
		close();
	}
	else
	{
		//declare output variable and pointer
		SQLINTEGER ptrSqlVersion;
		int malophoc;
		char hovaten[50];
		char tenmonhoc[50];
		int khoilop;
		char ngayhoc[50];
		char giohoc[50];
		int hocphi;
		char thoigianbatdau[50];
		char phonghoc[5];
		int soluong;
		int toida;
		int i = 0;
		cout << setw(5) << "Ma" << "|" << setw(25) << "Ten giao vien" << "|"
			<< setw(5) << "Mon" << "|" << setw(5) << "Khoi" << "|"
			<< setw(11) << "Ngay hoc" << "|" << setw(11) << "Gio hoc" << "|"
			<< setw(10) << "Hoc phi" << "|" << setw(11) << "ThGian BDau" << "|"
			<< setw(5) << "Phong" << "|" << setw(6) << "SLHTai" << "|"
			<< setw(5) << "SLTDa" << endl;
		cout << "=============================================================================================================" << endl;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
		{
			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &malophoc, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, hovaten, sizeof(hovaten), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_CHAR, tenmonhoc, sizeof(tenmonhoc), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 4, SQL_INTEGER, &khoilop, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 5, SQL_CHAR, ngayhoc, sizeof(ngayhoc), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 6, SQL_CHAR, giohoc, sizeof(giohoc), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 7, SQL_INTEGER, &hocphi, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 8, SQL_CHAR, thoigianbatdau, sizeof(thoigianbatdau), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 9, SQL_CHAR, phonghoc, sizeof(phonghoc), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 10, SQL_INTEGER, &soluong, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 11, SQL_INTEGER, &toida, 1, &ptrSqlVersion);

			cout << setw(5) << malophoc << "|" << setw(25) << hovaten << "|" << setw(5) << tenmonhoc << "|" << setw(5) << khoilop << "|"
				<< setw(11) << ngayhoc << "|" << setw(11) << giohoc << "|" << setw(10) << hocphi << "|" << setw(11) << thoigianbatdau << "|"
				<< setw(5) << phonghoc << "|" << setw(6) << soluong << "|" << setw(5) << toida << endl;

			i++;
		}
		if (i == 0) cout << "Khong tim thay du lieu!" << endl;
	}
	system("pause");
	DBHelper::close();
}
void ClassDBHelper::xemLopHocTheoMaLopHoc()
{
	system("cls");
	int malophoc;
	cout << "Nhap ma lop hoc :";
	cin >> malophoc;
	DBHelper::init();
	string query = "select * from dbo.function_xemLopHocTheoMaLopHoc(" + to_string(malophoc) + ")";
	const char* SQLQuery = query.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)SQLQuery, SQL_NTS))
	{
		cout << "Du lieu dua vao khong chinh xac! Kiem tra lai." << endl;
		cout << "\n";
		close();
	}
	else
	{
		//declare output variable and pointer
		SQLINTEGER ptrSqlVersion;
		int malophoc;
		char hovaten[50];
		char tenmonhoc[50];
		int khoilop;
		char ngayhoc[50];
		char giohoc[50];
		int hocphi;
		char thoigianbatdau[50];
		char phonghoc[5];
		int soluong;
		int toida;
		int i = 0;
		cout << setw(5) << "Ma" << "|" << setw(25) << "Ten giao vien" << "|"
			<< setw(5) << "Mon" << "|" << setw(5) << "Khoi" << "|"
			<< setw(11) << "Ngay hoc" << "|" << setw(11) << "Gio hoc" << "|"
			<< setw(10) << "Hoc phi" << "|" << setw(11) << "ThGian BDau" << "|"
			<< setw(5) << "Phong" << "|" << setw(6) << "SLHTai" << "|"
			<< setw(5) << "SLTDa" << endl;
		cout << "=============================================================================================================" << endl;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
		{
			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &malophoc, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, hovaten, sizeof(hovaten), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_CHAR, tenmonhoc, sizeof(tenmonhoc), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 4, SQL_INTEGER, &khoilop, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 5, SQL_CHAR, ngayhoc, sizeof(ngayhoc), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 6, SQL_CHAR, giohoc, sizeof(giohoc), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 7, SQL_INTEGER, &hocphi, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 8, SQL_CHAR, thoigianbatdau, sizeof(thoigianbatdau), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 9, SQL_CHAR, phonghoc, sizeof(phonghoc), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 10, SQL_INTEGER, &soluong, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 11, SQL_INTEGER, &toida, 1, &ptrSqlVersion);

			cout << setw(5) << malophoc << "|" << setw(25) << hovaten << "|" << setw(5) << tenmonhoc << "|" << setw(5) << khoilop << "|"
				<< setw(11) << ngayhoc << "|" << setw(11) << giohoc << "|" << setw(10) << hocphi << "|" << setw(11) << thoigianbatdau << "|"
				<< setw(5) << phonghoc << "|" << setw(6) << soluong << "|" << setw(5) << toida << endl;
			i++;
		}
		if (i == 0) cout << "Khong tim thay du lieu!" << endl;
	}
	system("pause");
	DBHelper::close();
}

