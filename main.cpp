#include <bits/stdc++.h>
#include "BigReal.h"

using namespace std;


int main() {
    BigReal n1("999.00");
    BigReal n2("11111.00");
    BigReal n3;
    n3 = n1 + n2;
    cout << n1 + n2;
    return 0;
}
