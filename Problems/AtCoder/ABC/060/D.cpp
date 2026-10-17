#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define FOR(i , n) for(int i = 0 ; i < (int)n ; i++)

int main(){
    int n , w ;
    cin >> n >> w;

    ll minW = 1e18;
    vector<array<ll , 2>> input(n);
    for(auto &[wi , vi] : input){
        cin >> wi >> vi;
        minW = min(minW , wi);
    }

    vector<vector<ll>> buckets(4);
    for(auto [wi , vi] : input) buckets[wi - minW].push_back(vi);

    for(vector<ll> &b : buckets){
        sort(b.rbegin() , b.rend());
        b.insert(b.begin() , 0);
        partial_sum(b.begin() , b.end() , b.begin());
    }

    ll ans = 0;

    FOR(i , buckets[0].size()){
        FOR(j , buckets[1].size()){
            FOR(k , buckets[2].size()){
                FOR(l , buckets[3].size()){
                    ll currW = i * (minW + 0) + j * (minW + 1) + k * (minW + 2) + l * (minW + 3);
                    ll currV = buckets[0][i] + buckets[1][j] + buckets[2][k] + buckets[3][l];

                    if(currW <= w){
                        ans = max(ans , currV);
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}