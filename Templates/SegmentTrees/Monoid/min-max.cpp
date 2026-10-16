#include<bits/stdc++.h>
using namespace std;

class Monoid{
public:
    int minIndex;
    int maxIndex;
    int minValue;
    int maxValue;

    Monoid(){
        minIndex = maxIndex = -1;
        minValue = +2e9;
        maxValue = -2e9;
    }

    Monoid(int index , int value){
        minIndex = maxIndex = index;
        minValue = maxValue = value;
    }

    friend Monoid operator+(const Monoid &u , const Monoid &v){
        Monoid uv;
        if(u.minValue < v.minValue){
            uv.minIndex = u.minIndex;
            uv.minValue = u.minValue;
        }
        else{
            uv.minIndex = v.minIndex;
            uv.minValue = v.minValue;
        }
        if(u.maxValue > v.maxValue){
            uv.maxIndex = u.maxIndex;
            uv.maxValue = u.maxValue;
        }
        else{
            uv.maxIndex = v.maxIndex;
            uv.maxValue = v.maxValue;
        }
        return uv;
    }
};

class SegmentTree{
private:
    int N;
    vector<Monoid> Tree;

public:
    SegmentTree(int N , vector<int> &A){
        this->N = N;
        Tree.resize(N << 2 | 2);
        Build(1 , 0 , N - 1 , A);
    }

    Monoid Build(int node , int low , int high , vector<int> &A){
        if(low == high) return Tree[node] = Monoid(low , A[low]);
        int mid = (low + high) >> 1;
        return Tree[node] = Build(node << 1 , low , mid , A) + Build(node << 1 | 1 , mid + 1 , high , A);
    }

    Monoid Query(int node , int low , int high , int qL , int qR){
        if(high < qL || low > qR) return Monoid();
        if(qL <= low && high <= qR) return Tree[node];
        int mid = (low + high) >> 1;
        return Query(node << 1 , low , mid , qL , qR) + Query(node << 1 | 1 , mid + 1 , high , qL , qR);
    }

    Monoid Update(int node , int low , int high , int index , int value){
        if(low == high) return Tree[node] = Monoid(index , value);
        int mid = (low + high) >> 1;
        if(index <= mid) Update(node << 1, low, mid, index, value);
        else Update(node << 1 | 1, mid + 1, high, index, value);
        return Tree[node] = Tree[node << 1] + Tree[node << 1 | 1];
    }

    array<int , 2> minmax(int L , int R){
        Monoid LR = Query(1 , 0 , N - 1 , L , R);
        return {LR.minIndex , LR.maxIndex};
    }

    void Update(int index , int value){
        Update(1 , 0 , N - 1 , index , value);
    }
};

int main(){
    int N ; cin >> N;

    vector<int> A(N);
    for(int &num : A) cin >> num;

    SegmentTree seg(N , A);
    
    auto [i , j] = seg.minmax(0 , N - 1);
    cout << i << " " << j;

    return 0;
}