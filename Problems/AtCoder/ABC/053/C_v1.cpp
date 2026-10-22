#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n ; cin >> n;

    ll moves = 2 * (n / 11);
    n %= 11;

    if(n >= 6){
        n -= 6;
        moves += 1;
    }

    if(n > 0){
        n -= n;
        moves += 1;
    }

    cout << moves;

    return 0;
}