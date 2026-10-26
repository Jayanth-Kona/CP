#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , m , k;
    cin >> n >> m >> k;

    string s ; cin >> s;

    int bad = 0;
    for(int i = 0 ; i < m - 1 ; i++) k -= s[i] == '1';

    for(int i = m - 1 ; i < n ; i++){
        k -= s[i] == '1';
        bad += k > 0;
        k += s[i - m + 1] == '1';
    }

    cout << bad;

    return 0;
}