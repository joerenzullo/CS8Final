#ifndef DRIVE
#define DRIVE

#include <iostream>
#include "graph.h"

using namespace std;

void drive();
void showPath(list<int>*& path);
void showSPvalue(double value, char choice, int source, int dest);
char chooseMenu();

#endif // DRIVE

