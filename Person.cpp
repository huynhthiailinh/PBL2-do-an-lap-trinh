#include "Person.h"

Person::Person()
{

}
Person::Person(string hovaten, string ngaysinh, string dienthoai)
{
	this->hovaten = hovaten;
	this->ngaysinh = ngaysinh;
	this->dienthoai = dienthoai;
}
Person::~Person()
{

}
string Person::getHoVaTen()
{
	return this->hovaten;
}
void Person::setHoVaTen(string hovaten)
{
	this->hovaten = hovaten;
}
string Person::getNgaySinh()
{
	return this->ngaysinh;
}
void Person::setNgaySinh(string ngaysinh)
{
	this->ngaysinh = ngaysinh;
}
string Person::getDienThoai()
{
	return this->dienthoai;
}
void Person::setDienThoai(string dienthoai)
{
	this->dienthoai = dienthoai;
}
void Person::Nhap()
{
	cout << "Nhap ho va ten:" << endl;
	fflush(stdin);
	getline(cin, this->hovaten);
	cout << "Nhap ngay sinh:" << endl;
	fflush(stdin);
	getline(cin, this->ngaysinh);
	cout << "Nhap so dien thoai:" << endl;
	fflush(stdin);
	getline(cin, this->dienthoai);
}
void Person::Xuat()
{
	cout << setw(5) << "Ma" << "|" << setw(25) << "Ho va ten" << "|" 
		<< setw(11) << "Ngay sinh" << "|" << setw(11) << "So dien thoai" << endl;
	cout << "===================================================" << endl;
	cout << setw(30) << this->hovaten << "|" << setw(11) << this->ngaysinh << "|"
		<< setw(11) << this->dienthoai << endl;
}

