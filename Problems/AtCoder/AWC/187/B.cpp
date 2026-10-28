#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin >> n;
    string s ; cin >> s;

    int ans = 0;
    for(int i = 0 , j = 0 ; i < n ; i = j){
        while(j < n && s[i] == s[j]) j++;
        if(s[i] == '#') ans = max(ans , j - i);
    }

    cout << ans;

    return 0;
}