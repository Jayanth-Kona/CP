#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)

int main(){
    int n , k ; cin >> n >> k;

    int ans = k;
    for(int i = 2 ; i <= n ; i++) ans *= (k - 1);

    cout << ans;

    return 0;
}