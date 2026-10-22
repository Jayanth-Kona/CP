#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n ; cin >> n;

    ll t = sqrtl(1 + 8 * n) / 2;
    if(t * (t + 1) / 2 < n) t++;

    cout << t;

    return 0;
}