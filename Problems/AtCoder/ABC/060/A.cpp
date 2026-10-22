#include<bits/stdc++.h>
using namespace std;

int main(){
    string a , b , c;
    cin >> a >> b >> c;

    if(a.back() == b[0] && b.back() == c[0]) cout << "YES";
    else cout << "NO";

    return 0;
}