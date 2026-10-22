#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n ; cin >> n;

    ll cost1 = 0 , sum1 = 0; // oddIndex(+ve) evenIndex(-ve)
    ll cost2 = 0 , sum2 = 0; // oddIndex(-ve) evenIndex(+ve)

    for(int i = 1 ; i <= n ; i++){
        ll num ; cin >> num;

        sum1 += num;
        sum2 += num;

        if(i & 1){
            ll add = sum1 > 0 ? 0 : -sum1 + 1;
            sum1 += add;
            cost1 += add;

            ll rem = sum2 < 0 ? 0 : sum2 + 1;
            sum2 -= rem;
            cost2 += rem;
        }
        else{
            ll rem = sum1 < 0 ? 0 : sum1 + 1;
            sum1 -= rem;
            cost1 += rem;

            ll add = sum2 > 0 ? 0 : -sum2 + 1;
            sum2 += add;
            cost2 += add;
        }
    }

    cout << min(cost1 , cost2);

    return 0;
}