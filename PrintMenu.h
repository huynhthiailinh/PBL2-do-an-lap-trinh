#pragma once
#include <iostream>

using namespace std;

class PrintMenu
{
public:
	void printTitle()
	{
		cout << "----------------------------------------------------------------------------" << endl;
		cout << "|      Dai hoc Bach Khoa - Dai hoc Da Nang - khoa Cong Nghe Thong Tin      |" << endl;
		cout << "|                             Do an lap trinh                              |" << endl;
		cout << "|       De tai: Quan ly hoc sinh tai mot trung tam day them cap THPT       |" << endl;
		cout << "|          Sinh vien thuc hien: PHAN VAN BINH, HUYNH THI AI LINH           |" << endl;
		cout << "|                          Nhom hoc phan: 19.14B                           |" << endl;
		cout << "|          Giang vien huong dan: Do Thi Tuyet Hoa, Phan Chi Tung           |" << endl;
		cout << "----------------------------------------------------------------------------" << endl;
	}
	void printMenu()
	{
		cout << "----------------------------------------" << endl;
		cout << "|                  MENU                |" << endl;
		cout << "|  1. Thao tac voi thong tin hoc sinh  |" << endl;
		cout << "|  2. Thao tac voi dang ky hoc         |" << endl;
		cout << "|  3. Thong tin giao vien              |" << endl;
		cout << "|  4. Thong tin lich hoc               |" << endl;
		cout << "|  5. Thong tin mon hoc                |" << endl;
		cout << "|  6. Thong tin lop hoc                |" << endl;
		cout << "|  0. Ket thuc                         |" << endl;
		cout << "----------------------------------------" << endl;
		cout << "Hay nhap lua chon: ";
	}
	void printMenuStudent()
	{
		cout << "-------------------------------------------------------------" << endl;
		cout << "|                       MENU STUDENT                        |" << endl;
		cout << "|  1. Xem danh sach tat ca cac hoc sinh                     |" << endl;
		cout << "|  2. Them 1 hoc sinh (ho va ten, ngay sinh, so dien thoai) |" << endl;
		cout << "|  3. Xoa 1 hoc sinh theo ma hoc sinh                       |" << endl;
		cout << "|  4. Cap nhat thong tin cua hoc sinh theo ma hoc sinh      |" << endl;
		cout << "|  5. Tim kiem thong tin cua hoc sinh theo ma hoc sinh      |" << endl;
		cout << "|  6. Xem danh sach hoc sinh chua dong hoc phi              |" << endl;
		cout << "|  7. Xem danh sach hoc sinh theo ma lop hoc                |" << endl;
		cout << "|  0. Quay lai menu truoc                                   |" << endl;
		cout << "-------------------------------------------------------------" << endl;
		cout << "Hay nhap lua chon: ";
	}
	void printMenuSubject()
	{
		cout << "-------------------------------------------------------------" << endl;
		cout << "|                       MENU SUBJECT                        |" << endl;
		cout << "|  1. Xem danh sach tat ca cac mon hoc                      |" << endl;
		cout << "|  2. Tim kiem thong tin cua theo ma mon hoc                |" << endl;
		cout << "|  0. Quay lai menu truoc                                   |" << endl;
		cout << "-------------------------------------------------------------" << endl;
		cout << "Hay nhap lua chon: ";
	}
	void printMenuTeacher()
	{
		cout << "-------------------------------------------------------------" << endl;
		cout << "|                      MENU TEACHER                         |" << endl;
		cout << "|  1. Xem danh sach tat ca cac giao vien                    |" << endl;
		cout << "|  2. Tim kiem thong tin cua theo ma giao vien              |" << endl;
		cout << "|  3. Thong ke 1 giao vien day bao nhieu lop                |" << endl;
		cout << "|  0. Quay lai menu truoc                                   |" << endl;
		cout << "-------------------------------------------------------------" << endl;
		cout << "Hay nhap lua chon: ";
	}
	void printMenuSchedule()
	{
		cout << "-------------------------------------------------------------" << endl;
		cout << "|                      MENU SCHEDULE                        |" << endl;
		cout << "|  1. Xem danh sach tat ca cac lich hoc                     |" << endl;
		cout << "|  2. Tim kiem thong tin theo ma lich hoc                   |" << endl;
		cout << "|  0. Quay lai menu truoc                                   |" << endl;
		cout << "-------------------------------------------------------------" << endl;
		cout << "Hay nhap lua chon: ";
	}
	void printMenuUpdateStudent()
	{
		cout << "--------------------------------------" << endl;
		cout << "|         MENU UPDATE STUDENT        |" << endl;
		cout << "|  Ban muon cap nhat thong tin nao?  |" << endl;
		cout << "|  1. Ho va ten hoc sinh             |" << endl;
		cout << "|  2. Ngay sinh hoc sinh             |" << endl;
		cout << "|  3. So dien thoai hoc sinh         |" << endl;
		cout << "|  0. Quay lai menu truoc            |" << endl;
		cout << "--------------------------------------" << endl;
		cout << "Hay nhap lua chon: ";
	}
	void printMenuRegister()
	{
		cout << "------------------------------------------------------------------" << endl;
		cout << "|                      MENU REGISTER                             |" << endl;
		cout << "|  1. Xem danh sach tat ca cac dang ky hoc                       |" << endl;
		cout << "|  2. Dang ky hoc (ma hoc sinh, ma lop hoc, tinh trang hoc phi)  |" << endl;
		cout << "|  3. Huy dang ky hoc theo ma dang ky                            |" << endl;
		cout << "|  4. Cap nhat tinh trang da dong hoc phi theo ma dang ky        |" << endl;
		cout << "|  5. Tim kiem hoc sinh trong danh sach dang ky theo ma hoc sinh |" << endl;
		cout << "|  6. Hoc phi thu duoc tu khoa hoc                               |" << endl;
		cout << "|  7. Tinh hoc phi thu duoc theo ma lop hoc                      |" << endl;
		cout << "|  0. Quay lai menu truoc                                        |" << endl;
		cout << "------------------------------------------------------------------" << endl;
		cout << "Hay nhap lua chon : ";
	}
	void printMenuClass()
	{
		cout << "--------------------------------" << endl;
		cout << "|          MENU CLASS          |" << endl;
		cout << "| Xuat danh sach lop hoc theo? |" << endl;
		cout << "|  1. Tat ca lop hoc hien tai  |" << endl; //
		cout << "|  2. Theo khoi lop            |" << endl; //
		cout << "|  3. Theo ma giao vien        |" << endl; //
		cout << "|  4. Cac lop con trong        |" << endl; //
		cout << "|  5. Theo ma lop hoc          |" << endl;
		cout << "|  6. Tim kiem theo ma lop hoc |" << endl; //
		cout << "|  0. Quay lai menu truoc      |" << endl;
		cout << "--------------------------------" << endl;
		cout << "Hay nhap lua chon: ";
	}
};