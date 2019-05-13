//
// Created by riple on 5/7/2019.
//

#include "Hash.h"

Hash::Hash() {
    hashMap.resize(4177);
}

void Hash::hashFunc1(string file) {
    readFile(file);
    for (string s: tempStore) {
        int sum = 0;
        for (char c: s) {
            sum = sum + (int)c;
        }
        int location = sum%4177;
        hashMap.at(location).push_front(s);
    }
}

void Hash::hashFunc2(string file) {
    readFile(file);
    for (string s: tempStore) {
        const int p = 107;
        long long hash_value = 0;
        long long p_power = 1;
        for (char c: s) {
            hash_value = abs(((hash_value) + (c - 'a' + 1) * p_power) % 4177);
            p_power = (p_power * p) % 4177;
        }
        hashMap.at(hash_value).push_front(s);
    }
}

void Hash::hashFunc3(string file) {
    readFile(file);
    for ( string s: tempStore) {
        unsigned long hash = 5381;
        for ( string::iterator it = s.begin(); it!=s.end(); it++) {
            hash = ((hash<<5) + hash) + *it;
        }
        hashMap.at(hash%4177).push_front(s);
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

void Hash::clearHashMap() {
    hashMap.clear();
    hashMap.resize(4177);
    tempStore.clear();
}

void Hash::printHashMap() {
    vector<int> temp;
    temp.resize(31);
    for (auto data: hashMap) {
        int count = 0;
        for (auto V: data) {
            count++;
        }
        if (count > temp.size()-1) {
            temp.at(temp.size()-1)++;
        } else {
            temp.at(count)++;
        }
    }
    for (int i = 0; i < temp.size(); i++) {
        if ( i == temp.size()-1) {
            cout << "Number of chains with length greater than " << i << ": "
                 << temp.at(i) << endl;
        } else {
            cout << "Number of chains with length " << i << ": "
                 << temp.at(i) << endl;
        }
    }
}