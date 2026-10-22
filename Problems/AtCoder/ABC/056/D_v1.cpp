#include<bits/stdc++.h>
using namespace std;

/*

Time Complexity: O(n * k * log(n))

*/

bool isReqd(int skip , int k , vector<int> &a){
    if(a[skip] >= k) return true;

    vector<bool> canMake(k + 1 , false);
    canMake[0] = true;

    for(int i = 0 ; i < (int)a.size() ; i++){
        if(i == skip) continue;
        else for(int sum = k ; sum >= a[i] ; sum--) if(canMake[sum - a[i]]) canMake[sum] = true;
    }

    for(int sum = k - a[skip] ; sum < k ; sum++) if(canMake[sum] == true) return true;

    return false;
}

int main(){
    int n , k ; cin >> n >> k;

    vector<int> a(n);
    for(int &num : a) cin >> num;
    sort(a.begin() , a.end());

    int low = 0 , high = n - 1;
    int ans = -1;
    
    while(low <= high){
        int mid = (low + high) >> 1;

        if(isReqd(mid , k , a) == false) low = (ans = mid) + 1;
        else high = mid - 1;
    }
    
    cout << (ans + 1);

    return 0;
}