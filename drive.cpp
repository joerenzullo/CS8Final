#include "drive.h"

#include <fstream>

void drive()
{
    char ans;
    do
    {
        ////////////////////////////////////////////
        /// check airport name first (valid or not)
        ////////////////////////////////////////////
        int s = 0, d = 4;
        char c = chooseMenu();


        Graph g(400);
        vector<Edge*> edges;
        map<string,int> nameToNumber;
        map<int,string> numberToName;
        list<int>* pathVar = new list<int>();

        //load the whole file into the graph and add all the edges
        loadfile(g, c, edges, nameToNumber, numberToName);


        g.shortestPath(s); //need to get (s,c) syntax so user choice can matter
        double v = g.getDistTo(d);
        if(v > 0)
        {
            showSPvalue(v, c, s, d, numberToName);

            //set pathVar
            g.getPathTo(d, pathVar);
            showPath(pathVar, edges);
        }
        else
        {
            // change to real airport names
            cout << "Invalid! No flight from " << numberToName[s] << " to " << numberToName[d] << endl;
        }

        cout << endl << "Try again? (Y/N): ";
        cin >> ans;
        cin.ignore(1000, '\n');

    }while(ans == 'Y' || ans == 'y');
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
void showSPvalue(double value, char choice, int source, int dest, map<int,string> numberToName)
{
    if(choice == '0')
        cout << "The shortest distence flight from " << numberToName[source] << " to " << numberToName[dest] << " is " << value << " miles.\n" << endl;
    else if(choice == '1')
        cout << "The best cost flight from " << numberToName[source] << " to " << numberToName[dest] <<" is " << value << " dollars.\n" << endl;
    else if(choice == '2')
        cout << "The shortest time flight from " << numberToName[source] << " to " << numberToName[dest] << " is " << value << " hours.\n" << endl;
    else
        cout << "The least number of stops flight from " << numberToName[source] << " to " << numberToName[dest] << " is " << (int)value << " stops.\n" << endl;
}



void showPath(list<int>*& path, vector<Edge*> edges)
{

    std::list<int>::const_iterator itpath = path->begin(), end = path->end()--;
    end--;
    int index = 0;

    vector<Edge*> pathEdges;

    while(itpath != end)
    {
        pathEdges.clear();
        int from = *itpath;
        int to = *(++itpath);
        for(Edge* e : edges)
        {
            if(e->SourceAirportID == from && e->DestinationAirportID == to)
            {
                pathEdges.push_back(e);
            }
        }
        if (index == 0)
        {
            Edge* dummy = pathEdges.at(0);
            cout << "Start your journey at " << dummy->SourceAirport << " (";
            cout << dummy->FromCity << ", " << dummy->FromCountry << ")";
            cout << " and fly " << dummy->DistanceMiles << " miles." << endl;

            cout << "You can fly on:" << endl;
            for(Edge* j: pathEdges)
            {
                cout << j->Airline_Name << " for $" << j->Price << endl;
            }
        }
        else
        {
            Edge* dummy = pathEdges.at(0);
            cout << "Then, change planes at " << dummy->SourceAirport << " (";
            cout << dummy->FromCity << ", " << dummy->FromCountry << ")";
            cout << " and fly " << dummy->DistanceMiles << " miles." << endl;

            cout << "You can fly on:" << endl;
            for(Edge* j: pathEdges)
            {
                cout << j->Airline_Name << " for $" << j->Price << endl;
            }

        }
        index++;
    }
    cout << "Finish your journey at " << pathEdges.at(0)->DestinationAirport << " (";
    cout << pathEdges.at(0)->ToCity << ", " << pathEdges.at(0)->ToCountry << ")";
    cout << endl;

}

void loadfile(Graph& g, char choice, vector<Edge*>& edges, map<string,int>& nameToNumber, map<int,string>& numberToName)
{
    ifstream myfile;
    myfile.open("routes.csv");
    if(myfile.is_open())
    {

        string line;
        //throw away first line (header)
        getline(myfile,line);

        while(getline(myfile, line))
        {
            string IATA_Airline_input = tokenize(line);
            string SourceAirport_input = tokenize(line);
            string DestinationAirport_input = tokenize(line);
            double Price_input = stod(tokenize(line));
            double DistanceMiles_input = stod(tokenize(line));
            string FromName_input = tokenize(line);
            string FromCity_input = tokenize(line);
            string FromCountry_input = tokenize(line);
            string FromICAO_input = tokenize(line);
            double FromLatitude_input = stod(tokenize(line));
            double FromLongitude_input = stod(tokenize(line));
            double FromAltitude_input = stod(tokenize(line));
            double FromTimezone_input = stod(tokenize(line));
            string FromTZdatabasetimezone_input = tokenize(line);
            string ToName_input = tokenize(line);
            string ToCity_input = tokenize(line);
            string ToCountry_input = tokenize(line);
            string ToICAO_input = tokenize(line);
            double ToLatitude_input = stod(tokenize(line));
            double ToLongitude_input = stod(tokenize(line));
            double ToAltitude_input = stod(tokenize(line));
            double ToTimezone_input = stod(tokenize(line));
            string ToTZdatabasetimezone_input = tokenize(line);
            string Airline_Name_input = tokenize(line);
            string Airline_ICAO_input = tokenize(line);
            double time_input = stod(tokenize(line));
            int SourceAirportID_input = stoi(tokenize(line));
            int DestinationAirportID_input = stoi(tokenize(line));

            Edge* e = new Edge(IATA_Airline_input,
                                SourceAirport_input,
                                DestinationAirport_input,
                                Price_input,
                                DistanceMiles_input,
                                FromName_input,
                                FromCity_input,
                                FromCountry_input,
                                FromICAO_input,
                                FromLatitude_input,
                                FromLongitude_input,
                                FromAltitude_input,
                                FromTimezone_input,
                                FromTZdatabasetimezone_input,
                                ToName_input,
                                ToCity_input,
                                ToCountry_input,
                                ToICAO_input,
                                ToLatitude_input,
                                ToLongitude_input,
                                ToAltitude_input,
                                ToTimezone_input,
                                ToTZdatabasetimezone_input,
                                Airline_Name_input,
                                Airline_ICAO_input,
                                time_input,
                                SourceAirportID_input,
                                DestinationAirportID_input);

            if(choice == '0')
            {
                e->weight = e->DistanceMiles;
            }
            else if(choice == '1')
            {
                e->weight = e->Price;
            }
            else if(choice == '2')
            {
                e->weight = e->time;
            }
            else
            {
                e->weight = 1;
            }

            edges.push_back(e);
            nameToNumber[e->SourceAirport] = e->SourceAirportID;
            numberToName[e->SourceAirportID] = e->SourceAirport;

            g.addEdge(e);
        }
    }
}

string tokenize(string& line)
{
    string temp = line.substr(0,line.find_first_of(','));
    line = line.substr(line.find_first_of(',')+1);
    return temp;
}

char chooseMenu()
{
    char choice;
    cout << "Please choose shortest route base on: " << endl;
    cout << " 0. distance  1. cost  2. time  3. stops" << endl << endl;
    cin.get(choice);
    cout << "Your choice: " << choice << endl << endl;
    cin.ignore(1000, '\n');
    while(choice < '0' || choice > '3') {
        cout << "Invalid! Your choose: " << choice;
        cin.ignore(1000, '\n');
    }
    return choice;
}
