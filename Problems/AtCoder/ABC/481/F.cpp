#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;

vector<ll> BFS(int n , int s , vector<vector<array<int, 2>>> &graph){
    vector<ll> num(n + 1);
    num[0] = 0;

    vector<int> rank(n + 1 , -1) , parent(n + 1 , -1) , digit(n + 1 , -1);

    queue<int> queue;
    queue.push(s);
    rank[s] = 1;

    while(queue.empty() == false){
        int k = queue.size();

        vector<int> nodes;

        while(k--){
            int u = queue.front();
            queue.pop();

            for(auto &[v , d] : graph[u]){
                if(rank[v] != -1) continue;
                
                if(parent[v] == -1){
                    digit[v] = d;
                    parent[v] = u;
                    nodes.push_back(v);
                }
                else{
                    if(rank[u] < rank[parent[v]] || (rank[u] == rank[parent[v]] && d < digit[v])){
                        digit[v] = d;
                        parent[v] = u;
                    }
                }
            }
        }

        sort(nodes.begin() , nodes.end() , [&](int u , int v){
            if(rank[parent[u]] == rank[parent[v]]) return digit[u] < digit[v];
            return rank[parent[u]] < rank[parent[v]];
        });

        int newRank = 0;
        for(int i = 0 , j = 0 ; i < (int)nodes.size() ; i = j){
            newRank += 1;
            while(j < (int)nodes.size() && rank[parent[nodes[i]]] == rank[parent[nodes[j]]] && digit[nodes[i]] == digit[nodes[j]]){
                rank[nodes[j]] = newRank;
                num[nodes[j]] = (num[parent[nodes[j]]] * 10 + digit[nodes[j]]) % mod;
                queue.push(nodes[j]);
                j++;
            }
        }

    }

    return num;
}

int main(){
    int n , m ; cin >> n >> m;
    vector<vector<array<int , 2>>> graph(n + 1);

    for(int i = 1 ; i <= m ; i++){
        int u , v , d;
        cin >> u >> v >> d;
        graph[u].push_back({v , d});
    }

    vector<ll> num = BFS(n , 1 , graph);
    for(int i = 2 ; i <= n ; i++) cout << num[i] << "\n";

    return 0;
}