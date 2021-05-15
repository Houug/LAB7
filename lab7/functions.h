#pragma once
#include "Clinic.h"

void printHeader();
void printMenu();
Clinic findDoctor(deque<Clinic> m);
void addDoctor(deque<Clinic>& m);
void printAll(deque<Clinic> m);
void removeFirstDoctor(deque<Clinic>& m);
bool compareByFIO(Clinic& obj1, Clinic& obj2);