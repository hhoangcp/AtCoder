/// hhoangcpascal

#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    llong N; cin >> N;

    llong l = 0, r = 2e9, ans = 2e9+1;
    while (l <= r) {
        llong mid = (l + r) >> 1;

        if (mid * (mid + 1) / 2 >= N) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    cout << ans;

    return 0;
}
