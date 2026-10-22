#include<bits/stdc++.h>
using namespace std;

/*

Inclusion Exlusion Principle : O(1)

*/

int NCR(int N , int R){
    if(N < R) return 0;

    int res = 1;

    for(int i = 1 ; i <= R ; i++){
        res *= (N - i + 1);
        res /= i;
    }

    return res;
}

int main(){
    int k , s ; cin >> k >> s;

    int triplets = NCR(s + 2 , 2) - (3 * NCR(s - k + 1 , 2) - 3 * NCR(s - 2 * k , 2) + NCR(s - 3 * k - 1 , 2));

    cout << triplets;

    return 0;
}

/*

x1 + x2 + .... + xr = n    and    xi >= 0
solutions = NCR(n + r - 1 , r - 1)

(noneExceeds K) = total - (atleast 1 exceeds K)
                = total - (x:exceeds + y:exceeds + z:exceeds - xy:exceeds + yz:exceeds - zx:exceeds + xyz:exceeds)
                = total - (3 * x:exceeds - 3 * xy:exceeds + xyz:exceeds)

total = ncr(s + 2 , 2)
1 exceeds K = ncr(s - k + 1 , 2)
2 exceeds K = ncr(s - 2k , 2)
3 exceeds K = ncr(s - 3k - 1 , 2)

*/