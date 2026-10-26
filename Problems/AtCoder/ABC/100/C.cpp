#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin >> n;

    int minOp1 = 1e9 , minOp2 = 1e9 , sum = 0;

    for(int i = 1 ; i <= n ; i++){
        int num ; cin >> num;

        int op = 0;
        while(num > 0 && num % 2 == 0){
            op += 1;
            num /= 2;
        }

        sum += op;
    }

    cout << sum;

    return 0;
}