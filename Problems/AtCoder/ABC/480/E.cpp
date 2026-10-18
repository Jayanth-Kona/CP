#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll find_max_d(ll a , ll len , ll n){
    ll min_d = 1 , max_d = 1e9;
    ll ans_d = 0;

    while(min_d <= max_d){
        ll d = (min_d + max_d) >> 1;
        ll prod = 1;

        for(int i = 1 ; i <= len && prod <= n ; i++){
            ll term = a + (i - 1) * d;
            if(prod <= n / term){
                prod *= term;
            }
            else{
                prod = n + 1;
            }
        }

        if(prod <= n){
            ans_d = d;
            min_d = d + 1;
        }
        else{
            max_d = d - 1;
        }
    }

    return ans_d;
}

ll find_max_a(ll len , ll n){
    ll min_a = 1 , max_a = 1e6;
    ll ans_a = 0;

    while(min_a <= max_a){
        ll a = (min_a + max_a) >> 1;
        if(find_max_d(a , len , n) != 0){
            ans_a = a;
            min_a = a + 1;
        }
        else{
            max_a = a - 1;
        }
    }

    return ans_a;
}

int main(){
    ll n ; cin >> n;
    ll minprod = 2;

    ll ans = 0;

    for(int len = 3 ; len <= 19 ; len++){
        minprod *= len;
        if(minprod > n) break;
        
        ll max_a = find_max_a(len , n);

        for(ll a = 1 ; a <= max_a ; a++) ans += find_max_d(a , len , n);
    }

    cout << ans;

    return 0;
}

/*

Observations:
-------------------------------------------------------------------------------------------------------

n <= 1e18
AP = a , a + d , a + 2d , ....

For an any AP sequence we need: (a , d , len)
so that, we can verify/build a sequence: a * (a + d) * (a + 2d) * .... * (a + (len - 1) * d) <= n

Here all 3 are unknowns !!
-------------------------------------------------------------------------------------------------------

Minimum possible AP(a: 1 , d: 1 , len: ?) = 1 , 2 , 3 , 4 , .... 

Given: prod <= n
1 * 2 * 3 * 4 * .... * x <= n
Factorial(x) <= n
x = 19 (atmax)

which means, any AP sequence length is atmost 19

So can we fix len? in range [3 , 19]
yes!
-------------------------------------------------------------------------------------------------------

Now we still dont know about (a , d)
And its obvious we cant try all (a , d)

What if we can fix either of 'a' and 'd'?

Since minlength = 3
Consider smallest possible AP --> a , a + d , a + 2d

prod = (a) * (a + d) * (a + 2d) <= n


Try to find limits of 'a' and 'd', by minimizing the other:

a^3 <= n (roughly)
a <= (n)^1/3
a <= 1e6

(or)

d^2 <= n (roughly)
d <= (n)^1/2
d <= 1e9
-------------------------------------------------------------------------------------------------------

now we saw that,
    we can have an AP with first term  as: 1e6 (atmost)
    we can have an AP with common diff as: 1e9 (atmost)
    

    if we fix a in the range [1 , 1e6]:
        sequences += find maximum 'd' such the prod(a , len) <= n

    TC: max_a * log(max_d)
        1e6   * log(1e9)
        30    * 1e6
       ~1e7
    
        Instead of taking max_a = 1e6 (which is for n = 1e18)
        find we can find max_a by binary search with prod(d , len) <= n


    if we fix d in the range [1 , 1e9]:
        sequences += find maximum 'a' such the prod(d , len) <= n

    TC: max_d * log(max_a)
        1e9   * log(1e6)
        1e9   * 20
       ~1e11

       Instead of taking max_d = 1e9 (which is for n = 1e18)
       find we can find max_d by binary search with prod(a , len) <= n
-------------------------------------------------------------------------------------------------------

Conclusion: Its feasible to fix 'a' and count AP's by maximum possible value of 'd', per length.
    
-------------------------------------------------------------------------------------------------------

*/