#include<bits/stdc++.h>
using namespace std;

int main(){
    int N ; cin >> N;
    string S ; cin >> S;

    for(string fix : {"SS" , "SW" , "WS" , "WW"}){
        string specie(N , '_');

        specie[0] = fix[0];
        specie[1] = fix[1];

        for(int i = 1 ; i <= N - 2 ; i++){
            int L = (i - 1);
            int R = (i + 1) % N;

            if(specie[i] == 'S'){
                if(S[i] == 'o') specie[R] = specie[L];
                else specie[R] = 'S' ^ 'W' ^ specie[L];
            }
            else{
                if(S[i] == 'x') specie[R] = specie[L];
                else specie[R] = 'S' ^ 'W' ^ specie[L];
            }
        }

        int good = 1;

        for(int i = 0 ; i < N && good; i++){
            int L = (i - 1 + N) % N;
            int R = (i + 1) % N;

            if(specie[i] == 'S'){
                if(S[i] == 'o' && specie[L] != specie[R]) good = 0;
                if(S[i] == 'x' && specie[L] == specie[R]) good = 0;
            }
            else{
                if(S[i] == 'o' && specie[L] == specie[R]) good = 0;
                if(S[i] == 'x' && specie[L] != specie[R]) good = 0;
            }
        }

        if(good){
            cout << specie;
            return 0;
        }
    }

    cout << "-1";

    return 0;
}