#include "graph.h"


Graph::Graph(const int& size) //
{
    sizeOfAirports = size;
    initialize();
}

Graph::~Graph() //
{
    nukem();
}

Graph::Graph(const Graph &other) //
{
    copy(other);
}

Graph& Graph::operator=(const Graph &other) //
{
    if(this != &other)
    {
        nukem();
        copy(other);
    }
    return *this;
}

void Graph::addEdge(Edge*& e) //
{
    adj[e->SourceAirportID].push_back(e);
    ++sizeOfEdges;
//    cout << e->source << endl;
//    cout << adj[0][0]->source << endl;
}

int Graph::getSizeOfEdges() //
{
    return sizeOfEdges;
}

int Graph::getSizeOfAirports() //
{
    return sizeOfAirports;
}

double Graph::getDistTo(const int& dest)  //
{
    return distTo[dest];
}

list<int>*& Graph::getPathTo(int dest)  //
{
    list<int>* path = new list<int>();
    for ( ; dest != -1; dest = pathTo[dest])
        path->push_front(dest);
    return path;
}

void Graph::shortestPath(const int& source)
{

    dijkstra(source);
}

void Graph::dijkstra(const int& source)  //
{
    int n = adj.size();
    distTo.clear();
    distTo.resize(n, infinite);
    distTo[source] = 0;
    pathTo.clear();
    pathTo.resize(n, -1);

    pq.push(make_pair(distTo[source], source));

    while (!pq.empty())
    {
        double dist = pq.top().first;
        int s = pq.top().second;
        pq.pop();

        // Because we leave old copies of the vertex in the priority queue
        // (with outdated higher distances), we need to ignore it when we come
        // across it again, by checking its distance against the minimum distance
        if (dist > distTo[s])
            continue;

        // Visit each edge exiting s
        for (std::vector<Edge*>::const_iterator iter = adj[s].begin(); iter != adj[s].end(); iter++)
        {
            int d = (*iter)->DestinationAirportID;
            double weight = (*iter)->weight;
            double dist_through_s = dist + weight;
            if (dist_through_s < distTo[d])
            {
                distTo[d] = dist_through_s;
                pathTo[d] = s;
                pq.push(make_pair(distTo[d], d));
            }
        }
    }
}

void Graph::clear() //
{
    adj.clear();
    distTo.clear();
    pathTo.clear();
    sizeOfEdges = int();
    sizeOfAirports = int();
}

void Graph::copy(const Graph &other) //
{
    //operator =
    //Assigns new contents to the container, replacing its current content.
    adj = other.adj;
    distTo = other.distTo;
    pathTo = other.pathTo;
    sizeOfEdges = other.sizeOfEdges;
    sizeOfAirports = other.sizeOfAirports;
}

void Graph::nukem() //
{
    clear();
}

void Graph::initialize() //
{
    sizeOfEdges = 0;
    adj.reserve(sizeOfAirports);
    for(int i = 0; i < sizeOfAirports; ++i) {
        adj.push_back(vector<Edge*>());
        adj[i].reserve(200);
    }
    distTo.reserve(sizeOfAirports);
    pathTo.reserve(sizeOfAirports);
}
