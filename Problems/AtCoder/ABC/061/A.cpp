#include<bits/stdc++.h>
using namespace std;

int main(){
    int A , B , C;
    cin >> A >> B >> C;

    if(A <= C && C <= B) cout << "Yes";
    else cout << "No";

    return 0;
}