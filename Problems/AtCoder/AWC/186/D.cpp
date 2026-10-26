#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , m ; cin >> n >> m;

    vector<int> x(n);
    for(int i = 0 ; i < n ; i++) cin >> x[i];
    sort(x.begin() , x.end());

    vector<array<int , 2>> rc(m);
    for(auto &[r , c] : rc) cin >> r >> c;

    vector<long long> dp(n + 1);
    dp[n] = 0;

    for(int i = n - 1 ; i >= 0 ; i--){
        dp[i] = 1e18;
        for(auto &[r , c] : rc){
            int j = upper_bound(x.begin() , x.end() , x[i] + 2LL * r) - x.begin();
            dp[i] = min(dp[i] , c + dp[j]);
        }
    }

    cout << dp[0];

    return 0;
}