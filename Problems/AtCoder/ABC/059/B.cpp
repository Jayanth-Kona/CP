#include<bits/stdc++.h>
using namespace std;

int main(){
    string a  , b; cin >> a >> b;

    if(a.size() == b.size()){
        if(a == b) cout << "EQUAL";
        else cout << (a < b ? "LESS" : "GREATER");
    }
    else{
        cout << (a.size() < b.size() ? "LESS" : "GREATER");
    }

    return 0;
}