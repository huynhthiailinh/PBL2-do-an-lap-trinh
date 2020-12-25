#pragma once
#include "DBHelper.h"
#include "Register.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include <vector>

using namespace std;

class RegisterDBHelper :public DBHelper
{
public:
	void LayDuLieu(vector<Register*>&);
	void XuatDuLieu(vector<Register*>&);
	void XoaDuLieu(vector<Register*>&);
	void DangKyHoc(Register&);
	void CapNhatDuLieu();
	void CapNhatDuLieuTinhTrang(int);
	int TimKiemDulieu(vector<Register*>&, int);
	void TimKiemMaHocSinh(vector<Register*>&, int);
	bool kiemTraMaHocSinhTonTai(int mahocsinh);
	bool kiemTraMaLopHocTonTai(int malophoc);
	bool kiemTraSoLuong(int malophoc);
	void XuatDanhSachDangKy(vector<Register*>&);
	void TongHocPhi();
	void tinhTongHocPhiTheoMaLopHoc();
};

