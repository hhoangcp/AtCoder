/// hhoangcpascal

#include <cstdio>
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

struct Point {
    int x, y;
    llong val;

    bool operator < (const Point &other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
} P[3006];

const llong mod = 1e9+7;
int n, m, p;

llong power(llong a, llong b) {
    if (b == 0) return 1LL;
    llong z = power(a, b>>1);
    z = (z*z) % mod;
    if (b & 1) z = (z*a) % mod;
    return z;
}

llong f[200006], g[200006];

void init() {
    int tmp = m+n;
    f[0] = g[0] = 1;
    for(int i=1; i<=tmp; ++i) {
        f[i] = (f[i-1]*i) % mod;
        g[i] = power(f[i], mod-2);
    }
}

template<typename T>
bool fast_scan(T &num) {
    num = 0;
    register char c = getchar();
    while (c != '-' && (c < '0' || '9' < c)) {
        if (feof(stdin)) return false;
        c = getchar();
    }
    bool neg = false;
    if (c == '-') {
        neg = true;
        c = getchar();
    }
    for(; '0' <= c && c <= '9'; c = getchar()) num = (num << 1) + (num << 3) + (c - '0');
    if (neg) num = -num;
    return true;
}

llong get_C(int X, int p) {
    return ((f[X] * g[p]) % mod * g[X-p]) % mod;
}

void process(int pos, int x, int y, llong &res) {
    int m1 = m-x+1, n1 = n-y+1;
    llong tmp = get_C(x+y-2, x-1);

    for(int i=1; i<pos; ++i)
    if (P[i].y <= y) {
        int u = x - P[i].x + 1, v = y - P[i].y + 1;
        llong tmp1 = get_C(u+v-2, u-1);

        tmp1 *= P[i].val; tmp1 %= mod;
        tmp = (tmp - tmp1 + mod) % mod;
    }

    P[pos].val = tmp;

    if (m1 == 1 && n1 == 1) res = (res - tmp + mod) % mod;
    else {
        llong tmp1 = get_C(m1+n1-2, m1-1);
        tmp *= tmp1; tmp %= mod;
        res = (res - tmp + mod) % mod;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> m >> n >> p;

    if (m == 1 && n == 1) {
        if (p == 0) cout << 1;
        else cout << 0;
        return 0;
    }

    init();

    llong res = get_C(m+n-2, m-1);
    for(int i=1; i<=p; ++i) {
        cin >> P[i].x >> P[i].y;
        if (P[i].x == 1 && P[i].y == 1) {
            cout << 0;
            return 0;
        }
        else P[i].val = get_C(P[i].x+P[i].y - 2, P[i].x - 1);
    }

    sort(P+1, P+p+1);
    for(int i=1; i<=p; ++i) process(i, P[i].x, P[i].y, res);

    cout << res;

    return 0;
}
