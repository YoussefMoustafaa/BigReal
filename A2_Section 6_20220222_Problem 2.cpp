// File: Question2.cpp
// Purpose: male and female speech
// Author: Omar Ashraf Zakaria
// Section: S6
// ID: 20220222
// TA: Nardeen Mokhless / Maya Ahmed
#include <iostream>
using namespace std;
int main() {
    vector<string>v;
    cout<<"please enter your text : \n";
    string line;
    getline(cin ,line);
    string s ="";
    for (int i = 0; i < size(line); ++i) {
        if(line[i]==' '){
            v.push_back(s);
            s="";
        }
        else{
            s+=line[i];
        }
    }
    v.push_back(s);
    for(int i = 0 ; i < v.size() ;i++){
        s = v[i];
        if(s == "He" || s == "He," || s == "He."){
            cout<<"She or "<<s<<" ";
        }
        else if(s == "he" || s == "he," || s == "he." ){
            cout<<"she or "<<s<<" ";
        }
        else if(s == "him" || s == "him," || s == "him."){
            cout<<"her or "<<s<<" ";
        }
        else if(s == "Him" || s == "Him," || s == "Him."){
            cout<<"Her or "<<s<<" ";
        }
        else if(s == "his" || s == "his," || s == "his."){
            cout<<"her or "<<s<<" ";
        }
        else if(s == "His" || s == "His," || s == "His."){
            cout<<"Her or "<<s<<" ";
        }
        else if(s == "She" || s == "She," || s == "She."){
            cout<<"He or "<<s<<" ";
        }
        else if(s == "she" || s == "she," || s == "she."){
            cout<<"he or "<<s<<" ";
        }
        else if(s == "her" || s == "her," || s == "her."){
            cout<<"him or "<<s<<" ";
        }
        else if(s == "Her" || s == "Her," || s == "Her."){
            cout<<"Him or "<<s<<" ";
        }
        else if(s == "her" || s == "her," || s == "her."){
            cout<<"his or "<<s<<" ";
        }
        else if(s == "Her" || s == "Her," || s == "Her."){
            cout<<"His or "<<s<<" ";
        }
        else{
            cout<<s<<" ";
        }
    }
}
