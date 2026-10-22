#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

int main(){
    int n , m;
    cin >> n >> m;

    vector<array<int , 3>> edges(m);
    for(auto &[u , v , w] : edges) cin >> u >> v >> w;

    vector<ll> dist(n + 1 , INF);
    dist[1] = 0;

    set<int> affectedNodes;

    for(int iter = 1 ; iter <= n ; iter++){
        bool relaxed = false;

        for(auto &[u , v , w] : edges){
            if(dist[u] != INF && dist[u] - w < dist[v]){
                dist[v] = dist[u] - w;
                relaxed = true;

                if(iter == n) affectedNodes.insert(v);
            }
        }

        if(relaxed == false) break;
    }

    if(affectedNodes.empty()){
        cout << -dist[n];
    }
    else{
        vector<vector<int>> Graph(n + 1);
        for(auto &[u , v , w] : edges) Graph[u].push_back(v);

        vector<bool> cycleNode(n + 1 , false);

        function<void(int)> markCycleNodes = [&](int u){
            cycleNode[u] = true;

            for(int v : Graph[u]){
                if(cycleNode[v] == false){
                    markCycleNodes(v);
                }
            }
        };

        for(int node : affectedNodes){
            if(cycleNode[node] == false){
                markCycleNodes(node);
            }
        }

        if(cycleNode[n] == true){
            cout << "inf";
        }
        else{
            cout << -dist[n];
        }
    }

    return 0;
}