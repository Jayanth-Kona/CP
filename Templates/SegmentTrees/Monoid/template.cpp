#include<bits/stdc++.h>
using namespace std;
using ll = long long;

class Monoid{
public:
    ll sum;

    Monoid(ll num = 0){
        sum = num;
    }

    friend Monoid operator+(const Monoid &u , const Monoid &v){
        Monoid uv;
        uv.sum = u.sum + v.sum;
        return uv;
    }
};

class SegmentTree{
private:
    vector<Monoid> Tree;

public:
    SegmentTree(int N , vector<int> &A){
        Tree.resize(N << 2 | 2);
        Build(1 , 0 , N - 1 , A);
    }

    Monoid Build(int node , int low , int high , vector<int> &A){
        if(low == high) return Tree[node] = Monoid(A[low]);
        int mid = (low + high) >> 1;
        return Tree[node] = Build(node << 1 , low , mid , A) + Build(node << 1 | 1 , mid + 1 , high , A);
    }

    Monoid Query(int node , int low , int high , int qL , int qR){
        if(high < qL || low > qR) return Monoid();
        if(qL <= low && high <= qR) return Tree[node];
        int mid = (low + high) >> 1;
        return Query(node << 1 , low , mid , qL , qR) + Query(node << 1 | 1 , mid + 1 , high , qL , qR);
    }

    Monoid update(int node , int low , int high , int index , int val){
        if(low == high) return Tree[node] = Monoid(val);
        int mid = (low + high) >> 1;
        if(index <= mid) update(node << 1, low, mid, index, val);
        else update(node << 1 | 1, mid + 1, high, index, val);
        return Tree[node] = Tree[node << 1] + Tree[node << 1 | 1];
    }
};

int main(){
    cout << "let's go !!" << endl;
}