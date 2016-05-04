#ifndef EDGE
#define EDGE

#include <iostream>
#include <cstdlib>

using namespace std;

struct Edge
{
    string IATA_Airline;
    string SourceAirport;
    string DestinationAirport;
    double Price;
    double DistanceMiles;
    string FromName;
    string FromCity;
    string FromCountry;
    string FromICAO;
    double FromLatitude;
    double FromLongitude;
    double FromAltitude;
    double FromTimezone;
    string FromTZdatabasetimezone;
    string ToName;
    string ToCity;
    string ToCountry;
    string ToICAO;
    double ToLatitude;
    double ToLongitude;
    double ToAltitude;
    double ToTimezone;
    string ToTZdatabasetimezone;
    string Airline_Name;
    string Airline_ICAO;
    double time;
    int SourceAirportID;
    int DestinationAirportID;

    //We can set this dynamically, on load, given the preferences of our user.
    double weight;


    Edge(string IATA_Airline_input = string(),
            string SourceAirport_input = string(),
            string DestinationAirport_input = string(),
            double Price_input = double(),
            double DistanceMiles_input = double(),
            string FromName_input = string(),
            string FromCity_input = string(),
            string FromCountry_input = string(),
            string FromICAO_input = string(),
            double FromLatitude_input = double(),
            double FromLongitude_input = double(),
            double FromAltitude_input = double(),
            double FromTimezone_input = double(),
            string FromTZdatabasetimezone_input = string(),
            string ToName_input = string(),
            string ToCity_input = string(),
            string ToCountry_input = string(),
            string ToICAO_input = string(),
            double ToLatitude_input = double(),
            double ToLongitude_input = double(),
            double ToAltitude_input = double(),
            double ToTimezone_input = double(),
            string ToTZdatabasetimezone_input = string(),
            string Airline_Name_input = string(),
            string Airline_ICAO_input = string(),
            double time_input = double(),
            int SourceAirportID_input = int(),
            int DestinationAirportID_input = int())
    {
        IATA_Airline = IATA_Airline_input;
        SourceAirport = SourceAirport_input;
        DestinationAirport = DestinationAirport_input;
        Price = Price_input;
        DistanceMiles = DistanceMiles_input;
        FromName = FromName_input;
        FromCity = FromCity_input;
        FromCountry = FromCountry_input;
        FromICAO = FromICAO_input;
        FromLatitude = FromLatitude_input;
        FromLongitude = FromLongitude_input;
        FromAltitude = FromAltitude_input;
        FromTimezone = FromTimezone_input;
        FromTZdatabasetimezone = FromTZdatabasetimezone_input;
        ToName = ToName_input;
        ToCity = ToCity_input;
        ToCountry = ToCountry_input;
        ToICAO = ToICAO_input;
        ToLatitude = ToLatitude_input;
        ToLongitude = ToLongitude_input;
        ToAltitude = ToAltitude_input;
        ToTimezone = ToTimezone_input;
        ToTZdatabasetimezone = ToTZdatabasetimezone_input;
        Airline_Name = Airline_Name_input;
        Airline_ICAO = Airline_ICAO_input;
        time = time_input;
        SourceAirportID = SourceAirportID_input;
        DestinationAirportID = DestinationAirportID_input;
        weight = DistanceMiles;
    }

    ~Edge()
    {
        IATA_Airline = string();
        SourceAirport = string();
        DestinationAirport = string();
        Price = double();
        DistanceMiles = double();
        FromName = string();
        FromCity = string();
        FromCountry = string();
        FromICAO = string();
        FromLatitude = double();
        FromLongitude = double();
        FromAltitude = double();
        FromTimezone = double();
        FromTZdatabasetimezone = string();
        ToName = string();
        ToCity = string();
        ToCountry = string();
        ToICAO = string();
        ToLatitude = double();
        ToLongitude = double();
        ToAltitude = double();
        ToTimezone = double();
        ToTZdatabasetimezone = string();
        Airline_Name = string();
        Airline_ICAO = string();
        time = double();
        SourceAirportID = int();
        DestinationAirportID = int();
        weight = double();
    }

};

#endif // EDGE

