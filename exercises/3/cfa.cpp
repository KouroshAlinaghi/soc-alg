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
int dp[2002][2002];
vector<int> shom[2002];

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sqrt(i); j++) {
            if (i % j == 0) {
                shom[i].pb(j);
                if (j != sqrt(i)) shom[i].pb(i/j);
            }
        }
    }

    for (int i = 1; i < 2002; i++) dp[i][1] = 1;
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (auto c : shom[i]) {
                dp[i][j] += dp[c][j - 1];
                dp[i][j] %= mod;
            }
        }
    }

    ll res = 0;
    for (int i = 1; i <= n; i++) {
        res += dp[i][k];
        res %= mod;
    }

    print(res);

	return(0);
}

