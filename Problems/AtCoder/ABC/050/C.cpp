#include<bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

int main(){
    int n ; cin >> n;

    vector<int> freq(n , 0);

    for(int i = 1 ; i <= n ; i++){
        int num ; cin >> num;
        freq[num]++;
    }

    if(n & 1){
        int ways = freq[0] == 1 ? 1 : 0;

        for(int d = 2 ; d < n ; d += 2){
            if(freq[d] == 2){
                ways = (2LL * ways) % mod;
            }
            else{
                ways = 0;
                break;
            }
        }

        cout << ways;
    }
    else{
        int ways = freq[1] == 2 ? 2 : 0;

        for(int d = 3 ; d < n ; d += 2){
            if(freq[d] == 2){
                ways = (2LL * ways) % mod;
            }
            else{
                ways = 0;
                break;
            }
        }

        cout << ways;
    }

    return 0;
}