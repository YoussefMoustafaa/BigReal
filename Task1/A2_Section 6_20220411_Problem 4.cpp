#include <bits/stdc++.h>

using namespace std;


class Prime {
private:
    int N{};
    vector<pair<int, int>> v;
public:
    Prime() {
        cin >> N;
    }
    bool isPrime(int p)
    {
        for (int i = 2; i <= sqrt(p); ++i) {
            if (p % i == 0) {
                return false;
            }
        }
        return true;
    }

    void getPrimes()
    {
        for (int i = 2; i <= N; ++i) {
            v.emplace_back(i, false);
        }

        for (int i = 0; i < v.size(); ++i) {
            if (isPrime(v[i].first)) {
                v[i].second = true;
            }
        }
    }

    friend ostream & operator << (ostream &out, const Prime &p);
};


ostream & operator<< (ostream &out, const Prime &p) {
    for (int i = 0; i < p.v.size(); ++i) {
        if (p.v[i].second)
            out << p.v[i].first << ' ';
    }
    return out;
}




int main() {

    Prime P;
    P.getPrimes();
    cout << P;

    return 0;
}