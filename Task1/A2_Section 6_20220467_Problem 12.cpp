// File: Question3.cpp
// Purpose: phishing scam detector tool
// Author: Mazen Ehab Abdelmoneim Ali
// Section: S6
// ID: 20220467
// TA: Nardeen Mokhless / Maya Ahmed

#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<std::string, int> phishing_keywords = {
        {"Account", 3},
        {"Alert", 3},
        {"Bank", 3},
        {"Card", 3},
        {"Password", 3},
        {"Update", 3},
        {"Verification", 3},
        {"Login", 3},
        {"Payment", 3},
        {"Security", 3},
        {"Suspicious", 3},
        {"Confirm", 3},
        {"Information", 3},
        {"Urgent", 3},
        {"Verify", 3},
        {"Social Security", 3},
        {"Phishing", 3},
        {"Reward", 3},
        {"Invoice", 2},
        {"Apple", 2},
        {"Microsoft", 2},
        {"PayPal", 2},
        {"Google", 2},
        {"Amazon", 2},
        {"Facebook", 2},
        {"IRS", 2},
        {"Lottery", 2},
        {"Prize", 2},
        {"Account Alert", 2},
        {"Scam", 2},
        {"Free", 2},
        {"Offer", 2},
        {"Important", 1},
        {"Upgrade", 1},
        {"Claim", 1},
        {"Exclusive", 1}
};

    string filename;
    cout << "Enter the name of the text file you want to open: ";
    cin >> filename;

    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error: Could not open input file." << endl;
        return 1;
    }

    string line;
    int totalPoints = 0;
    map<string, int> termCounts;

    while (getline(inputFile, line)) {
        for (const auto& entry : phishing_keywords) {
            string keyword = entry.first;
            int occurrences = 0;
            size_t pos = 0;

            while ((pos = line.find(keyword, pos)) != string::npos) {
                occurrences++;
                pos += keyword.length();
            }

            if (occurrences > 0) {
                totalPoints += occurrences * entry.second;
                termCounts[keyword] += occurrences;
            }
        }
    }


    for (const auto& entry : termCounts) {
        cout << entry.first << " - Occurrences: " << entry.second << " - Points: " << entry.second * phishing_keywords[entry.first] << endl;
    }

    cout << "Total Points: " << totalPoints << endl;

    inputFile.close();
    return 0;
}
// try Phishing.txt to test the tool