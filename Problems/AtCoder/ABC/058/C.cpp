#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin >> n;

    vector<int> take(26);

    for(int i = 1 ; i <= n ; i++){
        string s ; cin >> s;

        vector<int> curr(26 , 0);
        for(char ch : s) curr[ch - 'a']++;

        if(i == 1) take = curr;
        else for(int j = 0 ; j < 26 ; j++) take[j] = min(take[j] , curr[j]);
    }

    for(int j = 0 ; j < 26 ; j++) cout << string(take[j] , char('a' + j));

    return 0;
}