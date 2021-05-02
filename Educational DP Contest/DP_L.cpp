/// hhoangcpascal
/// Deque

#include <cstdio>
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong a[1000006];
int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; ++i) {
        cin >> a[i];
        for(; i > 2 && a[i-2] <= a[i-1] && a[i-1] >= a[i]; i -= 2, n -= 2) a[i-2] += a[i] - a[i-1];
    }

    llong mmax = 0;
    for(int l = 1, r = n, del = 1; l <= r; del = -del)
        mmax += 1LL * del * ((a[l] > a[r]) ? a[l++] : a[r--]);

    cout << mmax;

    return 0;
}
