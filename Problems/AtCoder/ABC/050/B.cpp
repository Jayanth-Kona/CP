#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n ; cin >> n;

    ll sum = 0;
    vector<int> t(n + 1);

    for(int i = 1 ; i <= n ; i++){
        cin >> t[i];
        sum += t[i];
    }

    int m ; cin >> m;

    for(int i = 1 ; i <= m ; i++){
        int p , x ; cin >> p >> x;
        cout << (sum - t[p] + x) << "\n";
    }

    return 0;
}