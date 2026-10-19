#include <bits/stdc++.h>
using namespace std;

int main(){
    int W , H , N;
    cin >> W >> H >> N;

    int L = 0 , R = W , B = 0 , T = H;

    for(int i = 1 ; i <= N ; i++){
        int X , Y , A;
        cin >> X >> Y >> A;

        if(A == 1) L = max(L , X);
        if(A == 2) R = min(R , X);
        if(A == 3) B = max(B , Y);
        if(A == 4) T = min(T , Y);
    }

    int remW = max(0 , R - L);
    int remH = max(0 , T - B);

    cout << remW * remH;

    return 0;
}