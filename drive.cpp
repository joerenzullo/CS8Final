#include "drive.h"

#include <fstream>

void drive()
{

    Graph g(1000);

    //load the whole file into the graph and add all the edges
    loadfile(g);

    int s = 0, d = 4;
    g.shortestPath(s);
    cout << g.getDistTo(d) << endl;
    showPath(g.getPathTo(d));
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

void loadfile(Graph& g)
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

void chooseMenu()
{
    char choice;
    cout << "Please choose shortest route base on: " << endl;
    cout << " 0. distance  1. cost  2. stops  3. time" << endl;
    cin.get(choice);
    cout << "Your choice: " << choice;
    cin.ignore(1000, '\n');
    while(choice < '0' || choice > '3') {
        cout << "Your coice: " << choice;
        cin.ignore(1000, '\n');
    }
    //////////////////////////////////////

}
