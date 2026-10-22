#include<bits/stdc++.h>
using namespace std;

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

    void Add(int u , int v){
        u = Find(u);
        v = Find(v);
        if(u != v){
            if(s[u] < s[v]) swap(u , v);
            p[v] = u;
            s[u] += s[v];
        }
    }
};

int main(){
    int N , K , L;
    cin >> N >> K >> L;

    DisjointSet roadways(N);
    for(int i = 1 ; i <= K ; i++){
        int u , v ; cin >> u >> v;
        roadways.Add(u , v);
    }

    DisjointSet railways(N);
    for(int i = 1 ; i <= L ; i++){
        int u , v ; cin >> u >> v;
        railways.Add(u , v);
    }

    map<array<int , 2> , int> map;
    for(int u = 1 ; u <= N ; u++){
        int ux = roadways.Find(u);
        int uy = railways.Find(u);
        map[{ux , uy}]++;
    }

    for(int u = 1 ; u <= N ; u++){
        int ux = roadways.Find(u);
        int uy = railways.Find(u);
        cout << map[{ux , uy}] << " ";
    }

    return 0;
}