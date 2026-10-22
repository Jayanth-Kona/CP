#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , a , b;
    cin >> n >> a >> b;

    long long ans = 0;

    int prev ; cin >> prev;

    for(int i = 2 ; i <= n ; i++){
        int curr ; cin >> curr;

        int d = curr - prev;
        ans += min((curr - prev) * 1LL * a , 1LL * b);

        prev = curr;
    }

    cout << ans;

    return 0;
}