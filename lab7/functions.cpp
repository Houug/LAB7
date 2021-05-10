#define _CRT_SECURE_NO_WARNINGS

#include "functions.h"
#include <cstring>
#include <iostream>
#include <iomanip>
#include "Clinic.h"
#include <deque>
#include <algorithm>
using namespace std;

int checkInput(int n, int mode)
{
	if (checkInput()) {
		if (mode == 0)
		{
			switch (n)
			{
			case 1:
				return 0;
			case 2:
				return 0;
			case 3:
				return 0;
			default:
				return 1;
			}
		}
		if (mode == 1)
		{
			switch (n)
			{
			case 0:
				return 0;
			case 1:
				return 0;
			case 2:
				return 0;
			default:
				return 1;
			}
		}
	}
}
void printHeader()
{
	cout << "\n========================================================================\n"
		 << setw(40) << "Ф.И.О Врача" << setw(16) << "Cпециальность" << setw(16) << "Квалификация"
		 << "\n========================================================================\n";
}
void printMenu()
{
	cout << "\n\n***************Меню**************\n"
		 << "1 - Добавить врача в базу\n2 - Поиск врача по Ф.И.О\n3 - Поиск врачей по специальности и квалификации\n"
		 << "4 - Сортировка базы по алфавиту\n5 - Вывод базы с врачами\n6 - Удалить врача из начала базы\n7 - Выход из программы"
		 << "\n*********************************\n";
}
bool checkInput()
{
	if (!cin)
	{
		cerr << endl << "Ошибка ввода!" << endl;
		cin.clear();
		cin.ignore(4096, '\n');
		return true;
	}
	return false;
}
Clinic findDoctor(deque<Clinic> m)
{
	Fio temp;
	int count = 0;

	cout << "Поиск врача по Ф.И.О\n";
	cin >> temp;

	Clinic foundDoctor(temp.getSurname(), temp.getName(), temp.getFather(), -1, -1);

	for (int i = 0; i < m.size(); i++)
	{
		if (m[i] == foundDoctor.getFIO())
		{
			count++;
			foundDoctor = m[i];
			break;
		}
	}
	if (count == 0) cout <<  "Поиск не выдал результов\n";
	else
	{
		printHeader();
		cout << foundDoctor;
		return foundDoctor;
	}
}
void sortData(deque<Clinic>& m)
{
	for (int i = 0, min; i < m.size(); i++)
	{
		min = i;

		for (int j = i + 1; j < m.size(); j++)
		{
			if (m[min] > m[j])
			{
				min = j;
			}
		}

		swap(m[i], m[min]);
	}
}
void addDoctor(deque<Clinic>& m)
{
	int choose;
	Clinic temp;

	cin >> temp;

	

Point:
	try {
		cout << "Куда добавить? 0 - Начало, 1 - Конец" << endl;
		cin >> choose;
		getchar();

		if (!cin) throw 0; // If var choose not int
		if (!(choose == 0 || choose == 1)) throw  1; // If var choose not equal 0 or 1
	}
	catch (int err) {
		if (err == 0) {
			cerr << endl << "Поддерживаются только цифры! Повторите ввод..." << endl;
			cin.clear();
			cin.ignore(4096, '\n');
		}
		if (err == 1) {
			cerr << endl << "Только 0 или 1!" << endl;
		}
		goto Point;
	}

	if (choose) {
		m.push_back(temp);
	}
	else {
		m.push_front(temp);
	}
	
}
void printAll(deque<Clinic> m)
{
	if (m.size())
	{
		printHeader();
		for (int i = 0; i < m.size(); i++)
		{
			cout << m[i];
		}
	}
	else
	{
		cerr << "База данных пустая!" << endl;
	}
}
void removeFirstDoctor(deque<Clinic>& m)
{
	if (m.size()) m.pop_front();
	else cerr << "База данных пустая!" << endl;
}
void filterDoctor(deque<Clinic> oldArr, deque<Clinic>& newArr)
{
	int spec = 0, qual = 0;

	do
	{
		cout << "Введите специальность (1-3): ";
		cin >> spec;
	} while (checkInput(spec, 0));

	do
	{
		cout << "Введите квалификация (0-2): ";
		cin >> qual;
	} while (checkInput(qual, 1));

	for (int i = 0; i < oldArr.size(); i++)
	{
		if ((spec == oldArr[i].specialty) && (qual == oldArr[i].qualification))
		{
			newArr.push_back(oldArr[i]);
		}
	}
	if (newArr.size() == 0)
	{
		cout << "Поиск не выдал результов\n";
	}
}

istream& operator>>(istream& in, Clinic& obj)
{
	int spec, qual;
	bool check;

	cin >> obj.getFIO();

	do {
		try {
			cout << "Введите специальность (1-3): ";
			cin >> spec;

			if (!cin) throw 0; // If spec not int
			else if (!(spec == 1 || spec == 2 || spec == 3)) throw 1; // If spec not 1,2 or 3

			check = false;
		}
		catch (int err) {
			if (err == 0) {
				cerr << endl << "Поддерживаются только цифры! Повторите ввод..." << endl;
				cin.clear();
				cin.ignore(4096, '\n');
			}
			else if (err == 1) {
				cerr << endl << "Поддерживаются только цифры 1,2 или 3." << endl;
			}

			check = true;
		}
	} while (check);
	obj.setSpecialtyId(spec);

	do {
		try {
			cout << "Введите квалификация (0-2): ";
			cin >> qual;

			if (!cin) throw 0; // If qual not int
			else if (!(qual == 1 || qual == 2 || qual == 0)) throw 1; // If qual not 1,2 or 0

			check = false;
		}
		catch (int err) {
			if (err == 0) {
				cerr << endl << "Поддерживаются только цифры! Повторите ввод..." << endl;
				cin.clear();
				cin.ignore(4096, '\n');
			}
			else if (err == 1) {
				cerr << endl << "Поддерживаются только цифры 0,1 или 2." << endl;
			}

			check = true;
		}
	} while (check);
	obj.setQualificationId(qual);

	return in;
}
istream& operator>>(istream& in, Fio& obj)
{
	char buf[20];
	bool check;

	do {
		try {
			cout << "Введите фамилию: ";
			in.getline(buf, 20);

			for (int i = 0; i < strlen(buf); i++) {
				if (!isalpha(buf[i])) throw 1;
			}
			check = false;
		}
		catch (...) {
			cerr << endl << "Фамилия должна содержать только буквы!" << endl;
			check = true;
		}
	} while (check);
	obj.setSurname(buf);

	do {
		try {
			cout << "Введите имя: ";
			in.getline(buf, 20);

			for (int i = 0; i < strlen(buf); i++) {
				if (!isalpha(buf[i])) throw 1;
			}
			check = false;
		}
		catch (...) {
			cerr << endl << "Имя должно содержать только буквы!" << endl;
			check = true;
		}
	} while (check);
	obj.setName(buf);

	do {
		try {
			cout << "Введите отчество: ";
			in.getline(buf, 20);

			for (int i = 0; i < strlen(buf); i++) {
				if (!isalpha(buf[i])) throw 1;
			}
			check = false;
		}
		catch (...) {
			cerr << endl << "Имя должно содержать только буквы!" << endl;
			check = true;
		}
	} while (check);
	obj.setFather(buf);
}
ostream& operator<<(ostream& out, Fio& obj)
{
	char buf[60];
	strcpy(buf, obj.getSurname());
	strcat(buf, " ");
	strcat(buf, obj.getName());
	strcat(buf, " ");
	strcat(buf, obj.getFather());

	out << buf;
	return out;
}
ostream& operator<<(ostream& out, Clinic& obj)
{
	char specialty[11], qualification[7];

	switch (obj.getSpecialtyId())
	{
	case 1:
		strcpy(specialty, "Терапевт");
		break;
	case 2:
		strcpy(specialty, "Кардиолог");
		break;
	case 3:
		strcpy(specialty, "Стоматолог");
		break;
	default:
		strcpy(specialty, "NAN");
		break;
	}
	switch (obj.getQualificationId())
	{
	case 0:
		strcpy(qualification, "Высшая");
		break;
	case 1:
		strcpy(qualification, "Первая");
		break;
	case 2:
		strcpy(qualification, "Вторая");
		break;
	default:
		strcpy(qualification, "NAN");
		break;
	}

	out << setw(40) << obj.getFIO() << setw(16) << specialty << setw(16) << qualification << endl;
	return out;
}
