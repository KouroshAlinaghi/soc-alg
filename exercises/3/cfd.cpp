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

int t, n;
int a[maxn];
int dp[maxn][2]; // 1 => doost, 0 => man

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> t;
    dp[0][1] = maxn;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            dp[i][0] = dp[i][1] = maxn;
        }

        dp[1][1] = a[1];

        for (int i = 2; i <= n; i++) {
            dp[i][0] = min(dp[i-1][1], dp[i-2][1]);
            dp[i][1] = min(dp[i-1][0] + a[i], dp[i-2][0] + a[i] + a[i-1]);
        }

        print(min(dp[n][0], dp[n][1]));
    }

	return(0);
}

