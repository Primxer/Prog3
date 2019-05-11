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
    int numOfCollision = 0;
    for (string s: tempStore) {
        for (char c: s) {
            sum = sum + (int)c;
        }
        int location = sum%4177;
        if ( !hashMap.at(location).empty()) {
            numOfCollision++;
        }
        hashMap.at(location).push_front(s);
        sum = 0;
    }
    for (auto n: hashMap) {
        n.clear();
    }
    tempStore.empty();
    hashMap.empty();
    hashMap.resize(4177);
    cout<<numOfCollision<<endl;
}

void Hash::hashFunc2(string file) {
    readFile(file);
    int numOfCollisions = 0;
    for (string s: tempStore) {
        const int p = 107;
        long long hash_value = 0;
        long long p_power = 1;
        for (char c: s) {
            hash_value = abs(((hash_value) + (c - 'a' + 1) * p_power) % 4177);
            p_power = (p_power * p) % 4177;
        }
        if ( !hashMap.at(hash_value).empty()) {
            numOfCollisions++;
        }
        hashMap.at(hash_value).push_front(s);
    }
    cout << numOfCollisions << endl;
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