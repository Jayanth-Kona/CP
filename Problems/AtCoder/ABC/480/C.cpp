#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , k , t;
    cin >> n >> k >> t;

    vector<int> a;
    for(int i = 1 ; i <= n ; i++){
        int num ; cin >> num;
        if(num <= t) a.push_back(num);
    }

    sort(a.begin() , a.end());
    if(a.empty() || a.back() != t) a.push_back(t);

    int ans = 0 , prev = 0;

    for(int curr : a){
        int gap = max(0 , curr - prev);
        int times = (gap + k - 1) / k;

        prev += times * k;
        ans  += times;

        prev = max(prev , curr + k);
    }

    cout << ans;

    return 0;
}