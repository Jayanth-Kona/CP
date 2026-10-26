#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n , m ; cin >> n >> m;

    vector<ll> x(n) , y(n) , z(n);
    for(int i = 0 ; i < n ; i++) cin >> x[i] >> y[i] >> z[i];

    auto cost = [&](int mask , int i) -> ll{
        int s0 = mask >> 0 & 1 ? +1 : -1;
        int s1 = mask >> 1 & 1 ? +1 : -1;
        int s2 = mask >> 2 & 1 ? +1 : -1;
        return s0 * x[i] + s1 * y[i] + s2 * z[i];
    };

    ll ans = -1e18;
    vector<ll> dp(m + 1 , -1e18);

    for(int mask = 0 ; mask < 8 ; mask++){
        dp[0] = 0;
        for(int j = 1 ; j <= m ; j++) dp[j] = -1e18;

        for(int i = 0 ; i < n ; i++){
            ll val = cost(mask , i);
            for(int j = min(i + 1 , m) ; j >= 1 ; j--) dp[j] = max(dp[j] , val + dp[j - 1]);
        }

        ans = max(ans , dp[m]);
    }

    cout << ans;

    return 0;
}