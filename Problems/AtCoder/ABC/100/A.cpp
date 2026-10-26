#include<bits/stdc++.h>
using namespace std;

int main(){
    int n  , m ; cin >> n >> m;

    if(max(n , m) <= 8) cout << "Yay!";
    else cout << ":(";

    return 0;
}