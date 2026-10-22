#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*

Intuition:

    Binary search on number of attacks

    If do 'X' attacks,
    Health of each monster is reduced by 'X * B'
    and health of centered monsters is reduced by mutiples of '(A - B)'

    If monster's is not killed even after 'X' attacks of 'B' damage,
    that means this monstered must have been centered some 'Y' number of times such that:
    H - (X * B) - Y * (A - B) <= 0
    Y >= (H - (X * B)) / (A - B)
    Y = ceil((H - XB) / (A - B))

    summation of all such Y for every monster should be <= X
    Because, we have done only 'X' attacks,
    and sum(Y) --> is number of times monsters needed to centered

    So, I can only center monsters altogether 'X' times (atmax)
    
    Hence required Condition is:
      sum(Y) <= X
    
    
    low = ceil(maxH / A)
    Best case: kill the maxH monster using 'A' and everyone other monster was also killed via 'B' affect
    This can happen when,
         1. Hi < maxH
         2. B ~ A (likely, B = A - 1)
    
    
    
    high = ceil(maxH / A) * N
    Worst Case: Kill all monsters using 'A' damage only, if damage 'B' is almost negligable
    This can happen when,
          1. Hi ~ maxH (likely, H = maxH or H = maxH - 1)
          2. B <<< A 

*/

int main(){
    ll N , A , B;
    cin >> N >> A >> B;

    vector<ll> H(N);
    for(ll &Hi : H) cin >> Hi;

    ll maxH = *max_element(H.begin() , H.end());

    ll low = ((maxH + A - 1) / A);
    ll high = ((maxH + A - 1) / A) * N;

    ll ans = high;

    while(low <= high){
        ll mid = (low + high) >> 1; // X

        ll explosionsReqd = 0; // Y
        for(ll Hi : H) explosionsReqd += max(0LL , (Hi - mid * B + A - B - 1) / (A - B));

        if(explosionsReqd <= mid) high = (ans = mid) - 1;
        else low = mid + 1;
    }

    cout << ans;

    return 0;
}