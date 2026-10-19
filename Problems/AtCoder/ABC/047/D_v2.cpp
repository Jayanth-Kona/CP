#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , t ; cin >> n >> t;

    vector<int> nums(n);
    for(int &num : nums) cin >> num;

    int minBuy = nums[0] , profit = 0;

    for(int i = 1 ; i < n ; i++){
        profit = max(profit , nums[i] - minBuy);
        minBuy = min(minBuy , nums[i]);
    }

    int totalCost = 0;
    int buyAt = 0 , buyPrice = nums[0];

    for(int i = 1 ; i <= n ; i++){
        if(i == n || nums[i] < buyPrice){

            int sellPrice = buyPrice + profit;
            int totalSellOptions = 0;

            for(int j = buyAt ; j < i ; j++){
                if(nums[j] == sellPrice){
                    totalSellOptions += 1;
                }
            }

            int cost = totalSellOptions;
            int buyOptions = 0 , sellOptions = 0;

            for(int j = buyAt ; j < i ; j++){
                if(nums[j] == sellPrice){
                    sellOptions += 1;
                }

                cost = min(cost , buyOptions + (totalSellOptions - sellOptions));

                if(nums[j] == buyPrice){
                    buyOptions += 1;
                }
            }

            totalCost += cost;

            if(i < n){
                buyAt = i;
                buyPrice = nums[i];
            }
        }
    }

    cout << totalCost;

    return 0;
}