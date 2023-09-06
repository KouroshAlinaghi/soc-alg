#include <iostream>

using namespace std;

const int maxn = 1e9 + 7;

int n, q;
int a[maxn], p[maxn];

int main() {
    cin >> n;
    cin >> a[0];
    p[0] = a[0];
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }

    int l, r, x;
    cin >> q;
    while (q--) {
        cin >> l >> r >> x;
        p[]
    }

    return 0;
}
