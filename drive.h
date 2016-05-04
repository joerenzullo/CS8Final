#ifndef DRIVE
#define DRIVE

#include <iostream>
#include "graph.h"

using namespace std;

void drive();
void showPath(list<int>*& path, vector<Edge *> edges);

void loadfile(Graph& g, char choice, vector<Edge *> &edges, map<string, int> &nameToNumber, map<int, string> &numberToName);
string tokenize(string& line);

void showSPvalue(double value, char choice, int source, int dest, map<int, string> numberToName);
char chooseMenu();

#endif // DRIVE

