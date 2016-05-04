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
#include "route.h"
#include "airport.h"

using namespace std;

typedef size_t id;
const double infinite = std::numeric_limits<double>::infinity();

class Graph {
public:
    Graph();
    ~Graph();
    Graph(const Graph &other);
    Graph& operator=(const Graph &other);

    void addEdge(const Edge& e);
    size_t getSizeOfEdges();
    size_t getSizeOfAirports();

    double getDistTo(const id& dest);
    list<id>& getPathTo(const id& dest);

    void shortestPath(const id& source, const id& dest);
    void dijkstra(const id& source);

private:
    vector<vector<Edge>> adj;
    map<string, id> airports;

    vector<double> distTo;
    vector<id> pathTo;
    priority_queue<pair<double, id>, vector<pair<double, id>>, greater<pair<double, id>> > pq;

    size_t sizeOfEdges;

    void clear();
    void copy(const Graph &other);
    void nukem();
    void initialize();
};


#endif // GRAPH

