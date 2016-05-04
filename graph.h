#ifndef GRAPH
#define GRAPH

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <limits>
#include <queue>
#include <map>
#include <utility>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <unistd.h>
#include <cmath>

#include "edge.h"

using namespace std;

typedef priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>> > p_queue;
const double infinite = std::numeric_limits<double>::infinity();

class Graph {
public:
    Graph(const int& size = 1000);
    ~Graph();
    Graph(const Graph &other);
    Graph& operator=(const Graph &other);

    void addEdge(Edge*& e);
    int getSizeOfEdges();
    int getSizeOfAirports();

    double getValueTo(const int& dest);
    list<int>*& getPathTo(int dest);

    void shortestPath(const int& source, char theChoice);
    void dijkstra(const int& source);

private:
    vector<vector<Edge*>> adj;
    vector<double> valueTo;
    vector<int> pathTo;
    p_queue pq;
    char choice;

    int sizeOfEdges;
    int sizeOfAirports;

    void clear();
    void copy(const Graph &other);
    void nukem();
    void initialize();
};


#endif // GRAPH

