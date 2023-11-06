// File: Question 6-B.cpp
// Purpose: printing the possible combinations after a user input the prefix and the number of digits after
// Author: Mazen Ehab Abdelmoneim Ali
// Section: S6
// ID: 20220467
// TA: Nardeen Mokhless / Maya Ahmed

#include <iostream>
#include <string>

using namespace std;

void numbers(string prefix, int k) {
    if (k == 0) {
        cout << prefix << endl;
    } else {
        numbers(prefix + "0", k - 1);
        numbers(prefix + "1", k - 1);
    }
}

int main() {
    string prefix;
    int k;

    cout << "Enter a prefix string of 0's and 1's: ";
    cin >> prefix;

    cout << "Enter a non-negative integer k: ";
    cin >> k;

    numbers(prefix, k);
    return 0;
}
//Dr. Mohamed el Ramly test cases:
//input:  prefix "00101" and k is 2
// output:
// 0010100
// 0010101
// 0010110
// 0010111