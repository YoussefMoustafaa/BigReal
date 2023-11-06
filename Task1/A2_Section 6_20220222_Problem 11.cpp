// File: Question11.cpp
// Purpose: compare between words or characters
// Author: Omar Ashraf Zakaria
// Section: S6
// ID: 20220222
// TA: Nardeen Mokhless / Maya Ahmed
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
vector<string>File_To_String(string filename){
    vector<string>v;
    string text;
    ifstream file(filename);
    //push the content of the file in a vector
    while (getline(file,text)){
        v.push_back(text);
    }
    return v;
};
void Char_By_Char_Comparison(vector<string>f1,vector<string>f2) {
    bool result = true;
    int size = min(f1.size(), f2.size());
    //check if the characters in vector 1 equals the characters in vector 2
    for (int i = 0; i < size; ++i) {
        int Smaller_String = min(f1[i].size(), f2[i].size());
        for (int j = 0; j < Smaller_String; ++j) {
            if (f1[i][j] != f2[i][j]) {
                cout << "The difference between the files in line " << i + 1 << " at the character number " << j + 1
                     << "\n" << f1[i][j] << " is " << f2[i][j] << " in the second file \n";
                result = false;
                break;
            }
        }
        if (!result)
            break;
    }
    if(result)
        cout<<"The files are identical \n";
}
void Word_By_Word_Comparison(vector<string>f1,vector<string>f2){
    bool result = true;
    int size=min(f1.size(),f2.size());
    vector<string>v1,v2;
    for (int i = 0; i < size; ++i) {
        string word;
        // Break the lines into words
        stringstream s1(f1[i]),s2(f2[i]);
        // to push individual words
        while (s1>>word)
            v1.push_back(word);
        while (s2>>word)
            v2.push_back(word);
        int Smaller_String= min(v1.size(),v2.size());
        //check if the words in vector 1 equals the words in vector 2
        for (int j = 0; j < Smaller_String; ++j) {
            if (v1[j]!=v2[j]){
                cout<<"At line "<<i+1<<", the difference between the files is :\nIn the first file the word is "<<v1[j]<<", but in the second one the word is "<<v2[j]<<"\n";
                result = false;
                break;
            }
        }
        if(!result)
            break;
    }
    if(result)
        cout<<"The files are identical \n";
}
int main() {
    string name1,name2;
    int choice;
    cout<<"Enter the name of the first file : \n";
    cin>>name1;
    cout<<"Enter the name of the second file : \n";
    cin>>name2;
    cout<<"which one do you want :\n"
          "1- character by character comparison\n"
          "2- word by word comparison \n";
    cin>>choice;
    if(choice==1)
        Char_By_Char_Comparison(File_To_String(name1), File_To_String(name2));
    if(choice==2)
        Word_By_Word_Comparison(File_To_String(name1), File_To_String(name2));
}