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
        else if (counts[i] % 2)
            return false;
    }
    if (ones == 2)
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

bool vis[N] = {0};


void printDominos(vector<dominoT>& sol)
{
    for (int i = 0; i < 4; i++)
    {
        cout << sol[i].leftDots << "|" << sol[i].rightDots << " - ";
    }
    cout << sol[4].leftDots << "|" << sol[4].rightDots << endl;
    
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
    if (sol.size() == 5) {
        return true;
    }

    if (idx == 5) {
        idx = 0;
    }

    if ( vis[d[idx].index] == 1 ) {
        sortDominos(d, ++idx, sol);
    }

    if (checkConnection(d, idx, sol)) {
        sol.push_back(d[idx]);
        vis[d[idx].index] = 1;
        sortDominos(d, ++idx, sol);
        return true;
    }

    sortDominos(d, ++idx, sol);
    return true;
}




int main() {

    vector<dominoT> d = {{1,4}, {2, 6}, {4, 4}, {6, 1}, {4, 3}};

    if (FormsDominoChain(d)) {
        cout << "Yes\n";
        FormDominos(d);
    }
    else
        cout << "No\n";

    return 0;
}