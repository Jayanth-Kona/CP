#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*
    Euler Tree + Difference Array
    TC: O(N) + O(N)
*/

class Tree{
private:
    int N;
    vector<vector<int>> T;

    vector<ll> diffArray;
    vector<int> live , dead , depth , subtreeSize;

public:
    Tree(int N , vector<array<int , 2>> &Edges){
        this->N = N;

        T.resize(N + 1);
        depth.resize(N + 1);
        subtreeSize.resize(N + 1);

        for(auto &[u , v] : Edges){
            T[u].push_back(v);
            T[v].push_back(u);
        }

        int timer = 0;
        live.resize(N + 1);
        dead.resize(N + 1);
        EulerTour(1 , 0 , timer);

        diffArray.resize(N << 1 | 2 , 0);
    }

    void EulerTour(int u , int p , int &timer , int d = 0){
        subtreeSize[u] = 1;
        depth[u] = d;

        live[u] = ++timer;

        for(int v : T[u]){
            if(v != p){
                EulerTour(v , u , timer , d + 1);
                subtreeSize[u] += subtreeSize[v];
            }
        }

        dead[u] = timer;
    }

    int getDepth(int u){
        return depth[u];
    }

    int getSubtreeSize(int u){
        return subtreeSize[u];
    }

    ll nodeValue(int u){
        return diffArray[live[u]];
    }

    void subtreeAdd(int u , int val){
        diffArray[live[u]] += val;
        diffArray[dead[u] + 1] -= val;
    }

    void computeDiffArray(){
        for(int i = 1 ; i < (int)diffArray.size() ; i++) diffArray[i] += diffArray[i - 1];
    }
};

int main(){
    int N ; cin >> N;

    vector<array<int , 2>> Edges(N - 1);
    for(auto &[u , v] : Edges){
        cin >> u >> v;
    }

    Tree T(N , Edges);

    ll val = 1;
    
    for(auto &[u , v] : Edges){
        if(T.getDepth(u) < T.getDepth(v)) swap(u , v);

        int size_u = T.getSubtreeSize(u);
        int size_v = N - size_u;

        if(size_u > size_v){
            T.subtreeAdd(u , +val);
        }
        else{
            T.subtreeAdd(1 , +val);
            T.subtreeAdd(u , -val);
        }

        val += 1;
    }

    T.computeDiffArray();

    for(int u = 1 ; u <= N ; u++) cout << T.nodeValue(u) << " ";

    return 0;
}