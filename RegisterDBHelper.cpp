#include "RegisterDBHelper.h"

void RegisterDBHelper::LayDuLieu(vector<Register*>& LOP)
{
	DBHelper::init();
	system("cls");
	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT * FROM DANGKY", SQL_NTS))
	{
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else
	{
		//declare output variable and pointer
		SQLINTEGER ptrSqlVersion;
		int madangky; 
		int mahocsinh;
		int malophoc;
		char tinhtrang[20];
		int i = 0;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &madangky, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_INTEGER, &mahocsinh, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_INTEGER, &malophoc, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 4, SQL_CHAR, tinhtrang, sizeof(tinhtrang), &ptrSqlVersion);
			string tinhtrang_c(tinhtrang);
			Register* St = new Register(madangky, mahocsinh, malophoc, tinhtrang_c);
			LOP.push_back(St);
		}
	}
	SQLCancel(sqlStmtHandle);
	DBHelper::close();
}
void RegisterDBHelper::XoaDuLieu(vector<Register*>& LOP)
{

	int madangky;
	cout << "Nhap ma dang ky can huy dang ky:";
	cin >> madangky;
	DBHelper::init();
	string query = "DELETE FROM DANGKY WHERE madangky = " + to_string(madangky) + "";
	const char* SQLQuery = query.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)SQLQuery, SQL_NTS)) {
		cout << "\n";
		cout << "Du lieu khong chinh xac! Vui long thu lai!";
		cout << "\n";
		close();
	}
	else
	{
		cout << "Huy dang ky thanh cong!" << endl;
	}
	system("pause");
	DBHelper::close();
}
void RegisterDBHelper::CapNhatDuLieu()
{
	DBHelper::init();
	Register hs;
	cout << "Nhap thong tin can cap nhat" << endl;
	hs.Nhap();
	string query = "UPDATE DANGKY SET  mahocsinh = '" + to_string(hs.getMaHocSinh()) + "', malophoc = '" + to_string(hs.getMaLopHoc())
		+ "', tinhtrang = '" + hs.getTinhTrang() + "' WHERE madangky = " + to_string(hs.getMaDangKy());
	const char* SQLQuery = query.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)SQLQuery, SQL_NTS)) {
		cout << "\n";
		cout << "Cap nhat khong thanh cong!";
		cout << "\n";
		close();
	}
	else {
		cout << "Cap nhat thanh cong!" << endl;
		return;
	}
	DBHelper::close();
}
void RegisterDBHelper::DangKyHoc(Register& a)
{
	DBHelper::init();
	string query = "INSERT INTO DANGKY VALUES('" + to_string(a.getMaHocSinh()) + "','" + to_string(a.getMaLopHoc()) + "','" + a.getTinhTrang() + "')";
	const char* SQLQuery = query.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)SQLQuery, SQL_NTS))
	{
		cout << "\nDang ky khong thanh cong, vui long thu lai!" << endl;
		close();
	}
	else
	{
		cout << "\nBan Da Dang Ky Thanh Cong" << endl;
		return;
	}
	system("pause");
	DBHelper::close();
}
int  RegisterDBHelper::TimKiemDulieu(vector<Register*>& LOP, int a)
{
	system("cls");
	RegisterDBHelper::LayDuLieu(LOP);
	for (size_t i = 0; i < LOP.size(); i++)
	{
		if (LOP[i]->getMaDangKy() == a)
			return i;
	}
	return -1;
	DBHelper::close();
}
void  RegisterDBHelper::TimKiemMaHocSinh(vector<Register*>& LOP, int a)
{
	DBHelper::init();
	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"select * from dbo.function_xemTatCaDangKy()", SQL_NTS))
	{
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
		int z = 0;
		cout << setw(5) << "Ma DK" << "|" << setw(5) << "Ma HS" << "|"
			<< setw(25) << "Ten Hoc Sinh" << "|" << setw(5) << "MaLop" << "|"
			<< setw(5) << "Mon" << "|" << setw(5) << " Khoi" << "|"
			<< setw(5) << "Dong HP" << endl;
		cout << "==============================================================" << endl;

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
			if (mahocsinh == a)
			{
				cout << setw(5) << madangky << "|" << setw(5) << mahocsinh << "|"
					<< setw(25) << hovaten_c << "|" << setw(5) << malophoc << "|"
					<< setw(5) << tenmonhoc_c << "|" << setw(5) << khoilop << "|"
					<< setw(5) << tinhtrang_c << endl;
				z++;
			}
		}
		if (z == 0) cout << "Hoc sinh chua dang ky lop nao!" << endl;
	}
	system("pause");
	DBHelper::close();
}
void  RegisterDBHelper::XuatDuLieu(vector<Register*>& LOP)
{
	RegisterDBHelper::LayDuLieu(LOP);
	cout << setw(5) << "Ma DK" << "|" << setw(5) << "MaHS" << "|"
		<< setw(5) << "Ma Lop" << "|" << setw(5) << "Dong HP" << endl;
	for (size_t i = 0; i < LOP.size(); i++)
		LOP[i]->Xuat();
	DBHelper::close();
}
void RegisterDBHelper::XuatDanhSachDangKy(vector<Register*>& LOP)
{
	DBHelper::init();
	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"select * from dbo.function_xemTatCaDangKy()", SQL_NTS))
	{
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
			<< setw(25) << "Ten Hoc Sinh" << "|" << setw(5) << "MaLop" << "|" 
			<< setw(5) << "Mon" << "|" << setw(5) << " Khoi" << "|" 
			<< setw(5) << "Dong HP" << endl;
		cout << "==============================================================" << endl;

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
			cout << setw(5) << madangky << "|" << setw(5) << mahocsinh << "|" 
				<< setw(25) << hovaten_c << "|" << setw(5) << malophoc << "|"
				<< setw(5) << tenmonhoc_c << "|" << setw(5) << khoilop << "|"
				<< setw(5) << tinhtrang_c << endl;
		}
	}
	system("pause");
	DBHelper::close();
}
bool RegisterDBHelper::kiemTraMaHocSinhTonTai(int mahocsinh)
{
	DBHelper::init();
	string query = "select dbo.function_kiemTraMaHocSinhTonTai(" + to_string(mahocsinh) + ")";
	const char* SQLQuery = query.c_str();

	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)SQLQuery, SQL_NTS))
	{
		cout << "Error querying SQL Server";
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
			if (check == 1) return true;
			return false;
		}
	}
	DBHelper::close();
}
bool RegisterDBHelper::kiemTraMaLopHocTonTai(int malophoc)
{
	DBHelper::init();
	string query = "select dbo.function_kiemTraMaLopHocTonTai(" + to_string(malophoc) + ")";
	const char* SQLQuery = query.c_str();

	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)SQLQuery, SQL_NTS))
	{
		cout << "Error querying SQL Server";
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
			if (check == 1) return true;
			return false;
		}
	}
	DBHelper::close();
}
bool RegisterDBHelper::kiemTraSoLuong(int malophoc)
{
	DBHelper::init();
	string query = "select dbo.function_kiemTraSoLuong(" + to_string(malophoc) + ")";
	const char* SQLQuery = query.c_str();

	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)SQLQuery, SQL_NTS))
	{
		cout << "Error querying SQL Server";
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
			if (check == 1) return true;
			return false;
		}
	}
	DBHelper::close();
}
void RegisterDBHelper::CapNhatDuLieuTinhTrang(int a)
{
	DBHelper::init();
	system("cls");
	string query = "UPDATE DANGKY SET tinhtrang = '1' WHERE madangky = " + to_string(a) + "";
	const char* SQLQuery = query.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)SQLQuery, SQL_NTS)) {
		cout << "\n";
		cout << "Cap nhat khong thanh cong!";
		cout << "\n";
		close();
	}
	else {
		cout << "Cap nhat thanh cong!" << endl;
		return;
	}
	DBHelper::close();
}

void RegisterDBHelper::TongHocPhi()
{
	DBHelper::init();
	system("cls");
	string query = "select * from dbo.function_tinhTongHocPhi()";
	const char* SQLQuery = query.c_str();

	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)SQLQuery, SQL_NTS))
	{
		cout << "Error querying SQL Server";
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
			cout << "Tong hoc phi cua hoc sinh la: " << check << endl;
		}
	}
	system("pause");
	DBHelper::close();
}
void RegisterDBHelper::tinhTongHocPhiTheoMaLopHoc()
{
	int malop;
	cout << "Nhap ma lop hoc ban muon xem: ";
	cin >> malop;
	DBHelper::init();
	system("cls");
	string query = "select * from dbo.function_tinhTongHocPhiTheoMaLopHoc(" + to_string(malop) + ")";
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
			cout << "Tong hoc phi thu vao cua lop hoc co ma lop la " << malop << ": " << check << endl;
		}
	}
	system("pause");
	DBHelper::close();
}