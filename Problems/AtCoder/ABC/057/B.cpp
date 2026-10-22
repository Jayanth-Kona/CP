#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , m ; cin >> n >> m;

    vector<array<int , 2>> a(n);
    for(auto &[x , y] : a) cin >> x >> y;

    vector<array<int , 2>> b(m);
    for(auto &[x , y] : b) cin >> x >> y;

    for(auto &[x , y] : a){
        int minID = -1;
        int minDist = 1e9;

        for(int i = 0 ; i < m ; i++){
            int currDist = abs(x - b[i][0]) + abs(y - b[i][1]);
            if(currDist < minDist){
                minID = i + 1;
                minDist = currDist;
            }
        }

        cout << minID << "\n";
    }

    return 0;
}