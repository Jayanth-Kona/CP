#include<bits/stdc++.h>
using namespace std;

int main(){
    int D , N ; cin >> D >> N;

    cout << (int)pow(10 , 2 * D) * (N == 100 ? N + 1 : N);

    return 0;
}