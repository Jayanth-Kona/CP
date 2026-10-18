#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , m ; cin >> n >> m;

    map<string , int> indexOf;

    for(int i = 0 ; i < n ; i++){
        string candidate ; cin >> candidate;
        indexOf[candidate] = i;
    }

    vector<int> votes(n , 0);
    for(int i = 0 ; i < m ; i++){
        string ballot ; cin >> ballot;
        
        if(indexOf.count(ballot)){
            votes[indexOf[ballot]]++;
        }
        else{
            vector<int> match;
            for(char &ch : ballot){
                char original = ch;
                for(char to = 'a' ; to <= 'z' ; to++){
                    ch = to;
                    if(indexOf.count(ballot)){
                        match.push_back(indexOf[ballot]);
                    }
                    if(match.size() > 1) break;
                }
                ch = original;
                if(match.size() > 1) break;
            }
            if(match.size() == 1) votes[match[0]] += 1;
        }
    }

    for(int i = 0 ; i < n ; i++){
        cout << votes[i] << '\n';
    }

    return 0;
}