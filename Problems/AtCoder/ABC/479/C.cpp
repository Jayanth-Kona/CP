#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n , w ; cin >> n >> w;

    vector<array<ll , 2>> a(n);
    for(auto &[profit , weight] : a) cin >> profit >> weight;

    ll maxP = 0;

    for(int mask = 1 ; mask < (1 << n) ; mask++){
        ll curW = 0;
        ll curP = 0;

        for(int i = 0 ; i < n && curW <= w ; i++){
            if(mask >> i & 1){
                curW += a[i][1];
                curP += a[i][0];
            }
        }

        if(curW <= w) maxP = max(maxP , curP);
    }

    cout << maxP;

    return 0;
}