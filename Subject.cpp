#include "Subject.h"

int Subject::getMaMonHoc()
{
	return this->mamonhoc;
}
Subject::Subject()
{

}
Subject::Subject(int mamonhoc, string tenmonhoc, int khoilop)
{
	this->mamonhoc = mamonhoc;
	this->tenmonhoc = tenmonhoc;
	this->khoilop = khoilop;
}
Subject::~Subject()
{

}
void Subject::Xuat()
{
	cout << setw(5) << this->mamonhoc << "|" << setw(5) << this->tenmonhoc << "|"
		<< setw(5) << this->khoilop << endl;
}