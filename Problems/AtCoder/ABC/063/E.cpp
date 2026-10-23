#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*

For fixed 'j' find 'i':

range: [i+1 , ... , j]

(ai+1 , ai+2 , ... , aj) / (j - i) >= k
(ai+1 , ai+2 , ... , aj) >= k * (j - i)
(ai+1 - k , ai+2 - k , ... , aj - k) >= 0

let: b = a - k

(ai+1 - k , ai+2 - k , ... , aj - k) >= 0
(bi+1 , bi+2 , ... , aj) >= 0

let: p[i] = sum(b[0..i])

(bi+1 , bi+2 , ... , aj) >= 0
p[j] - p[i] >= 0

p[j] >= p[i]

*/

class SegmentTree{
private:
    int N;
    vector<int> Tree;

public:
    SegmentTree(int N){
        this->N = N;
        Tree.resize(N << 2 | 2 , 0);
    }

    int sum(int qL , int qR){
        return query(1 , 0 , N - 1 , qL , qR);
    }

    int update(int index , int value){
        return update(1 , 0 , N - 1 , index , value);
    }

    int query(int node , int low , int high , int qL , int qR){
        if(low >  qR || high <  qL) return 0;
        if(low >= qL && high <= qR) return Tree[node];
        int mid = (low + high) >> 1;
        return query(node << 1 , low , mid , qL , qR) + query(node << 1 | 1 , mid + 1 , high , qL , qR);
    }

    int update(int node , int low , int high , int index , int value){
        if(low == high) return Tree[node] += value;
        int mid = (low + high) >> 1;
        if(index <= mid) update(node << 1 , low , mid , index , value);
        else update(node << 1 | 1 , mid + 1 , high , index , value);
        return Tree[node] = Tree[node << 1] + Tree[node << 1 | 1];
    }
};

int main(){
    int n , k ; cin >> n >> k;

    vector<ll> p(n + 1);
    p[0] = 0;

    for(int i = 1 ; i <= n ; i++){
        int ai ; cin >> ai;
        int bi = ai - k;
        p[i] = p[i - 1] + bi;
    }

    vector<ll> vals = p;
    sort(vals.begin() , vals.end());
    vals.erase(unique(vals.begin() , vals.end()) , vals.end());

    auto getIndex = [&](ll num) -> int{
        return lower_bound(vals.begin() , vals.end() , num) - vals.begin();
    };

    int m = vals.size();

    SegmentTree seg(m);
    seg.update(getIndex(p[0]) , +1);

    ll ans = 0;

    for(int j = 1 ; j <= n ; j++){
        int index = getIndex(p[j]);

        ans += seg.sum(0 , index);
        seg.update(index , +1);
    }

    cout << ans;

    return 0;
}