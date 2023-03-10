// main.cpp
#include "Readfile.h"
#include "Graph.h"
#include "Airport.h"
// #include "Route.h"

//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    // Initialize the airport vector
    vector<Airport> airports;

    // Initialize the routes vector
    vector<Route> routes;
    vector<Route*> routes_ptrs;
    //string filename = "./tests/airport_test.txt";
    Readfile read = Readfile();
    read.readfile_airport(airports, "./data/airport.txt");
    read.readfile_routes(routes_ptrs, airports, "./data/route.txt");
    
    for (auto & route : routes_ptrs)
    {
        routes.push_back(*route);
    }

    Graph myGraph(routes,airports);
    //myGraph.printGraph();

    //Test Case

    vector<unsigned> path = myGraph.Dijkstra(77, 10);
    cout<<"total_distance:"<<myGraph.total_dist<<endl;

    cout<<"path:"<<endl;
    for (unsigned int i = 0; i < path.size(); i++){
       cout<<path[i]<<"  ";
    }
    cout<<" "<<endl;



    return 0;
}
