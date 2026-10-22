#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin >> n;

    int sum = 0 , no_mod10 = 200;

    for(int i = 1 ; i <= n ; i++){
        int num ; cin >> num;
        sum += num;
        if(num % 10 != 0) no_mod10 = min(no_mod10 , num);
    }

    if(sum % 10 == 0){
        if(no_mod10 != 200) cout << sum - no_mod10;
        else cout << 0;
    }
    else{
        cout << sum;
    }

    return 0;
}