#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int mod = 1e9 + 7;

int main(){
    ll n , m ; cin >> n >> m;

    ll xsum = 0;
    for(int i = 1 ; i <= n ; i++){
        ll xi ; cin >> xi;
        xsum = (xsum + (2 * i - 1 - n) * xi % mod) % mod;
    }

    ll ysum = 0;
    for(int i = 1 ; i <= m ; i++){
        ll yi ; cin >> yi;
        ysum = (ysum + (2 * i - 1 - m) * yi % mod) % mod;
    }

    cout << (xsum * ysum) % mod;

    return 0;
}


/*

Answer = 

(x2 - x1) * [
    (y₂ − y₁) + (y₃ − y₁) + … + (ym − y₁)
              + (y₃ − y₂) + … + (ym − y₂)
                          + … +
                              + (ym − y{m−1}
]

+

(x3 - x1) * [
    (y₂ − y₁) + (y₃ − y₁) + … + (ym − y₁)
              + (y₃ − y₂) + … + (ym − y₂)
                          + … +
                              + (ym − y{m−1}
]

+

.
.
.

+

(xn − x{n−1}) * [
    (y₂ − y₁) + (y₃ − y₁) + … + (ym − y₁)
              + (y₃ − y₂) + … + (ym − y₂)
                          + … +
                              + (ym − y{m−1}
]

-----------------------------------------------------------------------------------

let ysum = [
    (y₂ − y₁) + (y₃ − y₁) + … + (ym − y₁)
              + (y₃ − y₂) + … + (ym − y₂)
                          + … +
                              + (ym − y{m−1}
]

and

xsum = [
    (x₂ − x₁) + (x₃ − x₁) + … + (xn − x₁)
              + (x₃ − x₂) + … + (xn − x₂)
                          + … +
                              + (xn − x{n−1}
]

Answer = (x2 - x1) * [ysum] + (x3 - x1) * [ysum] + ... + (xn − x{n−1}) * [ysum]
       = ysum * [(x2 - x1) + (x3 - x1) + ... + (xn − x{n−1})]
       = ysum * xsum

-----------------------------------------------------------------------------------

find contributions of each yi:

y1 = -(m - 1)
   = (1 - m) times

y2 = -(m - 2) + 1
   =  (3 - m) times

y3 = -(m - 3) + 2
   = (5 - m) times


Generic Form : yi = (2 * i - 1 - m) times

Therefore, ysum = sigma((2 * i - 1 - m) * yi) , where  1 <= i <= m
Similarly, xsum = sigma((2 * i - 1 - n) * xi) , where  1 <= i <= n

-----------------------------------------------------------------------------------

*/