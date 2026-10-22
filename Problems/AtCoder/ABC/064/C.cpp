#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin >> n;

    int mask = 0 , freePick = 0;

    for(int i = 1 ; i <= n ; i++){
        int rating ; cin >> rating;
        
        if(rating >= 3200){
            freePick += 1;
        }
        else{
            int color = rating / 400;
            mask |= 1 << color;
        }
    }

    int total = __builtin_popcount(mask);

    cout << max(1 , total) << " " << (total + freePick);

    return 0;
}