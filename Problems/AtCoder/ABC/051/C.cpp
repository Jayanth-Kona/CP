#include <bits/stdc++.h>
using namespace std;

int main(){
    int sx , sy , tx , ty;
    cin >> sx >> sy >> tx >> ty;

    int a = tx - sx;
    int b = ty - sy;

    string ans;

    // First trip: S -> T
    ans += string(b , 'U');
    ans += string(a , 'R');

    // Second trip: T -> S
    ans += string(b , 'D');
    ans += string(a , 'L');

    // Third trip: S -> T
    ans += 'L';
    ans += string(b + 1 , 'U');
    ans += string(a + 1 , 'R');
    ans += 'D';

    // Fourth trip: T -> S
    ans += 'R';
    ans += string(b + 1 , 'D');
    ans += string(a + 1 , 'L');
    ans += 'U';

    cout << ans;

    return 0;
}