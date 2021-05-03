//
// Created by 90552 on 15.12.2020.
//

#include "Package.h"
Package::Package() {}
Package::Package(string packName) {
    pack = packName;
}
string Package::getPack() {
    return pack;
}