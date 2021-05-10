#pragma once
#include <iostream>
using namespace std;
class Fio {
	char* surname;
	char* name;
	char* father;
public:
	friend class Clinic;
	friend ostream& operator<<(ostream& out, Fio& obj);
	friend istream& operator>>(istream& in, Fio& obj);

	Fio();
	Fio(const Fio& obj);
	~Fio();

	char* getSurname();
	char* getName();
	char* getFather();

	void setSurname(const char* surname);
	void setName(char* name);
	void setFather(char* father);
	void setFIO(char* surname, char* name, char* father);
};