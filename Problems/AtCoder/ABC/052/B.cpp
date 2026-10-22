#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin >> n;
    string s ; cin >> s;

    int x = 0 , maxx = 0;

    for(char ch : s){
        x += ch == 'I' ? +1 : -1;
        maxx = max(maxx , x);
    }

    cout << maxx;

    return 0;
}