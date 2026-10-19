#include<bits/stdc++.h>
using namespace std;

int main(){
    string s ; cin >> s;

    int score = 0;
    int paper = 0 , rock = 0;

    for(char ch : s){
        if(ch == 'p'){
            if(paper < rock){
                paper += 1;
            }
            else{
                rock += 1;
                score -= 1;
            }
        }
        else{
            if(paper < rock){
                paper += 1;
                score += 1;
            }
            else{
                rock += 1;
            }
        }
    }

    cout << score;

    return 0;
}