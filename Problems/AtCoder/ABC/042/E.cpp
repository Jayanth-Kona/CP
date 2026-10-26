#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

int n;
int target , limit;

int DP[42][1 << 18] , power10[42];

ll DFS(int pos , int mask){
    if((mask & target) == target) return power10[n - pos];

    if(pos == n) return 0;

    if(DP[pos][mask] != -1) return DP[pos][mask];

    ll ways = 0;

    for(int d = 1 ; d <= 10 ; d++){
        int new_mask = mask << d;
        new_mask |= 1 << (d - 1);
        new_mask &= limit;
        ways = (ways + DFS(pos + 1 , new_mask)) % mod;
    }

    return DP[pos][mask] = ways;
}

int main(){
    memset(DP , -1 , sizeof DP);

    cin >> n;

    power10[0] = 1;
    for(int i = 1 ; i <= n ; i++) power10[i] = (power10[i - 1] * 10LL) % mod;

    int x , y , z;
    cin >> x >> y >> z;

    limit = (1 << (x + y + z)) - 1;

    target = 0;
    for(int sum : {x + y + z , y + z , z}){
        target |= 1 << (sum - 1);
    }

    cout << DFS(0 , 0);

    return 0;
}

/*

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

# First Insight & State Formulation

DFS(pos, status, sum)
status = 0, 1, 2, 3, 4 (not started, X, Y, Z, done)
sum = current accumulated sum for the active segment


# Why It Fails? The Overcounting Problem 

Your model assumes the structure: (anything) -> (X) -> (Y) -> (Z) -> (anything)

Because you manually choose when to transition between states, two duplicate paths emerge:
1. If the first "anything" accidentally forms an (X -> Y -> Z), your DP might skip it, keep waiting, and then manually form a second (X -> Y -> Z) later.
2. In another branch, your DP could have matched that first occurrence and filled the rest with "anything".

Both branches generate the exact same final array, counting it multiple times.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

# The Fix: DFS with Bitmask Automaton
DFS(pos, mask)

mask = bitset tracking all active suffix sums ending at the current position.
Target suffix sums required simultaneously: Z , Y + Z , X + Y + Z

Target bitmask:
target = (1 << (Z - 1)) | (1 << (Y + Z - 1)) | (1 << (X + Y + Z - 1))

# What Makes the Bitmask Different?

Instead of guessing when to start or advance phases, the bitmask deterministically evaluates every incoming digit:
new_mask = ((mask << d) | (1 << (d - 1))) & limit

There are zero branching choices on where segments begin or end. The sequence of states is 100% deterministic for any given array.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

# Why This Completely Eliminates Overcounting

The search terminates and returns 10^(N - pos) the very first time (mask & target) == target.
This changes the counted pattern strictly to:
(prefix containing NO valid XYZ) -> (FIRST occurrence of XYZ) -> (anything)

Because every valid array has a unique, well-defined first index where XYZ completes, every valid sequence is counted at that exact first hit, and never again.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

*/