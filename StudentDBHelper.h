#pragma once
#include "DBHelper.h"
#include "Person.h"
#include "Student.h"
#include <vector>
class StudentDBHelper :public DBHelper
{
public:
	void LayDuLieu(vector<Student*>&);
	void XuatDuLieu(vector<Student*>&);
	void XuatHocSinhChuaDongHocPhi();
	void XoaDuLieu(vector<Student*>&);
	void ThemDuLieu();
	void CapNhatDuLieu();
	int TimKiemDulieu(vector<Student*>&, int);
	int TimKiemNhiPhan(vector<Student*>&, int);
	void updateHoVaTenHocSinh(const int&);
	void updateNgaySinhHocSinh(const int&);
	void updateSoDienThoaiHocSinh(const int&);
	void xemDanhSachHocSinhTheoMaLopHoc();
};

