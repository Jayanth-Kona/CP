#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n ; cin >> n;

    ll a , b ; cin >> a >> b;

    for(int i = 2 ; i <= n ; i++){
        ll p , q ; cin >> p >> q;
        
        ll cm = max((a + p - 1) / p , (b + q - 1) / q);
        
        a = cm * p;
        b = cm * q;
    }

    cout << (a + b);

    return 0;
}

/*

lets inital votes be 'a' and 'b'

votes = a , b
ratio = a : b

lets say 'x' is added to 'a'
         'y' is added to 'b'


votes = a + x , b + y
ratio = P : Q

we want to minimize votes = (a + x) + (b + y)
also, 'P' and 'Q' are co-primes(meaning no common factor between them)


   so,
      (a + x) = cm * P
      (b + y) = cm * Q


    votes = (a + x) + (b + y)
          = (cm * P) + (cm * Q)
          = cm * (P + Q)

    so if we minimize 'common factor',
    eventually votes are minimized

Also given that votes are never decreasing,
    a <= a + x    and   b <= b + y
    a <= cm * P   and   b <= cm * Q
    cm >= a / P   and   cm >= b / Q

    cm = max(ceil(a / P) , ceil(b / Q))

*/