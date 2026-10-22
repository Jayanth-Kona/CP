#include<bits/stdc++.h>
using namespace std;

int main(){
    string s ; cin >> s;

    int a = +1e9 , z = -1e9;

    for(int i = 0 ; i < (int)s.size() ; i++){
        if(s[i] == 'A') a = min(a , i);
        if(s[i] == 'Z') z = max(z , i);
    }

    cout << (z - a + 1);

    return 0;
}