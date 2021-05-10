#define _CRT_SECURE_NO_WARNINGS
#include "Clinic.h"
#include "Fio.h"
#include "functions.h"
#include <string.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <deque>
using namespace std;

Clinic::Clinic()
{
	this->specialty = -1;
	this->qualification = -1;
}
Clinic::Clinic(char* surname, char* name, char* father, int spec, int qual)
{
	this->getFIO().setFIO(surname, name, father);
	this->specialty = spec;
	this->qualification = qual;
}
Clinic::Clinic(const Clinic& obj)
{
	this->getFIO().setFIO(obj.fio.surname, obj.fio.name, obj.fio.father);
	this->specialty = obj.specialty;
	this->qualification = obj.qualification;
}
Clinic::~Clinic()
{
}

Fio& Clinic::getFIO()
{
	return fio;
}

int Clinic::getSpecialtyId()
{
	return this->specialty;
}
int Clinic::getQualificationId()
{
	return this->qualification;
}

void Clinic::setSpecialtyId(int spec)
{
	this->specialty = spec;
}

void Clinic::setQualificationId(int qual)
{
	this->qualification = qual;
}

bool Clinic::operator==(Fio& obj)
{
	if (strcmp(this->getFIO().getSurname(), obj.getSurname()) == 0 &&
		strcmp(this->getFIO().getName(), obj.getName()) == 0 &&
		strcmp(this->getFIO().getFather(), obj.getFather()) == 0)
		return true;
	else return false;
}
Clinic& Clinic::operator=(Clinic obj)
{
	this->getFIO().setSurname(obj.getFIO().getSurname());
	this->getFIO().setName(obj.getFIO().getName());
	this->getFIO().setFather(obj.getFIO().getFather());
	this->setQualificationId(obj.getQualificationId());
	this->setSpecialtyId(obj.getSpecialtyId());

	return *this;
}

bool Clinic::operator>(Clinic& obj)
{
	char bufMin[60], bufMax[60];

	strcpy(bufMin, obj.getFIO().getSurname());
	strcat(bufMin, " ");
	strcat(bufMin, obj.getFIO().getName());
	strcat(bufMin, " ");
	strcat(bufMin, obj.getFIO().getFather());

	strcpy(bufMax, this->getFIO().getSurname());
	strcat(bufMax, " ");
	strcat(bufMax, this->getFIO().getName());
	strcat(bufMax, " ");
	strcat(bufMax, this->getFIO().getFather());

	if (strcmp(bufMax, bufMin) > 0) {
		return true;
	}
	else return false;
}
bool Clinic::operator<(Clinic& obj)
{
	char bufMin[60], bufMax[60];

	strcpy(bufMin, obj.getFIO().getSurname());
	strcat(bufMin, " ");
	strcat(bufMin, obj.getFIO().getName());
	strcat(bufMin, " ");
	strcat(bufMin, obj.getFIO().getFather());

	strcpy(bufMax, this->getFIO().getSurname());
	strcat(bufMax, " ");
	strcat(bufMax, this->getFIO().getName());
	strcat(bufMax, " ");
	strcat(bufMax, this->getFIO().getFather());

	if (strcmp(bufMax, bufMin) < 0) {
		return true;
	}
	else return false;
}
