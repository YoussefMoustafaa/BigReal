#include <bits/stdc++.h>

using namespace std;

#define N 7


struct dominoT
{
    int leftDots;
    int rightDots;
    int index;
};

int counts[N] = {0};


void CountDominoNumbers(vector<dominoT>& d)
{

    int n = d.size();
    for (int i = 0; i < n; ++i) {
        counts[d[i].leftDots]++;
        counts[d[i].rightDots]++;
        d[i].index = i;
    }

}


bool FormsDominoChain(vector<dominoT>& d) {
    CountDominoNumbers(d);
    int ones = 0;
    for (int i = 1; i < 7; ++i) {
        if (counts[i] == 1)
            ones++;
    }
    if (ones <= 2)
        return true;
    else
        return false;
}


dominoT getFirstDomino(vector<dominoT>& d)
{
    for (int i = 0; i < d.size(); i++)
    {
        if (counts[d[i].leftDots] % 2) {
            return d[i];
        }
    }

    return d[0];
}

bool vis[1000] = {0};


void printDominos(vector<dominoT>& sol)
{
    int sz = sol.size();
    for (int i = 0; i < sz - 1; i++)
    {
        cout << sol[i].leftDots << "|" << sol[i].rightDots << " - ";
    }
    cout << sol[sz-1].leftDots << "|" << sol[sz-1].rightDots << endl;

}

bool checkConnection(vector<dominoT>& d, int idx, vector<dominoT>& sol)
{
    if (sol.back().rightDots == d[idx].leftDots) {
        return true;
    }
    return false;
}


bool sortDominos(vector<dominoT>& d, int idx, vector<dominoT>& sol);


void FormDominos(vector<dominoT>& d)
{
    dominoT firstDomino = getFirstDomino(d);

    vector<dominoT> sol;

    sol.push_back(firstDomino);
    vis[firstDomino.index] = 1;

    if (sortDominos(d, 0, sol) == false) {
        cout << "No Solution!\n";
    }
    printDominos(sol);
}


bool sortDominos(vector<dominoT>& d, int idx, vector<dominoT>& sol)
{
    if (sol.size() == d.size()) {
        return true;
    }

    if (idx == d.size()) {
        idx = 0;
    }

    if ( vis[d[idx].index] == 1 ) {
        sortDominos(d, ++idx, sol);
    }

    if (checkConnection(d, idx, sol)) {
        sol.push_back(d[idx]);
        vis[d[idx].index] = 1;
        if (idx == d.size()-1 && sol.size() != d.size()) {
            sol.pop_back();
            vis[d[idx].index] = 0;
        }
        sortDominos(d, ++idx, sol);
        return true;
    }

    sortDominos(d, ++idx, sol);
    return true;
}




int main() {

    // vector<dominoT> d = {{1,4}, {2, 6}, {4, 4}, {6, 1}, {4, 3}};

    cout << "Enter number of dominos: ";
    int n;
    cin >> n;
    cout << "Enter your dominos:\n "
            "separate the dots with (|) for example: 2|6 6|3 \n";

    vector<dominoT> d(n);

    string s;
    cin.ignore();
    getline(cin, s);

    int flip = 1;
    int j = 0;

    for (char& i : s) {
        if (isdigit(i) && flip) {
            d[j].leftDots = int(i - '0');
            flip ^= 1;
        } else if (isdigit(i) && !flip) {
            d[j].rightDots = int(i - '0');
            flip ^= 1;
            j++;
        }
    }


    if (FormsDominoChain(d)) {
        cout << "Yes\n";
        FormDominos(d);
    }
    else
        cout << "No\n";

    return 0;
}

// 6
// 2|4 4|5 0|0 5|5 5|0 0|1
