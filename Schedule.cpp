#include "Schedule.h"

int Schedule::getMaLichHoc()
{
	return this->malichhoc;
}
Schedule::Schedule()
{

}
Schedule::Schedule(int malichhoc, string ngayhoc, string giohoc)
{
	this->malichhoc = malichhoc;
	this->ngayhoc = ngayhoc;
	this->giohoc = giohoc;
}
Schedule::~Schedule()
{

}
void Schedule::Xuat()
{
	cout << setw(5) << this->malichhoc << "|" << setw(11) << this->ngayhoc << "|"
		<< setw(11) << this->giohoc << endl;
}

