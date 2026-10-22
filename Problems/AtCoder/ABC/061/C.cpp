#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n , k ; cin >> n >> k;

    vector<array<ll , 2>> A(n);
    for(auto &[num , copies] : A) cin >> num >> copies;
        
    sort(A.begin() , A.end());

    for(int i = 0 ; i < n ; i++){
        swap(A[i][0] , A[i][1]);
        if(i > 0) A[i][0] += A[i - 1][0];
    }

    int index = lower_bound(A.begin() , A.end() , array<ll , 2>{k , -1}) - A.begin();
    cout << A[index][1];

    return 0;
}