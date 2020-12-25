#include "Student.h"

int Student::getMaHocSinh()
{
	return this->mahocsinh;
}
Student::Student()
	: Person()
{
	this->mahocsinh = 0;
}
Student::Student(int mahocsinh, string hovaten, string ngaysinh, string dienthoai)
	: Person(string(hovaten), string(ngaysinh), string(dienthoai))
{
	this->mahocsinh = mahocsinh;
}
Student::~Student()
{

}
void Student::Nhap()
{
	cin.ignore();
	cout << "Nhap ho va ten: ";
	fflush(stdin);
	getline(cin, this->hovaten);
	cout << "Nhap ngay sinh <yyyy-mm-dd>: ";
	fflush(stdin);
	getline(cin, this->ngaysinh);
	cout << "Nhap so dien thoai: ";
	fflush(stdin);
	getline(cin, this->dienthoai);
}
void Student::Xuat()
{
	cout << setw(5) << this->mahocsinh << "|" << setw(25) << this->hovaten 
		<< "|" << setw(11) << this->ngaysinh << "|" << setw(11) << this->dienthoai << endl;
}
Student& Student::operator=(const Student& st)
{
	this->mahocsinh = st.mahocsinh;
	this->hovaten = st.hovaten;
	this->ngaysinh = st.ngaysinh;
	this->dienthoai = st.dienthoai;
	return *this;
}

