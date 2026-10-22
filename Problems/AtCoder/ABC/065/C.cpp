#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int mod = 1e9 + 7;

ll Fact(int N){
    ll res = 1;
    for(int num = 1 ; num <= N ; num++) res = (res * num) % mod;
    return res;
}

int main(){
    int N , M ; cin >> N >> M;

    if(N == M){
        cout << (2 * Fact(N) % mod * Fact(M) % mod);
    }
    else if(N == M + 1 || M == N + 1){
        cout << (Fact(N) * Fact(M)) % mod;
    }
    else{
        cout << 0;
    }

    return 0;
}