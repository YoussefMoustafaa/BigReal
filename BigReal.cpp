#include "BigReal.h"
#include <bits/stdc++.h>

using namespace std;

BigReal::BigReal(double realNumber) {   // default constructor
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


BigReal BigReal::operator + (BigReal &real) {

    BigReal result;
    //   000008538959345.38293232323232
    //   232328398429842.9238723
    string n1 = num;
    string n2 = real.num;
    string n3;

    unsigned int min = abs((int)n1.size() - (int)n2.size());

    string new_n1, new_n2;

    if (n1.size() <= n2.size()) {
        for (int i = 0; i < min; ++i) {
            new_n1 += '0';
        }
        new_n1 += n1;
        new_n2 = n2;
    } else {
        for (int i = 0; i < min; ++i) {
            new_n2[i] += '0';
        }
        new_n2 += n2;
        new_n1 = n1;
    }

    int i = 0;
    int carry = 0;
    for (; i < new_n1.size(); ++i) {
        char c = new_n1[i];
        //   0999
        //   1111
        int number1 = new_n1[new_n1.size()-i-1] - '0';
        int number2 = new_n2[new_n1.size()-i-1] - '0';
        int res = number1 + number2;
        res += carry;
        if (res < 10) {
            n3 += to_string(res);
            carry = 0;
        } else {
            n3 += to_string(res - 10);
            carry = 1;
        }
    }

    if (carry)
        n3 += "1";

    reverse(n3.begin(), n3.end());

    result.num = n3;
    result.fraction = "00";
    result.sign = 0;

    return result;

}

BigReal & BigReal::operator = (const BigReal& real) {

    this->num = real.num;
    this->fraction = real.fraction;
    this->sign = real.sign;

    return *this;
}

ostream & operator << (ostream &out, const BigReal &real) {
    out << real.num << '.' << real.fraction << endl;
    return out;
}


