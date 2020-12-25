#include "StudentDBHelper.h"
#include "Student.h"
#include <conio.h>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void StudentDBHelper::LayDuLieu(vector<Student*>& LOP)
{
	DBHelper::init();
	system("cls");
	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"select * from HOCSINH", SQL_NTS))
	{
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else
	{
		//declare output variable and pointer
		SQLINTEGER ptrSqlVersion;
		int mahocsinh;
		char hovaten[25];
		char ngaysinh[20];
		char dienthoai[20];
		int i = 0;

		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &mahocsinh, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, hovaten, sizeof(hovaten), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_CHAR, ngaysinh, sizeof(ngaysinh), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 4, SQL_CHAR, dienthoai, sizeof(dienthoai), &ptrSqlVersion);
			string hovaten_c(hovaten);
			string ngaysinh_c(ngaysinh);
			string dienthoai_c(dienthoai);
			Student* St = new Student(mahocsinh, hovaten_c, ngaysinh_c, dienthoai_c);
			LOP.push_back(St);
		}
	}
	SQLCancel(sqlStmtHandle);
	DBHelper::close();
}
void  StudentDBHelper::XuatDuLieu(vector<Student*>& LOP)
{
	StudentDBHelper::LayDuLieu(LOP);
	cout << setw(5) << "Ma" << "|" << setw(25) << "Ho va ten" << "|"
		<< setw(11) << "Ngay sinh" << "|" << setw(11) << "SDT" << endl;
	cout << "=======================================================" << endl;
	for (size_t i = 0; i < LOP.size(); i++)
		LOP[i]->Xuat();
	system("pause");
	DBHelper::close();
}
void StudentDBHelper::XuatHocSinhChuaDongHocPhi()
{
	DBHelper::init();
	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"select* from dbo.function_xemTatCaDangKy()", SQL_NTS))
	{
		//select* from dbo.function_xuatHocSinhChuaDongHocPhi()
		cout << "Error querying SQL Server" << endl;
		close();
	}
	else
	{
		//declare output variable and pointer
		SQLINTEGER ptrSqlVersion;
		int madangky;
		int mahocsinh;
		char hovaten[25];
		int malophoc;
		char tenmonhoc[5];
		int khoilop;
		char tinhtrang[5];
		cout << setw(5) << "Ma DK" << "|" << setw(5) << "Ma HS" << "|"
			<< setw(25) << "Ten Hoc Sinh" << "|" << setw(6) << "Ma lop" << "|"
			<< setw(5) << "Mon" << "|" << setw(5) << " Khoi" << "|"
			<< setw(5) << "Dong HP" << endl;
		cout << "=============================================================" << endl;
		int i=0;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
		{
			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &madangky, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_INTEGER, &mahocsinh, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_CHAR, hovaten, sizeof(hovaten), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 4, SQL_INTEGER, &malophoc, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 5, SQL_CHAR, tenmonhoc, sizeof(tenmonhoc), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 6, SQL_INTEGER, &khoilop, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 7, SQL_CHAR, tinhtrang, sizeof(tinhtrang), &ptrSqlVersion);
			string hovaten_c(hovaten);
			string tenmonhoc_c(tenmonhoc);
			string tinhtrang_c(tinhtrang);
			if (tinhtrang_c == "chua")
			{
				cout << setw(5) << madangky << "|" << setw(5) << mahocsinh << "|"
					<< setw(25) << hovaten_c << "|" << setw(6) << malophoc << "|"
					<< setw(5) << tenmonhoc_c << "|" << setw(5) << khoilop << "|"
					<< setw(5) << tinhtrang_c << endl;
				i++;
			}
		}
		if (i == 0) cout << "Tat ca hoc sinh da dong hoc phi!" << endl;
	}
	system("pause");
	DBHelper::close();
}
void StudentDBHelper::xemDanhSachHocSinhTheoMaLopHoc()
{
	int malop;
	cout << "Nhap ma lop hoc ban muon xem: ";
	cin >> malop;
	DBHelper::init();
	system("cls");
	string query = "select * from dbo.function_xemDanhSachHocSinhTheoMaLopHoc(" + to_string(malop) + ")";
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
		int mahocsinh;
		char hovaten[25];
		char ngaysinh[11];
		char dienthoai[11];
		char tinhtrang[5];
		cout << "Danh sach hoc sinh trong lop co ma lop hoc la " << malop << ":" << endl << "---" << endl;
		cout << setw(5) << "Ma HS" << "|" << setw(25) << "Ten hoc sinh" << "|"
			<< setw(11) << "Ngay sinh" << "|" << setw(11) << "SDT" << "|"
			<< setw(6) << "HocPhi" << endl;
		cout << "================================================================" << endl;
		int i = 0;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
		{
			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &mahocsinh, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, hovaten, sizeof(hovaten), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_CHAR, ngaysinh, sizeof(ngaysinh), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 4, SQL_CHAR, dienthoai, sizeof(dienthoai), &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 5, SQL_CHAR, tinhtrang, sizeof(tinhtrang), &ptrSqlVersion);
			string hovaten_c(hovaten);
			string ngaysinh_c(ngaysinh);
			string dienthoai_c(dienthoai);
			string tinhtrang_c(tinhtrang);

			cout << setw(5) << mahocsinh << "|" << setw(25) << hovaten_c << "|"
				<< setw(11) << ngaysinh_c << "|" << setw(11) << dienthoai_c << "|"
				<< setw(6) << tinhtrang_c << endl;
			i++;
		}
		if (i == 0) cout << "Khong tim thay du lieu!" << endl;
	}
	system("pause");
	DBHelper::close();
}
void StudentDBHelper::XoaDuLieu(vector<Student*>& LOP)
{
	DBHelper::init();
	int mahocsinh;
	cout << "Nhap ma hoc sinh can xoa: ";
	cin >> mahocsinh;
	string query = "DELETE FROM HOCSINH WHERE mahocsinh = " + to_string(mahocsinh);
	const char* SQLQuery = query.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)SQLQuery, SQL_NTS)) {
		cout << "\n";
		cout << "Ma hoc sinh can xoa khong ton tai!";
		cout << "\n";
		//close();
	}
	else {
		cout << "Da xoa thanh cong!" << endl;
		return;
	}
	system("pause");
	DBHelper::close();
}
void  StudentDBHelper::ThemDuLieu()
{
	Student s;
	s.Nhap();
	string query = "INSERT INTO HOCSINH VALUES('" + s.getHoVaTen() + "','" + s.getNgaySinh() + "','" + s.getDienThoai() + "')";
	const char* SQLQuery = query.c_str();
	DBHelper::init();
	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)SQLQuery, SQL_NTS))
	{
		cout << "\n";
		cout << "Du lieu dua vao khong chinh xac! Kiem tra lai.";
		cout << "\n";
		close();
	}
	else
	{
		cout << "\nBan da them thong tin thanh cong!" << endl;
		return;
	}
	system("pause");
	DBHelper::close();
}
void StudentDBHelper::CapNhatDuLieu()
{
	DBHelper::init();
	Student hs;
	int a;
	cout << "Nhap thong tin can cap nhat " << endl;
	cout << "Nhap ma hoc sinh can cap nhat: ";
	cin >> a;
	hs.Nhap();
	string query = "UPDATE HOCSINH SET hovaten = '" + hs.getHoVaTen() + "', ngaysinh = '" + hs.getNgaySinh()
		+ "', dienthoai = '" + hs.getDienThoai() + "' WHERE mahocsinh = " + to_string(a);
	const char* SQLQuery = query.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)SQLQuery, SQL_NTS)) {
		cout << "\n";
		cout << "Cap nhat du lieu khong thanh cong!";
		cout << "\n";
		close();
	}
	else {
		cout << endl << "Cap nhat du lieu thanh cong!" << endl;
		return;
	}
	DBHelper::close();
}
int  StudentDBHelper::TimKiemDulieu(vector<Student*>& LOP, int a)
{
	StudentDBHelper::LayDuLieu(LOP);
	system("cls");
	for (size_t i = 0; i < LOP.size(); i++)
	{
		if (LOP[i]->getMaHocSinh() == a)
		{
			cout << setw(5) << "Ma" << "|" << setw(25) << "Ho va ten" << "|"
				<< setw(11) << "Ngay sinh" << "|" << setw(11) << "SDT" << endl;
			return i;
		}
	}
	return -1;
	DBHelper::close();
}

void  StudentDBHelper::updateHoVaTenHocSinh(const int& c)
{
	string a;
	cin.ignore();
	cout << "\nNhap ho va ten moi: ";
	fflush(stdin);
	getline(cin, a);
	string query = "UPDATE HOCSINH SET hovaten = '" + a + "' WHERE mahocsinh = " + to_string(c)+ "";
	const char* SQLQuery = query.c_str();
	DBHelper::init();
	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)SQLQuery, SQL_NTS))
	{
		cout << "\nDu lieu dua vao khong chinh xac! Kiem tra lai.\n";
		close();
	}
	else
	{
		cout << "\nCap nhat ho va ten thanh cong!" << endl;
		return;
	}
	system("pause");
	DBHelper::close();
}

void StudentDBHelper::updateNgaySinhHocSinh(const int& c)
{
	string a;
	cout << "Nhap ngay sinh cua hoc sinh <YYYY-MM-DD>: ";
	cin >> a;
	string query = "UPDATE HOCSINH SET ngaysinh = '" + a + "' WHERE mahocsinh = " + to_string(c)+"";
	const char* SQLQuery = query.c_str();
	DBHelper::init();
	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)SQLQuery, SQL_NTS)) {
		cout << "\n";
		cout << "Du lieu dua vao khong chinh xac! Kiem tra lai.";
		cout << "\n";
		close();
	}
	else {
		cout << "\nCap nhat ngay sinh thanh cong!" << endl;
		return;
	}
	system("pause");
	DBHelper::close();
}

void StudentDBHelper::updateSoDienThoaiHocSinh(const int& c)
{
	string a;
	cout << "Nhap so dien thoai cua hoc sinh : ";
	cin >> a;
	string query = "UPDATE HOCSINH SET dienthoai = '" + a + "' WHERE mahocsinh = " + to_string(c);
	const char* SQLQuery = query.c_str();
	DBHelper::init();
	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)SQLQuery, SQL_NTS)) {
		cout << "\n";
		cout << "Du lieu dua vao khong chinh xac! Kiem tra lai.";
		cout << "\n";
		close();
	}
	else {
		cout << "\nCap nhat dien thoai thanh cong!" << endl;
		return;
	}
	system("pause");
	DBHelper::close();
}
int  StudentDBHelper::TimKiemNhiPhan(vector<Student*>& LOP, int a)
{
	StudentDBHelper::LayDuLieu(LOP);
		int right = LOP.size(); 

		int left = 0; 
		cout << setw(5) << "Ma" << "|" << setw(25) << "Ho va ten" << "|"
			<< setw(11) << "Ngay sinh" << "|" << setw(11) << "SDT" << endl;
		while (right >= left) 
		{
			int mid = left + (right - left) / 2; 
			if (LOP.at(mid)->getMaHocSinh() == a)
				return mid;
			if (LOP.at(mid)->getMaHocSinh() > a)
				right = mid - 1;
			if (LOP.at(mid)->getMaHocSinh() < a)
				left = mid + 1;
		}
		return -1;
	DBHelper::close();
}