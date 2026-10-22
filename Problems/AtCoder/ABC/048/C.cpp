#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , x ; cin >> n >> x;

    vector<int> a(n);
    for(int &num : a) cin >> num;

    long long ans = 0;

    for(int i = 1 ; i < n ; i++){
        int sum = a[i - 1] + a[i];
        int extra = max(0 , sum - x);

        int rem = min(extra , a[i]);
        a[i] -= rem;
        extra -= rem;

        ans += rem;

        rem = min(extra , a[i - 1]);
        a[i - 1] -= rem;
        extra -= rem;

        ans += rem;
    }

    cout << ans;

    return 0;
}