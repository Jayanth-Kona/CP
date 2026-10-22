#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int mod = 1e9 + 7;

int main(){
    int n ; cin >> n;

    ll factors = 1;

    for(int num = 2 ; num <= n ; num++){
        bool isPrime = true;
        for(int F = 2 ; F * F <= num ; F++){
            if(num % F == 0){
                isPrime = false;
                break;
            }
        }

        if(isPrime){
            int e = 0;
            for(int p = num ; n / p ; p *= num) e += n / p;
            factors = (factors * (e + 1)) % mod;
        }
    }

    cout << factors;

    return 0;
}