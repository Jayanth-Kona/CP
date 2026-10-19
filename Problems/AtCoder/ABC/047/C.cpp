#include<bits/stdc++.h>
using namespace std;

int main(){
    string s ; cin >> s;

    int groups = 0;

    for(int i = 0 , j = 0 , n = (int)s.size() ; i < n ; i = j){
        while(j < n && s[i] == s[j]) j++;
        groups += 1;
    }

    cout << groups - 1;

    return 0;
}