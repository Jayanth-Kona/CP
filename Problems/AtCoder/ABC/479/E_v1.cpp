#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*
    Euler Tree + SegmentTree + Offset
    TC: O(N) + O(Q * Log(N)) + O(1)
*/

class SegmentTree{
private:
    int N;
    vector<ll> Tree , Lazy;

public:
    SegmentTree(){
    }

    void Init(int N){
        this->N = N;
        Tree.resize(N << 2 | 2 , 0);
        Lazy.resize(N << 2 | 2 , 0);
    }

    ll Query(int qL , int qR){
        return Query(1 , 0 , N - 1 , qL , qR);
    }

    ll Update(int qL , int qR , ll val){
        return Update(1 , 0 , N - 1 , qL , qR , val);
    }

    ll Query(int node , int low , int high , int qL , int qR){
        if(Lazy[node] != 0){
            Tree[node] += (high - low + 1) * 1LL * Lazy[node];
            if(low != high){
                Lazy[node << 1] += Lazy[node];
                Lazy[node << 1 | 1] += Lazy[node];
            }
            Lazy[node] = 0;
        }

        if(low >  qR || high <  qL) return 0;
        if(low >= qL && high <= qR) return Tree[node];

        int mid = (low + high) >> 1;
        return Query(node << 1 , low , mid , qL , qR) + Query(node << 1 | 1 , mid + 1 , high , qL , qR);
    }

    ll Update(int node , int low , int high , int qL , int qR , ll val){
        if(Lazy[node] != 0){
            Tree[node] += (high - low + 1) * 1LL * Lazy[node];
            if(low != high){
                Lazy[node << 1] += Lazy[node];
                Lazy[node << 1 | 1] += Lazy[node];
            }
            Lazy[node] = 0;
        }

        if(low >  qR || high <  qL) return Tree[node];

        if(low >= qL && high <= qR){
            Tree[node] += (high - low + 1) * 1LL * val;
            if(low != high){
                Lazy[node << 1] += val;
                Lazy[node << 1 | 1] += val;
            }
            return Tree[node];
        }

        int mid = (low + high) >> 1;
        return Tree[node] = Update(node << 1 , low , mid , qL , qR , val) + Update(node << 1 | 1 , mid + 1 , high , qL , qR , val);
    }
};


class Tree{
private:
    int N;
    SegmentTree seg;
    vector<vector<int>> T;
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
        int timer = -1;
        live.resize(N + 1);
        dead.resize(N + 1);
        EulerTour(1 , 0 , timer);

        // Init segmentTree -> build is not reqd as all vals are intially zero
        seg.Init(N);
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
        return seg.Query(live[u] , live[u]);
    }

    void subtreeAdd(int u , int val){
        seg.Update(live[u] , dead[u] , val);
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