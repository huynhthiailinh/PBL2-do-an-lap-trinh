#include "PrintMenu.h"
#include "Person.h"
#include "Student.h"
#include "StudentDBHelper.h"
#include "Register.h"
#include "RegisterDBHelper.h"
#include "Teacher.h"
#include "TeacherDBHelper.h"
#include "Schedule.h"
#include "ScheduleDBHelper.h"
#include "Subject.h"
#include "SubjectDBHelper.h"
#include "Class.h"
#include "ClassDBHelper.h"
#include <vector>

//use the std namespace
using namespace std;

int main()
{
	int choose;
	PrintMenu QuanLy;
	QuanLy.printTitle();
	do
	{
		QuanLy.printMenu();
		cin >> choose;
		switch (choose)
		{
		case 1: //thao tac voi hoc sinh
		{
			int choose1;
			do
			{
				QuanLy.printMenuStudent();
				vector<Student*> LIST1;
				StudentDBHelper a;
				RegisterDBHelper b;
				cin >> choose1;
				switch (choose1)
				{
				case 1: a.XuatDuLieu(LIST1); break; //Xem danh sach tat ca cac hoc sinh
				case 2: a.ThemDuLieu(); break; //Them 1 hoc sinh (ho va ten, ngay sinh, so dien thoai)
				case 3: a.XoaDuLieu(LIST1); break; //Xoa 1 hoc sinh theo ma hoc sinh
				case 4: { //Cap nhat thong tin cua hoc sinh theo ma hoc sinh
					int c;
					cout << "\nNhap ma hoc sinh can cap nhat: "; cin >> c;
					int i = a.TimKiemDulieu(LIST1, c);
					if (i != -1)
					{
						LIST1[i]->Xuat();
						int choose2;
						do
						{
							QuanLy.printMenuUpdateStudent();
							cin >> choose2;
							switch (choose2)
							{
							case 1: a.updateHoVaTenHocSinh(c); break; //Ho va ten hoc sinh
							case 2: a.updateNgaySinhHocSinh(c); break; //Ngay sinh hoc sinh
							case 3: a.updateSoDienThoaiHocSinh(c); break;
							default: break;
							}
						} while (choose2 != 0);
					}
					else cout << "Khong tim thay thong tin" << endl;
					system("pause");
				}break;
				case 5: {
					int c;
					cout << "Nhap ma hoc sinh can tim kiem: ";
					cin >> c;
					int i = a.TimKiemNhiPhan(LIST1, c);
					if (i != -1) LIST1.at(i)->Xuat();
					else cout << "Khong tim thay thong tin" << endl;
					system("pause");
				}break;
				case 6: {
					a.XuatHocSinhChuaDongHocPhi();
				}break;
				case 7: //xem danh sach hoc sinh theo ma lop hoc
				{
					a.xemDanhSachHocSinhTheoMaLopHoc(); break;
				}
				default:
					system("cls"); break;
				}
			} while (choose1 != 0);

		}break;
		case 2: //thao tac dang ky hoc
		{
			int choose1;
			do
			{
				QuanLy.printMenuRegister();
				vector<Register*> LIST1;
				RegisterDBHelper a;
				cin >> choose1;
				switch (choose1)
				{
				case 1: a.XuatDanhSachDangKy(LIST1); break;
				case 2:
				{
					int mahs, malh;
					Register dk;
					do //kiem tra ma hoc sinh co ton tai
					{
						cout << "\nNhap ma hoc sinh: ";
						cin >> mahs;
						if (!a.kiemTraMaHocSinhTonTai(mahs))
						{
							cout << "Ma hoc sinh khong ton tai." << endl;
						}
					} while (!a.kiemTraMaHocSinhTonTai(mahs));
					dk.setMaHocSinh(mahs);

					do//kiem tra ma lop hoc co ton tai
					{
						cout << "\nNhap ma lop hoc: ";
						cin >> malh;
						dk.setMaLopHoc(malh);
						if (!a.kiemTraMaLopHocTonTai(malh))
						{
							cout << "Ma lop hoc khong ton tai." << endl;
						}
					} while (!a.kiemTraMaLopHocTonTai(malh));
					dk.setMaLopHoc(malh);

					if (!a.kiemTraSoLuong(malh)) 
					{
						cout << "Lop hoc da het cho. Quay lai lan sau." << endl;
						break;
					}
					else
					{
						//nhap tinh trang hoc phi
						int phi;
						cout << "Da dong hoc phi? (1. Roi 0. Chua): ";
						cin >> phi;
						dk.setTinhTrang(to_string(phi));
					}

					a.DangKyHoc(dk);
				}break;
				case 3: a.XoaDuLieu(LIST1); break;
				case 4: {
					int c;
					cout << "Nhap ma dang ky de cap nhat: ";
					cin >> c;
					int i = a.TimKiemDulieu(LIST1, c);
					if (i != -1)
					{
						if (LIST1.at(i)->getTinhTrang() == "1")
						{
							cout << "Ban da dong hoc phi lop hoc nay!" << endl;
						}
						else
						{
							a.CapNhatDuLieuTinhTrang(c);
							cout << "Cap nhat tinh trang hoc phi thanh cong!" << endl;
						}
					}
					else cout << "Khong tim thay thong tin" << endl;
					system("pause");
				}break;
				case 5:
				{
					int mahs;
					cout << "Nhap ma hoc sinh can tim kiem: ";
					cin >> mahs;
					a.TimKiemMaHocSinh(LIST1, mahs);
				}
				break;
				case 6:
				{
					a.TongHocPhi();

				}break;
				case 7:
				{
					a.tinhTongHocPhiTheoMaLopHoc();
				}
				default:
					system("cls"); break;
				}
			} while (choose1 != 0);

		}break;
		case 3: //thong tin giao vien
		{
			int choose1;
			do
			{
				QuanLy.printMenuTeacher();
				vector<Teacher*> LIST2;
				TeacherDBHelper b;
				cin >> choose1;
				switch (choose1)
				{
				case 1: b.XuatDuLieu(LIST2); break;
				case 2:
				{
					int c;
					cout << "Nhap ma giao vien can tim kiem: ";
					cin >> c;
					int i = b.TimKiemDulieu(LIST2, c);
					if (i != -1) LIST2.at(i)->Xuat();
					else cout << "Khong tim thay thong tin" << endl;
					system("pause");
				}break;
				case 3:
				{
					b.thongKeMotGiaoVienDayBaoNhieuLop(); break;
				}
				default:
					system("cls"); break;
				}
			} while (choose1 != 0);

		}break;
		case 4:
		{
			int choose1;
			do
			{
				QuanLy.printMenuSchedule();
				vector<Schedule*> LIST2;
				ScheduleDBHelper b;
				cin >> choose1;
				switch (choose1)
				{
				case 1: b.XuatDuLieu(LIST2); break;
				case 2: {
					int c;
					cout << "Nhap ma lich hoc can tim kiem: ";
					cin >> c;
					int i = b.TimKiemDulieu(LIST2, c);
					if (i != -1) LIST2.at(i)->Xuat();
					else cout << "Khong tim thay thong tin" << endl;
					system("pause");
				}break;
				default:
					system("cls"); break;
				}
			} while (choose1 != 0);

		}break;
		case 5:
		{
			int choose1;
			do
			{
				QuanLy.printMenuSubject();
				vector<Subject*> LIST2;
				SubjectDBHelper b;
				cin >> choose1;
				switch (choose1)
				{
				case 1: b.XuatDuLieu(LIST2); break;
				case 2:
				{
					int c;
					cout << "Nhap ma mon hoc can tim kiem: ";
					cin >> c;
					int i = b.TimKiemDulieu(LIST2, c);
					if (i != -1) LIST2.at(i)->Xuat();
					else cout << "Khong tim thay thong tin" << endl;
					system("pause");
				}break;
				default:
					system("cls"); break;
				}
			} while (choose1 != 0);

		}break;
		case 6:
		{
			int choose1;
			do
			{
				QuanLy.printMenuClass();
				vector<Class*> LIST2;
				ClassDBHelper b;
				cin >> choose1;
				switch (choose1)
				{
				case 1: b.xemTatCaLopHoc(LIST2); break;
				case 2: b.xemLopHocTheoKhoiLop(); break;
				case 3: b.xemLopHocTheoMaGiaoVien(); break;
				case 4: b.xemLopHocConTrong(); break;
				case 5: b.xemLopHocTheoMaLopHoc(); break;
				case 6: {
					int c;
					cout << "Nhap ma lop hoc can tim kiem: ";
					cin >> c;
					int i = b.TimKiemDuLieu(LIST2, c);
					if (i != -1) LIST2.at(i)->Xuat();
					else cout << "Khong tim thay thong tin" << endl;
					system("pause");
				} break;
				default:
					system("cls"); break;
				}
			} while (choose1 != 0);

		}break;
		case 0:
		{
			cout << "------------------------------------" << endl;
			cout << "|      KET THUC CHUONG TRINH       |" << endl;
			cout << "------------------------------------" << endl;
		}	break;
		default:
			break;
		}
	} while (choose != 0);
	system("pause");
	return 0;
}