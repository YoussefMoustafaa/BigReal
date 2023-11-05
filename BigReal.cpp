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

    // 0  1

    if (sign < real.sign)
        return true;
    else if (sign > real.sign)
        return false;

    bool isGreater = false;

    // .9854
    // .7621

    // 55.134
    // 55.230

    bool declared = false;

    if (n1.size() > n2.size())
        isGreater = true;
    else if (n1.size() < n2.size())
        isGreater = false;
    else {
        for (int i = 0; i < n1.size(); ++i) {
            if (n1[i] > n2[i]) {
                isGreater = true;
                declared = true;
                break;
            }
            else if (n1[i] < n2[i]) {
                isGreater = false;
                declared = true;
                break;
            }
        }
        // if num = num then check fractions
        if (!declared) {
            string f1 = fraction;
            string f2 = real.fraction;

            int min = abs((int) f1.size() - (int) f2.size());

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
                if (f1[i] > f2[i]) {
                    isGreater = true;
                    break;
                } else if (f1[i] < f2[i]) {
                    isGreater = false;
                    break;
                }
            }

        }

    }

    // if two numbers are -ve, (sign = 1)
    if (sign && real.sign) {
        isGreater ^= 1;
        return isGreater;
    } else
        return isGreater;
}


bool BigReal::operator < (const BigReal &real) {

    string n1 = num;
    string n2 = real.num;

    if (sign > real.sign)
        return true;
    else if (sign < real.sign)
        return false;

    bool isSmaller = false;
    bool declared = false;

    if (n1.size() < n2.size())
        isSmaller = true;
    else if (n1.size() > n2.size())
        isSmaller = false;
    else {
        for (int i = 0; i < n1.size(); ++i) {
            if (n1[i] < n2[i]) {
                isSmaller = true;
                declared = true;
                break;
            }
            else if (n1[i] > n2[i]) {
                isSmaller = false;
                declared = true;
                break;
            }
        }

        if (!declared) {
            string f1 = fraction;
            string f2 = real.fraction;

            int min = abs((int) f1.size() - (int) f2.size());

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
                if (f1[i] < f2[i]) {
                    isSmaller = true;
                    break;
                } else if (f1[i] > f2[i]) {
                    isSmaller = false;
                    break;
                }
            }

        }

    }

    // if two numbers are -ve, (sign = 1)
    if (sign && real.sign) {
        isSmaller ^= 1;
        return isSmaller;
    } else
        return isSmaller;

}


bool BigReal::operator == (const BigReal &real) {
    if (*this > real || *this < real)
        return false;
    else
        return true;
}


bool BigReal::operator != (const BigReal &real) {
    if (*this == real)
        return false;
    else
        return true;
}

int negative_sign = 0;


BigReal BigReal::operator + (BigReal &real) {

    BigReal result;

    if (negative_sign)
        result.sign = 1;
    else
        result.sign = 0;

    int firstSign = sign;
    int secondSign = real.sign;
    // 1st -ve, 2nd +ve

    // -4 + 3
    // 7 - 4
    // 3 - 4
    if (firstSign > secondSign) {
        this->sign = 0;
        return (real - *this);
    }
    // 1st +ve, 2nd -ve
    // 7 - 4 = 3
    else if (firstSign < secondSign) {
        real.sign = 0;
        return (*this - real);
    }
    // 1st -ve, 2nd -ve
    // -4 + (-5)
    // 4 + 5 = 9 * (-)
    else if (firstSign == 1 && secondSign == 1) {
        this->sign = 0;
        real.sign = 0;
        result.sign = 1;
    }

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

    return result;

}


BigReal BigReal::operator - (BigReal &real) {

    BigReal result;

    result.sign = 0;
    int firstSign = sign;
    int secondSign = real.sign;

    // 1st -ve, 2nd +ve
    // -4 - 3
    // 4 + 3 = 7 * (-)
    if (firstSign > secondSign) {
        sign = 0;
        negative_sign = 1;
        return (*this + real);
    }
    // 1st +ve, 2nd -ve
    // 4 - (-3)
    // 4 + 3
    else if (firstSign < secondSign) {
        real.sign = 0;
        return (*this + real);
    }
    // 1st -ve, 2nd -ve
    // -4 - (-3) = 1 * (-)
    // -4 + 3
    // 3 - 4
    else if (firstSign == 1 && secondSign == 1) {
        sign = 0;
        real.sign = 0;
        return (real - *this);
    }

    //   000008538959345.3829323232
    //   232328398429842.9238723000

    // 10005
    // 09842
    string f1 = fraction;
    string f2 = real.fraction;
    string f3;

    string n1 = num;
    string n2 = real.num;
    string n3;


    if (*this < real) {
        swap(n1, n2);
        swap(f1, f2);
        result.sign = 1;
    }


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

        int carry_f = 0;

        for (int i = 0; i < f1.size(); ++i) {

            int fraction1 = f1[f1.size()-i-1] - '0';
            int fraction2 = f2[f1.size()-i-1] - '0';
            int res = fraction1 - fraction2;

            res -= carry_f;

            if (res >= 0) {
                f3 += to_string(res);
                carry_f = 0;
            } else {
                res += 10;
                f3 += to_string(res);
                carry_f = 1;
            }
        }

        reverse(f3.begin(), f3.end());

        int carry = 0;

        if (carry_f)
            carry = 1;
        else
            carry = 0;

        //----------------------------------------

        int min2 = abs((int)n1.size() - (int)n2.size());

        string new_n1, new_n2;

        if (n1.size() < n2.size()) {
            for (int i = 0; i < min2; ++i) {
                new_n1 += '0';
            }
            new_n1 += n1;
            new_n2 = n2;
        } else {
            for (int i = 0; i < min2; ++i) {
                new_n2 += '0';
            }
            new_n2 += n2;
            new_n1 = n1;
        }

        for (int i = 0; i < new_n1.size(); ++i) {

            int number1 = new_n1[new_n1.size()-i-1] - '0';
            int number2 = new_n2[new_n1.size()-i-1] - '0';
            int res = number1 - number2;

            res -= carry;

            if (res >= 0) {
                n3 += to_string(res);
                carry = 0;
            } else {
                res += 10;
                n3 += to_string(res);
                carry = 1;
            }
        }

        reverse(n3.begin(), n3.end());

        result.num = n3;
        result.fraction = f3;

        return result;


}


BigReal & BigReal::operator = (const BigReal& real) {

    this->num = real.num;
    this->fraction = real.fraction;
    this->sign = real.sign;

    return *this;
}

ostream & operator << (ostream &out, const BigReal &real) {
    if (real.sign)
        out << '-';
    out << real.num << '.' << real.fraction << endl;
    return out;
}



