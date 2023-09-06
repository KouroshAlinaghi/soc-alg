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
int dp[3][maxn], a[3][maxn];

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[0][i] >> a[1][i] >> a[2][i];

    for (int i = 0; i < 3; i++)
        dp[i][1] = a[i][1];

    for (int i = 2; i <= n; i++) {
        dp[0][i] = max(dp[1][i-1], dp[2][i-1]) + a[0][i];
        dp[1][i] = max(dp[0][i-1], dp[2][i-1]) + a[1][i];
        dp[2][i] = max(dp[0][i-1], dp[1][i-1]) + a[2][i];
    }

    print(max(max(dp[0][n], dp[1][n]), dp[2][n]));

	return(0);
}

