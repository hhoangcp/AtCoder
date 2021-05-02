/// hhoangcpascal

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define llong long long

using namespace std;

vector<int> Add[200006];
vector<pair<int, int> > Delete[200006];
llong Lazy[800006], Max[800006];
int n, m;

void Down(int id) {
    Lazy[id*2+1] += Lazy[id];
    Max[id*2+1] += Lazy[id];

    Lazy[id*2+2] += Lazy[id];
    Max[id*2+2] += Lazy[id];

    Lazy[id] = 0;
}

void Update(int id, int l, int r, int u, int v, llong val) {
    if (l > v || u > r) return;
    if (u <= l && r <= v) {
        Max[id] += val;
        Lazy[id] += val;
        return;
    }

    int mid = (l + r) >> 1;
    Down(id);

    Update(id*2+1, l, mid, u, v, val);
    Update(id*2+2, mid+1, r, u, v, val);

    Max[id] = max(Max[id*2+1], Max[id*2+2]);
}

llong Query(int id, int l, int r, int u, int v) {
    if (u > r || l > v) return -1e18;
    if (u <= l && r <= v) return Max[id];

    int mid = (l + r) >> 1;
    Down(id);

    return max(Query(id*2+1, l, mid, u, v), Query(id*2+2, mid+1, r, u, v));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m;
    while (m--) {
        int l, r, a; cin >> l >> r >> a;
        Add[l].push_back(a);
        Delete[r].push_back({l, a});
    }

    llong res = 0;
    for(int i=1; i<=n; ++i) {
        for(int a: Add[i]) Update(0, 0, n, 0, i-1, 1LL * a);
        llong dp = Query(0, 0, n, 0, i-1);
        res = max(res, dp);

        Update(0, 0, n, i, i, dp);
        for(pair<int, int> tmp: Delete[i]) Update(0, 0, n, 0, tmp.first-1, -1LL * tmp.second);
    }

    cout << res;

    return 0;
}
