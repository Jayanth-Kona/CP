#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , m ; cin >> n >> m;

    vector<int> connections(n + 1);
    for(int i = 1 ; i <= m ; i++){
        int u , v ; cin >> u >> v;
        connections[u]++;
        connections[v]++;
    }

    for(int i = 1 ; i <= n ; i++){
        cout << connections[i] << "\n";
    }

    return 0;
}