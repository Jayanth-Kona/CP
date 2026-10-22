#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin >> n;

    vector<int> a(n);
    for(int &num : a) cin >> num;

    sort(a.begin() , a.end());

    int ans = 0;
    for(int i = 1 ; i < n ; i++) ans += a[i] - a[i - 1];

    cout << ans;

    return 0;
}