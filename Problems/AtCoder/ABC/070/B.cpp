#include<bits/stdc++.h>
using namespace std;

int main(){
    int A , B , C , D;
    cin >> A >> B >> C >> D;

    if(A <= C){
        cout << max(0 , B - C) - max(0 , B - D);
    }
    else{
        cout << max(0 , D - A) - max(0 , D - B);
    }

    return 0;
}