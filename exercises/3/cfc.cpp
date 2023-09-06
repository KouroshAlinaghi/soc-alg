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

int n;
int a[3001], b[3001], c[3001];
int dp[4][maxn];

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];

    dp[0][1] = a[1];
    dp[1][1] = -1 * maxn;
    dp[2][1] = b[1];
    dp[3][1] = -1 * maxn;

    for (int i = 2; i <= n; i++) {
        dp[0][i] = max(dp[2][i-1], dp[3][i-1]) + a[i];
        dp[1][i] = max(dp[0][i-1], dp[1][i-1]) + b[i];
        dp[2][i] = max(dp[2][i-1], dp[3][i-1]) + b[i];
        dp[3][i] = max(dp[0][i-1], dp[1][i-1]) + c[i];
    }

    print(max(dp[1][n], dp[0][n]));

	return(0);
}

