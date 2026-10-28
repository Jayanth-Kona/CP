#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n , c ; cin >> n >> c;

    ll ans = 0;
    ll prevCleared = -1e18 , prevNotCleared = 0;

    for(int i = 1 ; i <= n ; i++){
        ll num ; cin >> num;

        ll currCleared = num + max(prevCleared + c , prevNotCleared);
        ll currNotCleared = max(prevCleared , prevNotCleared);

        ans = max({ans , currCleared , currNotCleared});

        prevCleared = currCleared;
        prevNotCleared = currNotCleared;
    }

    cout << ans;

    return 0;
}