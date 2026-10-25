#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin >> n;

    int nextID = 0;
    map<string , int> userID;

    for(int i = 1 ; i <= n ; i++){
        string user ; cin >> user;
        if(!userID.count(user)) userID[user] = ++nextID;
        cout << userID[user] << "\n";
    }

    return 0;
}