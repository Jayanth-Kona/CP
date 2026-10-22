#include<bits/stdc++.h>
using namespace std;

// Space Optimization : 2 x 2D-DP

int main(){
    int N , MA , MB;
    cin >> N >> MA >> MB;

    vector<int> A(N + 1) , B(N + 1) , C(N + 1);
    for(int i = 1 ; i <= N ; i++) cin >> A[i] >> B[i] >> C[i];

    int sumA = accumulate(A.begin() , A.end() , 0);
    int sumB = accumulate(B.begin() , B.end() , 0);

    vector<vector<int>> DP(sumA + 1 , vector<int>(sumB + 1 , 1e9)) , NDP = DP;
    DP[0][0] = 0;

    int ans = 1e9;

    for(int i = 1 , pa = 0 , pb = 0; i <= N ; i++){
        NDP = DP;

        pa += A[i];
        pb += B[i];

        for(int a = 1 ; a <= pa ; a++){
            for(int b = 1 ; b <= pb ; b++){
                if(a >= A[i] && b >= B[i]){
                    NDP[a][b] = min(DP[a][b] , C[i] + DP[a - A[i]][b - B[i]]);
                    if(a * MB == b * MA) ans = min(ans , NDP[a][b]);
                }
            }
        }

        DP = NDP;
    }

    if(ans == 1e9) ans = -1;
    
    cout << ans;

    return 0;
}