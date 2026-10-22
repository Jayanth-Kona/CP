#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , t ; cin >> n >> t;

    int emitted = 0 , till = 0;

    for(int i = 1 ; i <= n ; i++){
        int curr ; cin >> curr;

        emitted += t - max(0 , till - curr);
        till = curr + t;
    }

    cout << emitted;

    return 0;
}