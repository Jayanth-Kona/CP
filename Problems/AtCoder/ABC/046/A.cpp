#include<bits/stdc++.h>
using namespace std;

int main(){
    int a , b , c;
    cin >> a >> b >> c;

    cout << set<int>{a , b , c}.size();

    return 0;
}