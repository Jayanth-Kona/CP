#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll s , c ; cin >> s >> c;

    ll use2c = min(s , c / 2); // s + c + c
    ll use4c = (c - 2 * use2c) / 4; // (s = c + c) + c + c

    cout << use2c + use4c;

    return 0;
}