// File: Question6A.cpp
// Purpose: Print Binary with no leading zero
// Author: Mazen Ehab Abdelmoneim Ali
// Section: S6
// ID: 20220467
// TA: Nardeen Mokhless / Maya Ahmed

#include <iostream>

using namespace std;

void binaryPrint(int n, bool leadingZero = true) {
    if (n > 0) {
        binaryPrint(n / 2, n == 1 ? false : true);
        if (leadingZero || n != 0)
            cout << n % 2;
    }
    else if (n == 0 && leadingZero) {
        cout << "0";
    }
}

int main() {
    int n;
    cout << "Enter a non-negative integer: ";
    cin >> n;

    binaryPrint(n);
    return 0;
}
//Dr. Mohamed El Ramly's test cases:
//n = 0  Output:0
//n = 4  Output:100
//n = 27 Output:11011