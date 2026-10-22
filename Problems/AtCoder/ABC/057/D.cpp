#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll NCR(ll N , ll R){
    if(N < R) return 0;

    ll res = 1;

    for(ll i = 1 ; i <= R ; i++){
        res *= (N - i + 1);
        res /= i;
    }

    return res;
}

int main(){
    ll N , A , B;
    cin >> N >> A >> B;

    vector<ll> V(N);
    for(ll &num : V) cin >> num;

    sort(V.rbegin() , V.rend());

    ll nume = accumulate(V.begin() , V.begin() + A , 0LL);
    ll deno = A;

    cout << fixed << setprecision(6) << ((long double)nume / deno) << "\n";

    if(V[0] == V[A - 1]){
        ll total = count(V.begin() , V.end() , V[A - 1]);
        ll ways = 0;

        for(int choose = A ; choose <= min(B , total) ; choose++){
            ways += NCR(total , choose);
        }

        cout << ways;
    }
    else{
        ll total = count(V.begin() , V.end() , V[A - 1]);
        ll choose = count(V.begin() , V.begin() + A , V[A - 1]);

        ll ways = NCR(total , choose);

        cout << ways;
    }

    return 0;
}