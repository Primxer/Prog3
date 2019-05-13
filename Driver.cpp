#include <iostream>
#include <chrono>
#include "Hash.h"
using namespace std::chrono;

int main() {
    Hash temp;
    cout << "HashFunc1 " << endl;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    temp.hashFunc1("phonebook.txt");
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>( t2 - t1 ).count();
    cout << "Runtime: " << duration << " milliseconds" << endl;
    temp.printHashMap();
    temp.clearHashMap();
    cout << endl;
    cout << "HashFunc2" << endl;
    t1 = high_resolution_clock::now();
    temp.hashFunc2("phonebook.txt");
    t2 = high_resolution_clock::now();
    duration = duration_cast<milliseconds>( t2 - t1 ).count();
    cout << "Runtime: " << duration << " milliseconds" << endl;
    temp.printHashMap();
    temp.clearHashMap();
    cout << endl;
    cout << "HashFunc3" << endl;
    t1 = high_resolution_clock::now();
    temp.hashFunc3("phonebook.txt");
    t2 = high_resolution_clock::now();
    duration = duration_cast<milliseconds>( t2 - t1 ).count();
    cout << "Runtime: " << duration << " milliseconds" << endl;
    temp.printHashMap();
    return 0;
}