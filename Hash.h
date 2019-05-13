//
// Created by riple on 5/7/2019.
//

#ifndef PROGRAM3_HASH_H
#define PROGRAM3_HASH_H

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <fstream>
#include <map>

using namespace std;

class Hash {
    public:
        Hash();
        void hashFunc1(string);
        void hashFunc2(string);
        void printHashMap();
        void clearHashMap();
        void hashFunc3(string);
    private:
    vector<list<string>> hashMap;
    vector<string> tempStore;
    void readFile(string);
};


#endif //PROGRAM3_HASH_H
