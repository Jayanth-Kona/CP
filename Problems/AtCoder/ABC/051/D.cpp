#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> FloydWarshall(int n , vector<array<int , 3>> &edges){
    vector<vector<int>> cost(n + 1 , vector<int>(n + 1 , 1e8));

    for(int i = 1 ; i <= n ; i++){
        cost[i][i] = 0;
    }

    for(auto &[u , v , w] : edges){
        cost[u][v] = cost[v][u] = w;
    }

    for(int k = 1 ; k <= n ; k++){
        for(int u = 1 ; u <= n ; u++) if(k != u){
            for(int v = 1 ; v <= n ; v++) if(k != v && u != v){
                cost[u][v] = min(cost[u][v] , cost[u][k] + cost[k][v]);
            }
        }
    }

    return cost;
}

int main(){
    int n , m ; cin >> n >> m;

    vector<array<int , 3>> edges(m);
    for(auto &[u , v , w] : edges) cin >> u >> v >> w;

    vector<vector<int>> cost = FloydWarshall(n , edges);
    
    int ans = 0;
    
    for(auto &[u , v , w] : edges){
        ans += cost[u][v] < w;
    }

    cout << ans;

    return 0;
}