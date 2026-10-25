#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*

Solved via DeepSeek: Problem is easy, its that I'm not familiar with geometry !!

*/

struct Point {
    ll x, y;
};

ll cross(const Point& p, const Point& q) {
    return p.x * q.y - p.y * q.x;
}

// Upper half-plane: y > 0, or y == 0 and x > 0
bool upper(const Point& p) {
    return (p.y > 0) || (p.y == 0 && p.x > 0);
}

// Exact CCW angular order starting from positive x-axis, range [0, 2π)
bool angleLess(const Point& a, const Point& b) {
    bool ua = upper(a), ub = upper(b);
    if (ua != ub) return ua;
    ll c = cross(a, b);
    if (c != 0) return c > 0;
    // Collinear with origin: tie-break by distance (strict ordering)
    return (a.x*a.x + a.y*a.y) < (b.x*b.x + b.y*b.y);
}

// Max points in any open semicircle (i.e., one side of some line through origin)
int maxInHalfPlane(vector<Point> pts) {
    int n = pts.size();
    if (n == 0) return 0;

    sort(pts.begin(), pts.end(), angleLess);

    vector<Point> a(2 * n);
    for (int i = 0; i < n; i++) a[i] = a[i + n] = pts[i];

    int best = 0, j = 0;
    for (int i = 0; i < n; i++) {
        if (j < i) j = i;
        while (j < i + n && (j == i || cross(a[i], a[j]) > 0)) j++;
        best = max(best, j - i);
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<Point> pts(n);
        for (int i = 0; i < n; i++) cin >> pts[i].x >> pts[i].y;
        cout << maxInHalfPlane(pts) << "\n";
    }
    return 0;
}