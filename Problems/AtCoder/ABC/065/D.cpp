#include<bits/stdc++.h>
using namespace std;
using ll = long long;

class DisjointSet{
private:
    vector<int> p , s;

public:
    DisjointSet(int n){
        for(int i = 0 ; i <= n + 1 ; i++){
            p.push_back(i);
            s.push_back(1);
        }
    }

    int Find(int u){
        if(p[u] != u) p[u] = Find(p[u]);
        return p[u];
    }

    bool Add(int u , int v){
        u = Find(u);
        v = Find(v);

        if(u == v) return false;

        if(s[u] < s[v]) swap(u , v);

        p[v] = u;
        s[u] += s[v];

        return true;
    }
};

int main(){
    int n ; cin >> n;

    vector<int> x(n) , y(n);
    for(int i = 0 ; i < n ; i++) cin >> x[i] >> y[i];

    vector<int> xOrder(n);
    iota(xOrder.begin() , xOrder.end() , 0);
    sort(xOrder.begin() , xOrder.end() , [&](int i , int j){
        return x[i] < x[j];
    });

    vector<int> yOrder(n);
    iota(yOrder.begin() , yOrder.end() , 0);
    sort(yOrder.begin() , yOrder.end() , [&](int i , int j){
        return y[i] < y[j];
    });

    vector<array<int , 3>> edges;
    for(int i = 1 , u , v ; i < n ; i++){
        u = xOrder[i];
        v = xOrder[i - 1];
        edges.push_back({x[u] - x[v] , u , v});

        u = yOrder[i];
        v = yOrder[i - 1];
        edges.push_back({y[u] - y[v] , u , v});
    }

    sort(edges.begin() , edges.end());

    DisjointSet dsu(n);
    ll cost = 0 , edgesAdded = 0;

    for(auto &edge : edges){
        auto [c , u , v] = edge;

        if(dsu.Add(u , v) == true){
            cost += c;
            if(++edgesAdded == n - 1) break;
        }
    }

    cout << cost;

    return 0;
}