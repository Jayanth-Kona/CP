#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n , q ; cin >> n >> q;

    vector<ll> L(n + 1);
    L[1] = 1e12;
    for(int i = 2 ; i <= n ; i++) cin >> L[i];

    vector<ll> R(n + 1);
    R[n] = 1e12;
    for(int i = 1 ; i <= n - 1 ; i++) cin >> R[i];

    vector<ll> minSuffix_L(n + 2);
    minSuffix_L[n + 1] = 1e12;
    for(int i = n ; i >= 1 ; i--) minSuffix_L[i] = min(minSuffix_L[i + 1] , L[i]);

    vector<ll> minPrefix_R(n + 2);
    minPrefix_R[0] = 1e12;
    for(int i = 1 ; i <= n ; i++) minPrefix_R[i] = min(minPrefix_R[i - 1] , R[i]);

    while(q--){
        int S , T ; cin >> S >> T;

        if(S < T){
            cout << min(L[S] + minPrefix_R[S - 1] , R[S]) << '\n';
        }
        else{
            cout << min(R[S] + minSuffix_L[S + 1] , L[S]) << '\n';
        }
    }

    return 0;
}

/*

    S ----> T

Case 1: SL  [S]  SR  [T]

    moveL = SL + minPrefix_R[S - 1]
    moveR = SR
    ans = min(moveL , moveR)

Case 2: [T]  SL  [S]   SR

    moveL = SL
    moveR = SR + minSuffix_L[S + 1]
    ans = min(moveL , moveR)

*/