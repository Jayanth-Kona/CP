#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , k ; cin >> n >> k;

    vector<int> y(n);
    for(int &yi : y) cin >> yi;

    int ans = y[0] == k;

    for(int i = 1 ; i < n ; i++){
        if(y[i - 1] == k){
            ans--;
        }
        if(min(y[i - 1] , y[i]) <= k && k <= max(y[i - 1] , y[i])){
            ans++;
        }
    }

    cout << ans;

    return 0;
}