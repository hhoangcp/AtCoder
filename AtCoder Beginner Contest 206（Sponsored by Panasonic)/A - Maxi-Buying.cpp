/// hhoangcpascal

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n; cin >> n;

    double ans = 1.08 * n;
    int f = floor(ans);

    if (f < 206) puts("Yay!");
    else if (f > 206) puts(":(");
    else puts("so-so");

    return 0;
}
