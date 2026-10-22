#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , m ; cin >> n >> m;

    cout << string(m + 2 , '#') << "\n";

    for(int i = 1 ; i <= n ; i++){
        string row ; cin >> row;
        cout << "#" + row + "#\n";
    }

    cout << string(m + 2 , '#') << "\n";

    return 0;
}