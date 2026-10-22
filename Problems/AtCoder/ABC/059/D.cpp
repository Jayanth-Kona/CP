#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll a , b ; cin >> a >> b;

    if(abs(a - b) <= 1) cout << "Brown";
    else cout << "Alice";

    return 0;
}