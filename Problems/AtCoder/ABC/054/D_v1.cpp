#include<bits/stdc++.h>
using namespace std;

// No Space Optimization : 1 x 3D-DP

int main(){
    int N , MA , MB;
    cin >> N >> MA >> MB;

    vector<int> A(N + 1) , B(N + 1) , C(N + 1);
    for(int i = 1 ; i <= N ; i++) cin >> A[i] >> B[i] >> C[i];

    int sumA = accumulate(A.begin() , A.end() , 0);
    int sumB = accumulate(B.begin() , B.end() , 0);

    vector<vector<vector<int>>> DP(N + 1 , vector<vector<int>>(sumA + 1 , vector<int>(sumB + 1 , 1e9)));
    DP[0][0][0] = 0;

    int ans = 1e9;

    for(int i = 1 , pa = 0 , pb = 0; i <= N ; i++){
        pa += A[i];
        pb += B[i];

        DP[i][0][0] = 0;

        for(int a = 1 ; a <= pa ; a++){
            for(int b = 1 ; b <= pb ; b++){

                DP[i][a][b] = DP[i - 1][a][b];
                if(a >= A[i] && b >= B[i]) DP[i][a][b] = min(DP[i][a][b] , C[i] + DP[i - 1][a - A[i]][b - B[i]]);

                if(a * MB == b * MA){
                    ans = min(ans , DP[i][a][b]);
                }
            }
        }
    }

    if(ans == 1e9) ans = -1;
    
    cout << ans;

    return 0;
}