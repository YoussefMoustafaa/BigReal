// File: Question3.cpp
// Purpose: split
// Author: Mazen Ehab Abdelmoneim Ali
// Section: S6
// ID: 20220467
// TA: Nardeen Mokhless / Maya Ahmed

#include <iostream>
using namespace std;

bool bears(int n) {
    if (n == 42) {
        return true;
    } else if (n < 42) {
        return false;
    } else {

        if (n % 2 == 0 && bears(n / 2)) {
            return true;
        }
        if (n % 3 == 0 && bears(n - n / 3)) {
            return true;
        }
        if (n % 4 == 0 && bears(n - (n % 10) * ((n % 100) / 10))) {
            return true;
        }
        if (n % 5 == 0 && bears(n - 42)) {
            return true;
        }

        return false;
    }
}

int main() {
    int n;
    cin >> n;

    if (bears(n)) {
        cout << "bear(" << n << ") is true" << endl;
        cout << "You have reached the goal!" << endl;
    } else {
        cout << "bear(" << n << ") is false" << endl;
        cout << "You lost" << endl;
    }

    return 0;
}
// Dr Mohamed El Ramly's Test Cases to try:
// bear(250) is true
// bear(42) is true
// bear(84) is true
// bear(53) is false
// bear(41) is false