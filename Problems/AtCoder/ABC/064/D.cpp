#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin >> n;
    string s ; cin >> s;

    int open = 0 , openReqd = 0;

    for(char ch : s){
        if(ch == '('){
            open += 1;
        }
        else{
            if(open > 0){
                open -= 1;
            }
            else{
                openReqd += 1;
            }
        }
    }

    cout << string(openReqd , '(') + s + string(open , ')');

    return 0;
}