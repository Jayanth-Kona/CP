## Core Observations

* **$T$ is Irrelevant:** Takahashi has infinite money and unlimited trades per town, so he will put his entire budget $T$ into the single best price difference (`profit`).
* **Target is `profit - 1`:** To reduce Takahashi's total earnings, Aoki just needs to reduce the maximum single-apple `profit` by 1 yen.
* **Cost to Break One Pair is 1:** For any pair achieving the max `profit`, Aoki only needs to spend 1 yen—either increase the `buyPrice` by 1 or decrease the `sellPrice` by 1.
* **No Side Effects:** Increasing a minimum price or decreasing a maximum price shrinks the value range, so it never accidentally creates a new best pair elsewhere.
* **Multiple Pairs Must Be Ordered (High to Low):** Many pairs can achieve the same maximum `profit`, but a pair with higher prices must appear completely before a pair with lower prices. If the smaller `buyPrice` came first, it would combine with the larger `sellPrice` later to create an even bigger `profit`.
* **Non-Overlapping Segments:** Because valid `buyPrice` values must strictly decrease as we move left to right, optimal pairs never cross or overlap. A new group starts the exact moment a number drops below our current `buyPrice`.

---

## Version 1: Distinct Elements (Original Problem)

### Approach

* **Why `cost = 1` per group:** Because all numbers in the array are distinct, each segment's `buyPrice` appears only once, and its matching `sellPrice` (`buyPrice + profit`) can also appear at most once.
* **1-to-1 Pairing:** There are no shared buys or multiple sell choices inside a group. Every time we see `nums[i] - minBuy == profit`, it represents a completely separate, isolated `(buy, sell)` pair.
* **Counting Pairs:** Breaking each isolated pair costs exactly 1 yen. We simply track the running `minBuy` and count how many times the maximum `profit` is achieved.

```cpp
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

```

---

## Version 2: Duplicate Elements Allowed (Follow-Up)

### Approach

**1. Segment Ordering & Grouping**

* Even with duplicates, multiple price pairs giving the maximum `profit` are still completely non-overlapping.
* Every optimal `buyPrice` is a running minimum. As long as numbers stay above or equal to our current `buyPrice`, we stay in the same group.
* The moment we encounter a number strictly smaller than `buyPrice`, the current group closes and a new independent group begins.
* Since groups do not interact, we compute the minimum cost for each group separately and add them to `totalCost`.

**2. How to Compute a Single Group**

* Inside one group, `buyPrice` and `sellPrice` (`buyPrice + profit`) can appear multiple times in any order.
* A valid trade happens whenever a `buyPrice` appears to the left of a `sellPrice`.
* To break all trades in the group, any surviving `sellPrice` must sit strictly to the left of any surviving `buyPrice`.
* This means there is a split point in the group where:
* Everything to the **left** has **no `buyPrice**` (we pay 1 for each `buyPrice` in the prefix).
* Everything to the **right** has **no `sellPrice**` (we pay 1 for each `sellPrice` in the suffix).


* **Sweeping the Split Point:**
* Initially, we set `cost = totalSellOptions` (the cost of deleting all `sellPrice` elements in the group, leaving only buys).
* We then loop through the group, tracking `buyOptions` (buys seen so far on the left) and `totalSellOptions - sellOptions` (sells remaining on the right).
* At every step, we update `cost = min(cost, buyOptions + (totalSellOptions - sellOptions))` to find the cheapest split point (which also naturally checks the extreme of deleting all `buyPrice` elements at the end of the loop).



```cpp
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

    if(profit == 0){
        cout << 0;
        return 0;
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

```