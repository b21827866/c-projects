//
// Created by 90552 on 15.12.2020.
//

#include "Destination.h"
Destination::Destination() {}
Destination::Destination(string cityName, Stack<Package> pack, Queue<Truck> truck) {
    city = cityName;
    s = pack;
    q = truck;


}
string Destination::getCity() {
    return city;
}
