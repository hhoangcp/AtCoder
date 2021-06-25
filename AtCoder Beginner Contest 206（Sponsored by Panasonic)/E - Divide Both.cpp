/// hhoangcpascal

#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong dp[1000006], ans = 0;
int l, r, cnt[1000006];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> l >> r;
    for(int i = l; i <= r; ++i) ++cnt[i];

    for(int i = r; i >= 2; --i) {
        llong num = 0;
        for(int j = i; j <= r; j += i) num += cnt[j];

        dp[i] = num * (num - 1) / 2;
        for(int j = 2 * i; j <= r; j += i) dp[i] -= dp[j];

        ans += dp[i];
        if (l <= i) ans -= r / i - 1;
    }

    cout << ans * 2;

    return 0;
}
