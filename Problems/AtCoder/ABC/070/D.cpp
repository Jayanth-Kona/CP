#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> BFS(int n , int s , vector<vector<array<int, 2>>> &graph){
    vector<ll> dist(n + 1 , 0);
    dist[s] = 0;
    
    queue<array<int , 2>> queue;
    queue.push({s , -1});

    while(queue.empty() == false){
        auto [u , p] = queue.front();
        queue.pop();

        for(auto &[v , duv] : graph[u]){
            if(v != p){
                dist[v] = duv + dist[u];
                queue.push({v , u});
            }
        }
    }
    
    return dist;
}

int main(){
    int n ; cin >> n;
    vector<vector<array<int , 2>>> graph(n + 1);

    for(int i = 1 ; i <= n - 1 ; i++){
        int u , v , w;
        cin >> u >> v >> w;
        graph[u].push_back({v , w});
        graph[v].push_back({u , w});
    }

    int q , k ; cin >> q >> k;

    vector<ll> distK = BFS(n , k , graph);

    for(int i = 1 ; i <= q ; i++){
        int u , v ; cin >> u >> v;
        cout << distK[u] + distK[v] << "\n";
    }

    return 0;
}