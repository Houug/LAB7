#pragma once
#include "Clinic.h"

int checkInput(int n, int mode);
void printHeader();
void printMenu();
bool checkInput();
Clinic findDoctor(deque<Clinic> m);
void sortData(deque<Clinic>& m);
void addDoctor(deque<Clinic>& m);
void printAll(deque<Clinic> m);
void removeFirstDoctor(deque<Clinic>& m);