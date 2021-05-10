#pragma once
#include "Clinic.h"
#include <fstream>
#include <deque>

void loadData(deque<Clinic>& m, fstream& data);
void createData(deque<Clinic>& m);
void saveData(deque<Clinic> m, fstream& data);