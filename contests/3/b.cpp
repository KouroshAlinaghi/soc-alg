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
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
#define print(x) cout << x << endl

ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n, k;

bool check(int v) {
    ll sum = 0;
    while (v) {
        sum += v;
        v /= k;
    }
    return sum >= n;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;

    ll l = 0, r = 1e9;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    print(r);

	return(0);
}
