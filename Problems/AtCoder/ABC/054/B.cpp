#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , m ; cin >> n >> m;

    vector<string> A(n);
    for(string &s : A) cin >> s;

    vector<string> B(m);
    for(string &s : B) cin >> s;

    for(int dx = 0 ; dx + m - 1 < n ; dx++){
        for(int dy = 0 ; dy + m - 1 < n ; dy++){
            int good = 1;
            for(int i = 0 ; i < m && good ; i++){
                for(int j = 0 ; j < m && good ; j++){
                    good &= A[i + dx][j + dy] == B[i][j];
                }
            }
            if(good){
                cout << "Yes";
                return 0;
            }
        }
    }

    cout << "No";

    return 0;
}