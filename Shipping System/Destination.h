#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "Truck.h"
#include "Package.h"
using namespace std;

#ifndef UNTITLED14_DESTINATION_H
#define UNTITLED14_DESTINATION_H


class Destination {
public:
    Destination();
    Destination(string cityName,Stack<Package> pack,Queue<Truck> truck);

    string city;
    Stack<Package> s;
    Queue<Truck> q;
    string getCity();
    
};


#endif //UNTITLED14_DESTINATION_H
