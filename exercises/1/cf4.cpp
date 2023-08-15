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

int t, n, k;
int a[101];
int l[101];

int calc_power(int l, int r) {
    int res = 0;
    while (l++ < r - 1) {
        res += abs(a[l] - a[l+1]);
    }
    return res;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> t;

    for (int test = 0; test < t; test++) {
        cin >> n >> k;
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        int cur_min = maxn;
        for (;;/*each efraz*/) {
            int sum = 0;
            for (int i = 0; i < k; i++)
                sum += calc_power(l[i], (i ? l[i-1] : 0));
            cur_min = min(cur_min, sum);
        }
        print(cur_min);
    }

	return(0);
}
