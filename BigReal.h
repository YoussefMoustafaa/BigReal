#ifndef BIGREAL_A2_BIGREAL_H
#define BIGREAL_A2_BIGREAL_H

#include <bits/stdc++.h>

using namespace std;


class BigReal {
private:
    string num;
    string fraction;
    int sign{};  // sign = 0
public:
    BigReal(double realNumber = 0.0);
    BigReal(string realNumber);
    BigReal(const BigReal &real);
    BigReal(long long n);
    int size();
    BigReal operator + (BigReal &real);
    BigReal operator - (BigReal &real);
    BigReal & operator = (const BigReal& real);
    bool operator > (const BigReal &real);
    bool operator < (const BigReal &real);
    bool operator == (const BigReal &real);
    bool operator != (const BigReal &real);
    friend ostream& operator << (ostream& out, const BigReal& real);
};


#endif //BIGREAL_A2_BIGREAL_H
