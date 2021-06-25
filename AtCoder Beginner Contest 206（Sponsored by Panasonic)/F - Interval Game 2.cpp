/// hhoangcpascal

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Data {
    int l, r;
} D[106];

int G[106][106], n;

int Grundy(int l, int r) {
    if (l >= r) return 0;
    if (G[l][r] != -1) return G[l][r];

    vector<bool> mask(129, false);

    for(int i = 1; i <= n; ++i)
    if (l <= D[i].l && r >= D[i].r)
        mask[Grundy(l, D[i].l) ^ Grundy(D[i].r, r)] = true;

    for(int cur = 0; G[l][r] == -1; ++cur)
    if (!mask[cur]) G[l][r] = cur;

    return G[l][r];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> D[i].l >> D[i].r;

        for(int i = 1; i <= 100; ++i)
        for(int j = 1; j <= 100; ++j) G[i][j] = -1;

        if (Grundy(1, 100)) cout << "Alice\n"; else cout << "Bob\n";
    }

    return 0;
}
