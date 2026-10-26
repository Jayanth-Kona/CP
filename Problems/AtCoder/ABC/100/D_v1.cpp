#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[1002][1002][2][2][2];
ll x[1002] , y[1002] , z[1002];

int main(){
    int n , m ; cin >> n >> m;

    for(int i = 1 ; i <= n ; i++) cin >> x[i] >> y[i] >> z[i];

    if(m == 0){
        cout << 0;
        return 0;
    }

    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){
            for(int s1 : {0 , 1}){
                for(int s2 : {0 , 1}){
                    for(int s3 : {0 , 1}){
                        dp[i][j][s1][s2][s3] = j == 0 ? 0 : -1e18;
                    }
                }
            }
        }
    }

    auto cost = [&](int index , int s1 , int s2 , int s3)->ll{
        return x[index] * (s1 == 0 ? -1 : +1) + y[index] * (s2 == 0 ? -1 : +1) + z[index] * (s3 == 0 ? -1 : +1);
    };

    ll ans = -1e18;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= min(i , m) ; j++){
            for(int s1 : {0 , 1}){
                for(int s2 : {0 , 1}){
                    for(int s3 : {0 , 1}){
                        dp[i][j][s1][s2][s3] = max(dp[i - 1][j][s1][s2][s3] , cost(i , s1 , s2 , s3) + dp[i - 1][j - 1][s1][s2][s3]);
                        if(j == m) ans = max(ans , dp[i][j][s1][s2][s3]);
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}