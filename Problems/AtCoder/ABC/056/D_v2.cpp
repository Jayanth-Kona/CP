#include<bits/stdc++.h>
using namespace std;

/*

Time Complexity: O(n * k)

*/

int main(){
    int n , k ; cin >> n >> k;

    vector<int> a(n + 1);
    for(int i = 1 ; i <= n ; i++) cin >> a[i];

    vector<vector<bool>> prefix(n + 2 , vector<bool>(k , false)) , suffix = prefix;
    prefix[0][0] = suffix[n + 1][0] = true;

    for(int i = 1 , j = n ; i <= n ; i++ , j--){
        for(int sum = 0 ; sum < k ; sum++){
            prefix[i][sum] = prefix[i - 1][sum];
            if(a[i] <= sum && prefix[i - 1][sum - a[i]]) prefix[i][sum] = true;

            suffix[j][sum] = suffix[j + 1][sum];
            if(a[j] <= sum && suffix[j + 1][sum - a[j]]) suffix[j][sum] = true;
        }
    }

    int ans = 0;

    for(int skip = n ; skip >= 1 ; skip--){
        if(a[skip] < k){

            vector<int> cumul(k , 0);
            for(int sum = 0 ; sum < k ; sum++){
                cumul[sum] = suffix[skip + 1][sum] + (sum > 0 ? cumul[sum - 1] : 0);
            }

            int isReqd = false;

            for(int psum = 0 ; psum < k ; psum++){
                if(prefix[skip - 1][psum]){
                    int lb = k - psum - a[skip];
                    int ub = k - psum - 1;
                    
                    int ssum_exists = cumul[ub] - (lb > 0 ? cumul[lb - 1] : 0);

                    if(ssum_exists > 0){
                        isReqd = true;
                        break;
                    }
                }
            }

            if(!isReqd) ans++;
        }
    }

    cout << ans;

    return 0;
}


/*

psum + ssum + a[i] >= k
ssum >= k - psum - a[i]

psum + ssum < k
ssum < k - psum
sum <= k - psum - 1

ssum = [max(0 , k - psum - a[i]) , k - psum - 1]

*/