#ifndef EDGE
#define EDGE

#include <iostream>
#include <cstdlib>

using namespace std;

struct Edge
{
    int source, dest;
    double weight;

    string sourceAirport;
    string sourceAirportID;

    string destinationAirport;
    string destinationAirportID;

    Edge(const int& s = int(), const int& d = int(), const double& w = double())
    {
        source = s;
        dest = d;
        weight = w;
    }

    ~Edge()
    {
        source = int();
        dest = int();
        weight = double();
    }

};

#endif // EDGE

