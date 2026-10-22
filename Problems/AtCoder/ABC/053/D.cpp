#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin >> n;

    map<int , int> map;
    for(int i = 1 ; i <= n ; i++){
        int num ; cin >> num;
        map[num]++;
    }

    int even = 0 , odd = 0;
    for(auto [num , freq] : map){
        if(freq & 1) odd++;
        else even++;
    }

    cout << even + odd - (even & 1);

    return 0;
}