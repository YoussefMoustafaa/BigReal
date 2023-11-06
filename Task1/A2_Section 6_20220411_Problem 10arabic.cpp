// File: Question10.cpp
// Purpose: words censorship
// Author:Youssef Mostafa Sayed Mohamed
// Section: S6
// ID: 20220411
// TA: Nardeen Mokhless / Maya Ahmed

#include <bits/stdc++.h>
#include <fstream>

using namespace std;

map<string, string> mp;



string censor(string& word)
{
    for (auto it : mp) {
        if (word == it.first)
            return it.second;
    }
    return word;
}


int main() {

    mp.insert(make_pair("فلسطين","فـلـ.سـط.ين"));
    mp.insert(make_pair("غزة","عْـزة"));
    mp.insert(make_pair("حماس","حـ.ما.س"));
    mp.insert(make_pair("قتل","قـ.ـتـ.ل"));
    mp.insert(make_pair("حرب","حـ.ر.ب"));
    mp.insert(make_pair("ارهاب","ار.هـ.اب"));
    mp.insert(make_pair("جهاد","جـ.ها.د"));
    mp.insert(make_pair("صهاينة","صـ.هايـ.نـة"));
    mp.insert(make_pair("عدوان","عـ.د.وان"));
    mp.insert(make_pair("قتلة","قـ.تـ.لة"));
    mp.insert(make_pair("اسرائيل","اسر.ائـ.يل"));
    mp.insert(make_pair("هجرم","هـ.جرم"));
    mp.insert(make_pair("ذبح","ذبـ.ـح"));
    mp.insert(make_pair("قطع","قـ.طـ.ـع"));

    fstream file("text1.txt");
    fstream outFile("text2.txt");

    string line;

    while (getline(file, line))
    {
        string word;

        for (char& i : line) {
            if (i == ' ') {
                outFile << censor(word) << " ";
                word = "";
                continue;
            }

            word += i;

        }

        outFile << censor(word) << " ";
        outFile << endl;
    }

    file.close();
    outFile.close();

    return 0;
}