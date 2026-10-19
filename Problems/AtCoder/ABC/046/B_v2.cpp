#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// Time Complexity: O(log(n))

ll mod = (INT_MAX + 1LL);

ll power(ll a , ll b){
    ll res = 1;
    while(b){
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main(){
    ll n , k ; cin >> n >> k;
    
    cout << k * power(k - 1 , n - 1);

    return 0;
}