#include<bits/stdc++.h>
using namespace std;

int main(){
    int a , b , c;
    cin >> a >> b >> c;

    if(c % gcd(a , b) == 0) cout << "YES";
    else cout << "NO";

    return 0;
}