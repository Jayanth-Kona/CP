#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , t ; cin >> n >> t;

    vector<int> nums(n);
    for(int &num : nums) cin >> num;

    int cost = 0;
    int minBuy = nums[0] , profit = 0;

    for(int i = 1 ; i < n ; i++){
        if(nums[i] - minBuy > profit){
            profit = nums[i] - minBuy;
            cost = 1;
        }
        else if(nums[i] - minBuy == profit){
            cost += 1;
        }
        minBuy = min(minBuy , nums[i]);
    }

    cout << cost;

    return 0;
}