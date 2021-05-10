#pragma once
#include "Fio.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <deque>
using namespace std;
class Clinic {
	Fio fio;
	int specialty;
	int qualification;
public:

	friend Clinic findDoctor(deque<Clinic> m);
	friend void filterDoctor(deque<Clinic> oldArr, deque<Clinic>& newArr);
	friend istream& operator>> (istream& in, Clinic& obj);
	friend ostream& operator<<(ostream& out, Clinic& obj);

	Clinic();
	Clinic(char* surname, char* name, char* father, int spec, int qual);
	Clinic(const Clinic& obj);
	~Clinic();
	
	Fio& getFIO();

	int getSpecialtyId();
	int getQualificationId();

	void setSpecialtyId(int spec);
	void setQualificationId(int qual);

	bool operator== (Fio& obj);
	bool operator> (Clinic& obj);
	bool operator< (Clinic& obj);
	Clinic& operator=(Clinic obj);
};