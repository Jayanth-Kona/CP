#include<bits/stdc++.h>
using namespace std;

int BFS_01(int N , int S , int T , vector<vector<array<int , 2>>> &Graph){
    using node = array<int , 2>;
    
    vector<int> dist(N + 1 , 1e9);
    deque<node> dq;
    dq.push_front({dist[S] = 0 , S});

    while(dq.empty() == false){
        auto [D , U] = dq.front();
        dq.pop_front();

        if(D > dist[U]) continue;

        for(auto &[V , W] : Graph[U]){
            if(D + W < dist[V]){
                if(W == 0) dq.push_front({dist[V] = D , V});
                else dq.push_back({dist[V] = D + W , V});
            }
        }
    }

    return dist[T] == 1e9 ? -1 : dist[T];
}

int main(){
    int N , M , S , T;
    cin >> N >> M >> S >> T;

    vector<vector<array<int , 2>>> Graph(N + 1);

    for(int i = 1 ; i <= M ; i++){
        int U , V;
        cin >> U >> V;
        Graph[U].push_back({V , 1});
    }

    for(int U = 1 ; U <= N ; U++){
        int minV = 1e9;
        for(auto &[V , W] : Graph[U]) minV = min(minV , V);
        for(auto &[V , W] : Graph[U]) if(V == minV) W = 0;
    }

    cout << BFS_01(N , S , T , Graph);

    return 0;
}