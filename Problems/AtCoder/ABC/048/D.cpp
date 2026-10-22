#include<bits/stdc++.h>
using namespace std;

int main(){
    string s ; cin >> s;

    if(s[0] == s.back()){
        if(s.size() % 2 == 1) cout << "Second";
        else cout << "First";
    }
    else{
        if(s.size() % 2 == 1) cout << "First";
        else cout << "Second";
    }

    return 0;
}

/*

Final state of string would be of form:
    xyxyx (or) xyxy

given that corners cannot be removed,

if s[0] = s.back():
It will stop with at odd length
if s.size() == odd:
    turn = first Player (he cannot make a move)
    winner = second Player 

Similarly reason out else case

*/