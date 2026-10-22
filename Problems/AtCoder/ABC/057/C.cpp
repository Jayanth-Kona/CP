#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N ; cin >> N;

    int ans = to_string(N).size();

    for(ll A = 1 ; A * A <= N ; A++){
        if(N % A == 0){
            ll B = N / A;
            ans = min(ans , (int)max(to_string(A).size() , to_string(B).size()));
        }
    }

    cout << ans;

    return 0;
}