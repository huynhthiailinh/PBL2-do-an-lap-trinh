#pragma once
#include "Person.h"

class Teacher : public Person
{
private:
	int magiaovien;
	string noicongtac;
public:
	int getMaGiaoVien();
	string getNoiCongTac();
	Teacher();
	Teacher(int, string, string, string, string);
	~Teacher();
	void Xuat();
	//Teacher& operator=(const Teacher&);
};

