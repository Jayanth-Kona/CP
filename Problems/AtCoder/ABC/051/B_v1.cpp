#include<bits/stdc++.h>
using namespace std;

/*

Brute force : O(K^2)

*/

int main(){
    int k , s ; cin >> k >> s;
    
    int triplets = 0;

    for(int x = 0 ; x <= k ; x++){
        for(int y = 0 ; y <= k ; y++){
            int z = s - y - x;
            if(0 <= z && z <= k) triplets += 1;
        }
    }

    cout << triplets;

    return 0;
}