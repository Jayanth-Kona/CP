#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n , m ; cin >> n >> m;

    vector<int> a(n);
    for(int &num : a) cin >> num;

    ll ans = -1e18 , sum  = 0;

    for(int i = 0 ; i < 2 * n ; i++){
        sum += a[i % n];
        if(i >= m  - 1){
            ans = max(ans , sum);
            sum -= a[(i - m + 1 + 2 * n) % n];
        }
    }

    cout << ans;

    return 0;
}