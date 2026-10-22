#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll H , W ; cin >> H >> W;

    ll ans = 1e18;

    {
        ll A1 = H * (W / 3);
        ll A2 = H * (W / 3 + min(1LL , W % 3));
        
        if(A1 > 0) ans = min(ans , A2 - A1);
    }

    {
        ll A1 = (H / 3) * W;
        ll A2 = (H / 3 + min(1LL , H % 3)) * W;

        if(A1 > 0) ans = min(ans , A2 - A1);
    }

    for(int i = 1 ; i <= H ; i++){
        ll A1 = (i) * (W);
        ll A2 = (H - i) * (W / 2);
        ll A3 = (H - i) * (W / 2 + W % 2);

        ll minA = min({A1 , A2 , A3});
        ll maxA = max({A1 , A2 , A3});

        if(minA > 0){
            ans = min(ans , maxA - minA);
        }
    }

    for(int i = 1 ; i <= W ; i++){
        ll A1 = (H) * (i);
        ll A2 = (H / 2) * (W - i);
        ll A3 = (H / 2 + H % 2) * (W - i);

        ll minA = min({A1 , A2 , A3});
        ll maxA = max({A1 , A2 , A3});

        if(minA > 0){
            ans = min(ans , maxA - minA);
        }
    }

    cout << ans;

    return 0;
}