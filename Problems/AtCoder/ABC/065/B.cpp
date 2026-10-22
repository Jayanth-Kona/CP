#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin >> n;

    vector<int> a(n + 1);
    for(int i = 1 ; i <= n ; i++) cin >> a[i];

    vector<int> status(n + 1 , 0); // 0:off , 1:on , 2:visited
    status[1] = 1;
    
    int curr = 1 , steps = 0;
    while(curr != 2){
        status[curr] = 2;

        steps += 1;
        int next = a[curr];

        if(status[next] == 1 || status[next] == 2) break;

        status[next] = 1;
        curr = next;
    }

    cout << (curr == 2 ? steps : -1);

    return 0;
}