#include "Teacher.h"

int Teacher::getMaGiaoVien()
{
	return this->magiaovien;
}
string Teacher::getNoiCongTac()
{
	return this->noicongtac;
}
Teacher::Teacher() : Person()
{
	this->magiaovien = 0;
	this->noicongtac = "";
}
Teacher::Teacher(int magiaovien, string hovaten, string ngaysinh, string dienthoai, string noicongtac)
	: Person(string(hovaten), string(ngaysinh), string(dienthoai))
{
	this->magiaovien = magiaovien;
	this->noicongtac = noicongtac;
}
Teacher::~Teacher()
{

}
void Teacher::Xuat()
{
	cout << setw(5) << this->magiaovien << "|" << setw(25) << this->hovaten << "|" 
		<< setw(11) << this->ngaysinh << "|" << setw(11) << this->dienthoai << "|" << setw(20) << noicongtac << endl;
}
//Teacher& Teacher::operator=(const Teacher& tc)
//{
//	this->magiaovien = tc.magiaovien;
//	this->hovaten = tc.hovaten;
//	this->ngaysinh = tc.ngaysinh;
//	this->dienthoai = tc.dienthoai;
//	this->noicongtac = tc.noicongtac;
//	return *this;
//}

