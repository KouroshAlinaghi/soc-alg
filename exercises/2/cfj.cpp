#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3e6;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x << endl, exit(0)
#define ms(x , y) memset(x , y , sizeof x)
#define print(x) cout << x << endl

ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n, t;
ll a[maxn], s[maxn];

bool can_read(int l, int r) {
    return s[r] - s[l] + a[l] <= t;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> t;

    cin >> a[0];
    s[0] = a[0];
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    int curr_max = 0;
    for (int i = 0; i < n; i++) {
        int l = i, r = n - 1;
        if (a[i] > t) continue;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (!can_read(i, mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        auto m = can_read(i, r) ? r - i + 1 : l - i + 1;
        curr_max = max(m, curr_max);
    }

    print(curr_max);

	return(0);
}
