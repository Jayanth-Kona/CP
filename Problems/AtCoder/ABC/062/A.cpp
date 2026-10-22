#include<bits/stdc++.h>
using namespace std;

int group(int n){
    if(n & 1){
        if(n <= 7) return 1;
        else return 2;
    }
    else{
        if(n >= 8) return 1;
        else if(n >= 4) return 2;
        else return 3;
    }
    return 0;
}

int main(){
    int x , y ; cin >> x >> y;

    if(group(x) == group(y)) cout << "Yes";
    else cout << "No";

    return 0;
}