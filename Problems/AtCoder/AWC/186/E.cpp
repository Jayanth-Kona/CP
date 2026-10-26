#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n , m ; cin >> n >> m;

    vector<int> a(n + 1);
    for(int i = 1 ; i <= n ; i++) cin >> a[i];

    vector<int> indegree(n + 1 , 0);
    vector<vector<int>> graph(n + 1);
    for(int i = 1 ; i <= m ; i++){
        int u , v ; cin >> u >> v;
        graph[u].push_back(v);
        indegree[v]++;
    }

    vector<ll> dp(n + 1 , 0);

    queue<int> queue;
    for(int u = 1 ; u <= n ; u++){
        if(indegree[u] == 0){
            queue.push(u);
        }
    }

    int tot = 0;

    while(queue.empty() == false){
        int u = queue.front();
        queue.pop();

        tot += 1;

        for(int v : graph[u]){
            dp[v] = max(dp[v] , dp[u] + a[u]);
            if(--indegree[v] == 0) queue.push(v);
        }
    }

    for(int u = 1 ; u <= n ; u++) dp[u] += a[u];

    if(tot == n){
        cout << *max_element(dp.begin() + 1 , dp.end());
    }
    else{
        cout << "-1";
    }

    return 0;
}