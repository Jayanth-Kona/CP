#include<bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

int main(){
    int n ; cin >> n;

    int Fact = 1;
    for(int num = 1 ; num <= n ; num++) Fact = Fact * 1LL * num % mod;

    cout << Fact;

    return 0;
}