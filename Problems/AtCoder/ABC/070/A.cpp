#include<bits/stdc++.h>
using namespace std;

int main(){
    int num ; cin >> num;

    if(num % 10 == num / 100) cout << "Yes";
    else cout << "No";
    
    return 0;
}