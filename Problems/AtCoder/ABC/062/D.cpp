#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n ; cin >> n;

    vector<int> a(3 * n + 1);
    for(int i = 1 ; i <= 3 * n ; i++) cin >> a[i];

    ll psum = 0;
    multiset<int> pset;
    vector<ll> pmax(3 * n + 2 , -1e18);

    for(int i = 1 ; i <= 3 * n ; i++){
        psum += a[i];
        pset.insert(a[i]);

        if(i >= n){
            pmax[i] = max(pmax[i - 1] , psum);

            int mini = *pset.begin();
            pset.extract(mini);
            psum -= mini;
        }
    }

    ll ssum = 0;
    multiset<int> sset;
    vector<ll> smin(3 * n + 2 , +1e18);
    
    for(int i = 3 * n ; i >= 1 ; i--){
        ssum += a[i];
        sset.insert(a[i]);

        if(i <= 2 * n + 1){
            smin[i] = min(smin[i + 1] , ssum);

            int maxi = *sset.rbegin();
            sset.extract(maxi);
            ssum -= maxi;
        }
    }


    ll ans = -1e18;
    for(int i = n ; i <= 2 * n ; i++){
        ans = max(ans , pmax[i] - smin[i + 1]);
    }

    cout << ans;

    return 0;
}