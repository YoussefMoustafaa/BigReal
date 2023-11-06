#include<numeric>
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<deque>
#include<vector>
#include<set>
#include<map>
using namespace std;
bool sortbysecdesc(const pair<string,int> &a,
                   const pair<string ,int> &b)
{
    return a.second>b.second;
}

int main() {
    char c;
    string name;
    int score ;
   vector<pair<string , int > > v;
   cout<<"menu\na - Add a new player and score.\nb - Print the top 10 names and scores to the screen.\nc - enter a player name and output that player’s highest score if it is on the top 10 list\n"
         "or a message if the player’s name has not been input or is not in the top 10.\n";
   while(cin>>c){

       if(c== '0') break;
       else if(c == 'a'){
           cout<<"input the name of the player : \n";
           cin>>name;
           cout<<"input the score of the player : \n";
           cin>>score;
           v.push_back(make_pair(name , score));
       }
       else if(c == 'b'){
           cout<<"the top ten players and their scores :\n";
           sort(v.begin(), v.end(), sortbysecdesc);
           for(int i = 0 ; i < 10; i++){
               cout<<v[i].first<<" "<<v[i].second<<"\n";
           }
       }
       else if(c == 'c'){
           int flag = 0 ;
           cout<<"input the player you want to search for :\n";
           cin>>name;
           sort(v.begin(), v.end(), sortbysecdesc);
           for(int i = 0 ; i < 10; i++){
               if(name == v[i].first){
                   flag = 1;
                   cout<<v[i].second<<endl;
                   break;
               }
           }
           if(flag == 0) {
               for (int i = 10; i < v.size(); i++) {
                   if(name == v[i].first){
                       cout<<"the player’s name has not been in the top 10.\n";
                       flag = 1;
                   }
               }
           }
           if(flag == 0){
               cout<<"the player’s name has not been input.\n";
           }
       }
       cout<<"you can choose another operation or 0 zero to exit\n";
   }
}
