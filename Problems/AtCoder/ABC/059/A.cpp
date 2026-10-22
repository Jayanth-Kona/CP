#include<bits/stdc++.h>
using namespace std;

int main(){
    string a , b , c;
    cin >> a >> b >> c;

    cout << char(a[0] ^ ' ') << char(b[0] ^ ' ') << char(c[0]  ^ ' ');

    return 0;
}