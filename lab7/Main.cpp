#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <fstream>
#include "Clinic.h"
#include "functions.h"
#include "Data.h"

#include <deque>
#include <algorithm>

#define path "data.txt"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	// Block of variables
	fstream data;

	deque<Clinic> arr;
	deque<Clinic> foundDoctors;

	int menu, count = 0;

	// Load/create database
	data.open(path);
	if (!data.is_open())
	{
		cout << "Файл не открылся!" << endl;
		data.open(path, fstream::app);
		if (data.is_open())
		{
			cout << "Создание нового файла!" << endl;
			createData(arr);
		}
		else
		{
			cout << "Обратитесь к администратору!" << endl;
			return 0;
		}
		return 0;
	}
	else
	{
		loadData(arr, data);
	}

	// Menu
	do
	{
		printMenu();
	menuPoint:
		try {
			cout << "Выберите пункт меню: ";
			cin >> menu;
			getchar();

			if (!cin) throw 0; // If menu not int
		}
		catch (int err) {
			if (err == 0) {
				cerr << endl << "Поддерживаются только цифры! Повторите ввод..." << endl;
				cin.clear();
				cin.ignore(4096, '\n');
			}
			goto menuPoint;
		}

		switch (menu)
		{
		case 1:
			addDoctor(arr);
			break;
		case 2:
			findDoctor(arr);
			break;
		case 3:
			filterDoctor(arr, foundDoctors);
			if (foundDoctors.size() != 0)
			{
				printHeader();
				for (int i = 0; i < foundDoctors.size(); i++)
				{
					cout << foundDoctors[i];
				}
			}
			break;
		case 4:
			sort(arr.begin(), arr.end(), compareByFIO);
			break;
		case 5:
			printAll(arr);
			break;
		case 6:
			removeFirstDoctor(arr);
			break;
		case 7:
			saveData(arr, data);
			data.close();
			return 0;
		default:
			cout << "Введенный вами пункт меню не существует" << endl;
			break;
		}
	} while (TRUE);
}
