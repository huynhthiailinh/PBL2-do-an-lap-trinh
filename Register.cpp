#include "Register.h"
int Register::getMaDangKy()
{
	return this->madangky;
}
void Register::setMaDangKy(int madangky)
{
	this->madangky = madangky;
}
int Register::getMaHocSinh()
{
	return this->mahocsinh;
}
void Register::setMaHocSinh(int mahocsinh)
{
	this->mahocsinh = mahocsinh;
}
int Register::getMaLopHoc()
{
	return this->malophoc;
}
void Register::setMaLopHoc(int malophoc)
{
	this->malophoc = malophoc;
}
string Register::getTinhTrang()
{
	return this->tinhtrang;
}
void Register::setTinhTrang(string tinhtrang)
{
	this->tinhtrang = tinhtrang;
}
Register::Register()
{

}
Register::Register(int madangky, int mahocsinh, int malophoc, string tinhtrang)
{
	this->madangky = madangky;
	this->mahocsinh = mahocsinh;
	this->malophoc = malophoc;
	this->tinhtrang = tinhtrang;
}
Register::~Register()
{

}
void Register::Nhap()
{
	cout << "Nhap ma hoc sinh: ";
	cin >> this->mahocsinh;
	cout << "Nhap ma lop hoc: ";
	cin >> this->malophoc;
	cout << "Nhap tinh trang hoc phi (1. Da dong 0. Chua dong): ";
	fflush(stdin);
	getline(cin, this->tinhtrang);
}
void Register::Xuat()
{
	cout << setw(5) << this->madangky << "|" << setw(5) << this->mahocsinh << "|"
		<< setw(5) << this->malophoc << "|" << setw(5);
	if(this->tinhtrang.compare("0")) cout << "DA DONG" << endl;
	else cout << "CHUA DONG" << endl;
}
bool Register::operator!=(Register& rg)
{
	if (madangky != rg.madangky)
		return true;
	return false;
}

