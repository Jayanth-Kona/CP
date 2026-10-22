#include<bits/stdc++.h>
using namespace std;

int main(){
    string O , E ; cin >> O >> E;

    for(int i = 0 ; i < (int)E.size() ; i++){
        cout << O[i] << E[i];
    }

    if(O.size() > E.size()) cout << O.back();

    return 0;
}