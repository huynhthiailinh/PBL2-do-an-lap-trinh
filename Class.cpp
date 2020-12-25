#include "Class.h"

int Class::getMaLopHoc()
{
	return this->malophoc;
}
Class::Class()
{

}
Class::Class(int malophoc, int magiaovien, int mamonhoc, int malichhoc, int hocphi, string thoigianbatdau, string phonghoc, int soluong, int toida)
{
	this->malophoc = malophoc;
	this->magiaovien = magiaovien;
	this->mamonhoc = mamonhoc;
	this->malichhoc = malichhoc;
	this->hocphi = hocphi;
	this->thoigianbatdau = thoigianbatdau;
	this->phonghoc = phonghoc;
	this->soluong = soluong;
	this->toida = toida;
}
Class::~Class()
{

}
void Class::Xuat()
{
	cout << setw(5) << this->malophoc << "|" << setw(5) << this->magiaovien << "|"
		<< setw(5) << this->mamonhoc << "|" << setw(6) << this->malichhoc << "|"
		<< setw(10) << this->hocphi << "|" << setw(11) << this->thoigianbatdau << "|"
		<< setw(5) << this->phonghoc << "|" << setw(6) << this->soluong  << "|"
		<< setw(5) << this->toida << "|" << endl;
}

