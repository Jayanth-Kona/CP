#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n ; cin >> n;

    ll moves = 2 * (n / 11) + ((n % 11) + 6 - 1) / 6;

    cout << moves;

    return 0;
}