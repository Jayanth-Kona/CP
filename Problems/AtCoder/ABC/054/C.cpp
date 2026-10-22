#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , m ; cin >> n >> m;

    vector<int> edge(n + 1 , 0);

    for(int i = 1 ; i <= m ; i++){
        int u , v ; cin >> u >> v;
        edge[u] |= 1 << v;
        edge[v] |= 1 << u;
    }

    vector<int> path(n);
    iota(path.begin() , path.end() , 1);

    int ans = 0;

    do{
        int good = 1;

        for(int i = 1 ; i < n && good ; i++){
            int u = path[i - 1];
            int v = path[i];
            good &= (edge[u] >> v & 1);
        }

        ans += good;

    }while(next_permutation(path.begin() + 1 , path.end()));

    cout << ans;

    return 0;
}