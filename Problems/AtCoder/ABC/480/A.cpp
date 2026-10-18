#include<bits/stdc++.h>
using namespace std;

int main(){
    int ax , ay;
    int dx , dy;

    for(int x = 0 ; x < 2 ; x++){
        for(int y = 0 ; y < 2 ; y++){
            char ch ; cin >> ch;
            if(ch == 'A'){
                ax = x;
                ay = y;
            }
            else if(ch == 'D'){
                dx = x;
                dy = y;
            }
        }
    }

    if(abs(ax - dx) + abs(ay - dy) == 1) cout << "Yes";
    else cout << "No";

    return 0;
}