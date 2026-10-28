#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*
very bored so solved it this way !!

But can be made optimal: I have used lazy even for point updates,
                         and may be some observations/optimaztions exists.
                         Idk, haven't thought much about this problem
*/

class SegmentTree{
private:
      int N;
      vector<ll> Tree , Lazy;

public:
    SegmentTree(vector<int> &nums){
        N = nums.size();
        Tree.resize(N << 2 | 2 , 0);
        Lazy.resize(N << 2 | 2 , 0);
        build(1 , 0 , N - 1 , nums);
    }

    ll merge(ll a , ll b){
        return a + b;
    }

    ll reject(){
        return 0;
    }

    ll build(int node , int low , int high , vector<int> &nums){
        if(low == high) return Tree[node] = nums[low];
        int mid = (low + high) >> 1;
        return Tree[node] = merge(build(node << 1 , low , mid , nums) , build(node << 1 | 1 , mid + 1 , high , nums));
    }

    ll Sum(int ql , int qr){
        return query(1 , 0 , N - 1 , ql , qr);
    }

    void Add(int ql , int qr , int val){
        update(1 , 0 , N - 1 , ql , qr , val);
    }

    ll query(int node , int low , int high , int ql , int qr){
        if(Lazy[node] != 0){
            Tree[node] += (high - low + 1) * 1LL * Lazy[node];
            if(low != high){
                Lazy[node << 1] += Lazy[node];
                Lazy[node << 1 | 1] += Lazy[node];
            }
            Lazy[node] = 0;
        }

        if(low >  qr || high <  ql) return reject();
        if(low >= ql && high <= qr) return Tree[node];

        int mid = (low + high) >> 1;
        return merge(query(node << 1 , low , mid , ql , qr) , query(node << 1 | 1 , mid + 1 , high , ql , qr));
    }



    ll update(int node , int low , int high , int ql , int qr , int val){
        if(Lazy[node] != 0){
            Tree[node] += (high - low + 1) * 1LL * Lazy[node];
            if(low != high){
                Lazy[node << 1] += Lazy[node];
                Lazy[node << 1 | 1] += Lazy[node];
            }
            Lazy[node] = 0;
        }

        if(low >  qr || high <  ql) return Tree[node];

        if(low >= ql && high <= qr){
            Tree[node] += (high - low + 1) * 1LL * val;
            if(low != high){
                Lazy[node << 1] += val;
                Lazy[node << 1 | 1] += val;
            }
            return Tree[node];
        }

        int mid = (low + high) >> 1;
        return Tree[node] = merge(update(node << 1 , low , mid , ql , qr , val) , update(node << 1 | 1 , mid + 1 , high , ql , qr , val));
    }

};

int main(){
    int n , q ; cin >> n >> q;

    vector<int> openingSales(n);
    for(int &num : openingSales) cin >> num;
    SegmentTree open(openingSales);
    
    vector<int> closingSales(n , 0);
    SegmentTree close(closingSales);

    vector<int> areOpen(n , 1);
    SegmentTree status(areOpen);

    for(int i = 1 ; i <= q ; i++){
        int op ; cin >> op;

        if(op == 1){
            int ql , qr , val;
            cin >> ql >> qr >> val;

            ql -= 1;
            qr -= 1;

            open.Add(ql , qr , val);
        }
        else if(op == 2){
            int p ; cin >> p;
            p -= 1;

            ll closingPrice = open.Sum(p , p);
            close.Add(p  , p , closingPrice);
            status.Add(p , p , -1);
        }
        else{
            int k ; cin >> k;

            int j = -1;
            int low = 0 , high = n - 1;

            while(low <= high){
                int mid = (low + high) >> 1;

                if(status.Sum(0 , mid) >= k){
                    j = mid;
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }

            ll sum =  j == -1 ? 0 : close.Sum(0 , j);

            cout << sum << "\n";
        }
    }

    return 0;
}


// 1. add to everyone
// 2. when store closes -> get value -> put it in closed
// 3. sum of closed
