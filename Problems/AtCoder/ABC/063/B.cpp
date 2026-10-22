#include<bits/stdc++.h>
using namespace std;

int main(){
    string s ; cin >> s;

    int mask = 0;
    
    for(char ch : s){
        if(mask >> ch - 'a' & 1){
            cout << "no";
            return 0;
        }
        else{
            mask |= 1 << ch - 'a';
        }
    }

    cout << "yes";

    return 0;
}