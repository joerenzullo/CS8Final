#ifndef DRIVE
#define DRIVE

#include <iostream>
#include "graph.h"

using namespace std;

void drive();
void showPath(list<int>*& path);
void loadfile(Graph& g);
string tokenize(string& line);
void showSPvalue(double value, char choice, int source, int dest);
void chooseMenu();

#endif // DRIVE

