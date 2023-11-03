#include "BigReal.h"
#include <bits/stdc++.h>

using namespace std;

BigReal::BigReal(double realNumber) {   // default constructor
    cout << realNumber << endl;
}

BigReal::BigReal(string realNumber) {   // constructor
    bool flag = false;
    int i = 0;
    if (realNumber[0] == '-') {
        sign = 1;
        i++;
    }
    for (;i < realNumber.size(); ++i) {
        if (realNumber[i] == '.') {
            flag = true;
            continue;
        }

        if (!flag)
            num += realNumber[i];
        else
            fraction += realNumber[i];
    }
}

BigReal::BigReal(const BigReal &real) {   // copy constructor
    num = real.num;
    fraction = real.fraction;
    sign = real.sign;
}

int BigReal::size() {

}

void BigReal::test() {
    if (sign)
        cout << '-';
    cout << num << '.' << fraction << endl;
}

//   n1 + n2


BigReal BigReal::operator + (BigReal &real) {


}
