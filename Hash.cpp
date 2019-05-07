//
// Created by riple on 5/7/2019.
//

#include "Hash.h"

Hash::Hash() {
    hashMap.resize(4177);
}

void Hash::hashFunc1(string file) {
    readFile(file);
    int sum = 0;
    for (string s: tempStore) {
        for (char c: s) {
            sum = sum + (int)c;
        }
        int location = sum%4177;
        if ( !hashMap.at(location).empty()) {
            cout<<sum<<" collision"<<endl;
        }
        hashMap.at(location).push_back(s);
        sum = 0;
    }
}

void Hash::readFile(string file) {
    ifstream inFile;
    string line;
    inFile.open(file);
    if (!inFile) {
        cout<<"Unable to open file."<<endl;
        exit(1);
    }
    while ( getline(inFile, line)) {
        tempStore.push_back(line);
    }
    inFile.close();
}

void Hash::printHashMap() {

    for (auto data: hashMap) {
        for (auto V: data) {
            cout<<"->"<<V<<endl;
            cout<<endl;
        }
    }
}