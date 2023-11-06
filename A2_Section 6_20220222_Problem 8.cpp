// File: Question8.cpp
// Purpose: pattern
// Author: Omar Ashraf Zakaria
// Section: S6
// ID: 20220222
// TA: Nardeen Mokhless / Maya Ahmed
#include <iostream>
using namespace std;
void result(int n, int i){
    if (n == 0)
        return;

    result(n / 2, i);

    for (int j = 0; j < i; j++)
        cout << "  ";
    for (int j = 0; j < n; j++)
        cout << "* ";
    cout << endl;

    result(n / 2, i + n / 2);

}
int main() {
    int n;
    cout<<"please enter a num power of 2 and greater than zero : ";
    cin>>n;
    result(n,0);
}