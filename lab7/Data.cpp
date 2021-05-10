#define _CRT_SECURE_NO_WARNINGS
#include "Data.h"
#include "functions.h"
#include "Clinic.h"
#include <iostream>
#include <fstream>
#define path "data.txt"

using namespace std;

void loadData(deque<Clinic>& m, fstream& data)
{
	data.seekg(ios::beg);
	for (int i = 0; !data.eof(); i++)
	{
		char bufName[20], bufSurname[20], bufFather[20];
		int spec, qual;

		data >> bufSurname >> bufName >> bufFather >> spec >> qual;
		if (data.fail()) {
			cerr << "Ошибка чтения файла! Возможно база не загрузилась." << endl;
			return;
		}
			
		Clinic temp(bufSurname, bufName, bufFather, spec, qual);

		m.push_back(temp);
	}
	cout << "Файл успешно открыт!\n";
}
void createData(deque<Clinic>& m)
{
	int n;
	point:
	try {
		cout << "Введите кол-во позиций в базе: ";
		cin >> n;

		if (!cin) throw 0; // If n not int
	}
	catch (int err) {
		if (err == 0) {
			cerr << endl << "Поддерживаются только цифры! Повторите ввод..." << endl;
			cin.clear();
			cin.ignore(4096, '\n');
		}

		goto point;
	}

	for (int i = 0; i < n; i++)
	{
		cout << "\nВвод элемента базы номер:\n" << i + 1;
		addDoctor(m);
	}
}
void saveData(deque<Clinic> m, fstream& data)
{
	data.close();
	data.open(path, ios::out);
	data.seekg(ios::beg);

	if (!m.size()) return;

	data << m[0].getFIO().getSurname() << " "
		<< m[0].getFIO().getName() << " "
		<< m[0].getFIO().getFather() << " "
		<< m[0].getSpecialtyId() << " "
		<< m[0].getQualificationId();

	for (int i = 1; i < m.size(); i++)
	{
		data << endl 
			<< m[i].getFIO().getSurname() << " "
			<< m[i].getFIO().getName() << " "
			<< m[i].getFIO().getFather() << " "
			<< m[i].getSpecialtyId() << " "
			<< m[i].getQualificationId();
	}
}
