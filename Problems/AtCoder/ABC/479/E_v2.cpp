#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*
    Euler Tree + Difference Array + Offset
    TC: O(N) + O(N) + O(1)
*/

class Tree{
private:
    int N;
    vector<vector<int>> T;
    vector<ll> diffArray;
    vector<int> live , dead , depth , subtreeSize;

public:
    Tree(int N , vector<array<int , 2>> &edges){
        this->N = N;

        T.resize(N + 1);
        depth.resize(N + 1);
        subtreeSize.resize(N + 1);

        for(auto &[u , v] : edges){
            T[u].push_back(v);
            T[v].push_back(u);
        }

        // do an euler tour
        int timer = 0;
        live.resize(N + 1);
        dead.resize(N + 1);
        EulerTour(1 , 0 , timer);

        // Since queries is done after all updates
        // we can avoid log(n) online updates and can use difference arrays in O(1)
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
    int n ; cin >> n;

    vector<array<int , 2>> edges(n - 1);
    for(auto &[u , v] : edges){
        cin >> u >> v;
    }

    Tree T(n , edges);

    ll val = 1 , offset = 0;

    for(auto &[u , v] : edges){
        if(T.getDepth(u) < T.getDepth(v)) swap(u , v);

        int size_u = T.getSubtreeSize(u);
        int size_v = n - size_u;

        if(size_u > size_v){
            T.subtreeAdd(u , +val);
        }
        else{
            offset += val;
            T.subtreeAdd(u , -val);
        }

        val += 1;
    }

    T.computeDiffArray();

    for(int u = 1 ; u <= n ; u++) cout << (T.nodeValue(u) + offset) << " ";

    return 0;
}

/*

treeNodes = (a , b , c , u , v , f , g)

If an edge (u , v) is deleted, then we will have 2 components,
    c1 = (a , b , c , u)
    c2 = (v , f , g)

    if dist(root , u) < dist(root , v):
        swap(u , v)

    size(u) = subtree(u)
    size(v) = n - size(u)

    if size(u) > size(v):
        then add val to component c1

        so, 
            c1 + val = (a + val , b + val , c + val , d + val)
            c2 = (e , f , g) 

    else:
        offset += val
        then sub val to c1

        so,
            c1 - val = (a - val , b - val , c - val , d - val)
            c2 = (e , f , g)

        because in the end,
            c1 - val + offset = c1 - val + val = c1
            c2 + offset = c2 + val


here offset means --> apply on entire tree

we are forcing to performing operations on lower component c1,
because once edge is deleted,

component c1 is a subtree (when looked from root --> so easy to do some operations)
component c2 is a parent component (it contains all nodes till root top and also other subtree of root, which is hard to compute)

*/