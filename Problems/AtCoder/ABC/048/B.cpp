#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll a , b , x;
    cin >> a >> b >> x;

    cout << (1 + b / x) - (a == 0 ? 0 : 1 + (a - 1) / x);

    return 0;
}