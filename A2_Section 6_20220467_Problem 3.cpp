// File: Question3.cpp
// Purpose: split
// Author: Mazen Ehab Abdelmoneim Ali
// Section: S6
// ID: 20220467
// TA: Nardeen Mokhless / Maya Ahmed

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> split(string target, string delimiter) {
    vector<string> result;
    int pos = 0;
    int start = 0;
    while ((pos = target.find(delimiter, start)) != string::npos) {
        string substring = target.substr(start, pos - start);
        result.push_back(substring);
        start = pos + delimiter.length();
    }
    string remaining = target.substr(start);
    result.push_back(remaining);
    return result;
}

int main() {
    string input;
    string delimiter;

    cout << "Enter the target string: ";
    getline(cin, input);

    cout << "Enter the delimiter: ";
    getline(cin, delimiter);

    vector<string> result = split(input, delimiter);

    for (string str : result) {
        cout << str << endl;
    }

    return 0;
}
// Dr. Mohamed el Ramly's Test Cases:
//split("10,20,30", ",")
//should return a vector with the strings "10", "20", and "30". Similarly,
//split("do re mi fa so la ti do", " ")
//should return a vector with the strings "do", "re", "mi", "fa", "so", "la", "ti", and "do".