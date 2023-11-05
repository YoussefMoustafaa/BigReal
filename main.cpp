#include <bits/stdc++.h>
#include "BigReal.h"

using namespace std;


int main() {
//    BigReal n1("15.39");
//    BigReal n2("39.15");
    BigReal n1 ("11.9000000000000000000000000000000001");
    BigReal n2 ("2333333333339.1134322222222292000000000000000000");
    //                     2333333333351.0134322222222292000000000000000001
    BigReal n3 = n1 + n2;
    cout << n3;
    n3 = n3 + BigReal (0.9);
    return 0;
}
