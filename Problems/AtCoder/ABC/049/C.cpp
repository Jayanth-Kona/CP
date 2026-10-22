#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<string> words = {"dream" , "dreamer" , "erase" , "eraser"};

    string s ; cin >> s;
    int n = s.size();
    
    vector<bool> canForm(n + 1 , false);
    canForm[0] = true;

    for(int i = 1 ; i <= n ; i++){
        if(canForm[i - 1] == true){
            for(string &w : words){
                if(s.substr(i - 1 , w.size()) == w){
                    canForm[i + w.size() - 1] = true;
                }
            }
        }
    }

    cout << (canForm[n] ? "YES" : "NO");

    return 0;
}