#include "drive.h"

void drive()
{
    char ans;
    do
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

        ////////////////////////////////////////////
        /// check airport name first (valid or not)
        ////////////////////////////////////////////
        int s = 0, d = 4;
        char c = chooseMenu();
        g.shortestPath(s, c);
        double v = g.getValueTo(d);
        if(v > 0){
            showSPvalue(v, c, s, d);
            showPath(g.getPathTo(d));
        } else{
            // change to real airport names
            cout << "Invalid! No flight from " << s << " to " << d << endl;
        }

        cout << endl << "Try again? (Y/N): ";
        cin << ans;
        cin.ignore(1000, '\n');

    }while(ans == 'Y' || ans == 'y');

    cout << "Good-Bye!" << endl;
}

//If multiple airlines serve the same route, such as Delta and British Airways from Los Angeles to London,
//BOTH routes must be printed in order to give the end-user a choice of airlines (frequent flyer miles really pay off!)


//The input for your program must be a valid airport code for the origin and a valid airport code for the destination.


//Leave LAX (Los Angeles) on American Airways after flying 2,500 miles
//Change planes at ANT (Atlanta) to American Airlines and fly 1,000 miles
//Arrive at MIA (Miami)


/////////////////////////////////////////////////////////////////////////
/// 1.we need to show real name of airport instead of integer, change later
/// 2. shortest time change to hour.
/////////////////////////////////////////////////////////////////////////
void showSPvalue(double value, char choice, int source, int dest)
{
    if(choice == '0')
        cout << "The shortest distence flight from " << source << " to " << dest << " is " << value << " miles.\n";
    else if(choice == '1')
        cout << "The best cost flight from " << source << " to " << dest <<" is " << value << " dollars.\n";
    else if(choice == '2')
        cout << "The shortest time flight from " << source << " to " << dest << " is " << value << " seconds.\n";
    else
        cout << "The least number of stops flight from " << source << " to " << dest << " is " << (int)value << " stops.\n";
}

void showPath(list<int>*& path)
{
    std::cout << "Path : " << endl;
    std::list<int>::const_iterator itpath = path->begin(), end = path->end()--;
    end--;

   while(itpath != end){
        cout << *itpath;
        cout << " --> " << (*(++itpath)) << endl;
    }
}

char chooseMenu()
{
    char choose;
    cout << "Please choose shortest route base on: " << endl;
    cout << " 0. distance  1. cost  2. time  3. stops" << endl << endl;
    cout << "Your choose: " << choose;
    cin.ignore(1000, '\n');
    while(choose < '0' || choose > '3') {
        cout << "Invalid! Your choose: " << choose;
        cin.ignore(1000, '\n');
    }
    return choose;
}
