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
ll a, freq[maxn], dp[maxn];

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        freq[a]++;
    }

    dp[0] = 0;
    dp[1] = freq[1];

    for (int i = 2; i < maxn; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + freq[i] * i);
    }

    print(dp[maxn - 1]);

	return(0);
}

