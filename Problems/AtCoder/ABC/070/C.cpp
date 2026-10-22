#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n ; cin >> n;

    ll intersect = 1;

    for(int i = 1 ; i <= n ; i++){
        ll num ; cin >> num;
        intersect = lcm(intersect , num);
    }

    cout << intersect;

    return 0;
}