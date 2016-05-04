//#include <QApplication>
//#include <marble/MarbleWidget.h>

#include <iostream>
#include "graph.h"

using namespace std;

void showPath(list<int>*& path);

int main(int argc, char** argv)
{
    Graph g(5);

    Edge* e1 = new Edge(0, 1, 4);
    Edge* e2 = new Edge(0, 2, 9);
    Edge* e3 = new Edge(0, 3, 5);
    Edge* e4 = new Edge(1, 3, 8);
    Edge* e5 = new Edge(2, 3, 3);
    Edge* e6 = new Edge(3, 4, 6);
    Edge* e7 = new Edge(4, 2, 2);

    g.addEdge(e1);
    g.addEdge(e2);
    g.addEdge(e3);
    g.addEdge(e4);
    g.addEdge(e5);
    g.addEdge(e6);
    g.addEdge(e7);

    int s = 0, d = 3;
    g.shortestPath(s);
    cout << g.getDistTo(d) << endl;
    showPath(g.getPathTo(d));


    return 0;
//    QApplication app(argc, argv);

//    Marble::MarbleWidget *mapWidget = new Marble::MarbleWidget;
//    // Load Marble using OpenStreetMap in Mercator projection
//    mapWidget->setProjection(Marble::Spherical);
//    mapWidget->setMapThemeId("earth/openstreetmap/openstreetmap.dgml");

//    mapWidget->setWindowTitle("Hello Marble!");
//    mapWidget->show();
//    return app.exec();
}

void showPath(list<int>*& path)
{
    std::cout << "Path : ";
    std::copy(path->begin(), path->end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::list<int>::const_iterator itpath = path->begin();

    for(;itpath != path->end(); ++itpath){
        cout << *itpath << " --> " << (*(++itpath)) << endl;
    }
}

