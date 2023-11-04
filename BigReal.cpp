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


bool BigReal::operator > (const BigReal &real) {

    string n1 = num;
    string n2 = real.num;

    // .9854
    // .7621

    // 55.134
    // 55.23

    if (n1.size() > n2.size())
        return true;
    else if (n1.size() < n2.size())
        return false;
    else {
        for (int i = 0; i < n1.size(); ++i) {
            if (n1[i] > n2[i])
                return true;
            else if (n1[i] < n2[i])
                return false;
        }
        // if num = num then check fractions

        string f1 = fraction;
        string f2 = real.fraction;

        int min = abs((int)f1.size() - (int)f2.size());

        if (f1.size() < f2.size()) {
            for (int i = 0; i < min; ++i) {
                f1 += '0';
            }
        } else {
            for (int i = 0; i < min; ++i) {
                f2 += '0';
            }
        }

        for (int i = 0; i < f1.size(); ++i) {
            if (f1[i] > f2[i])
                return true;
            else if (f1[i] < f2[i])
                return false;
        }

        return false;

    }
}



BigReal BigReal::operator + (BigReal &real) {

    BigReal result;
    //   000008538959345.3829323232
    //   232328398429842.9238723000

    string f1 = fraction;
    string f2 = real.fraction;
    string f3;

    unsigned int min2 = abs((int)f1.size() - (int)f2.size());

    if (f1.size() <= f2.size()) {
        for (int i = 0; i < min2; ++i) {
            f1 += '0';
        }
    } else {
        for (int i = 0; i < min2; ++i) {
            f2 += '0';
        }
    }

    int i = 0;
    int carry_f = 0;
    for (; i < f1.size(); ++i) {
        char c = f1[i];
        //   0999
        //   1111
        int number1 = f1[f1.size()-i-1] - '0';
        int number2 = f2[f1.size()-i-1] - '0';
        int res = number1 + number2;
        res += carry_f;
        if (res < 10) {
            f3 += to_string(res);
            carry_f = 0;
        } else {
            f3 += to_string(res - 10);
            carry_f = 1;
        }
    }

    reverse(f3.begin(), f3.end());

    int carry;
    if (carry_f)
        carry = 1;
    else
        carry = 0;

    //-----------------------------------

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
            new_n2 += '0';
        }
        new_n2 += n2;
        new_n1 = n1;
    }


    for (int i = 0; i < new_n1.size(); ++i) {
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
    result.fraction = f3;
    result.sign = 0;

    return result;

}


BigReal BigReal::operator - (BigReal &real) {

    BigReal result;
    //   000008538959345.3829323232
    //   232328398429842.9238723000

    // 19345
    // 09842
    //

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


