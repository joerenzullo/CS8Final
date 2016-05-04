#ifndef EDGE
#define EDGE

#include <iostream>
#include <cstdlib>

using namespace std;

struct Edge
{
    size_t source, dest;
    double weight;

    Edge(const size_t& s = size_t(), const size_t& d = size_t(), const double& w = double())
    {
        source = s;
        dest = d;
        weight = w;
    }

    ~Edge()
    {
        source = size_t();
        dest = size_t();
        weight = double();
    }

};

#endif // EDGE

