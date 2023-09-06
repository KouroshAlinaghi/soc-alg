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
int a[maxn], s[maxn];

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> a[0];
    s[0] = a[0];
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    ll ans = 0, thirds = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] * 3 == 2 * s[n - 1]) ans += thirds;
        if (s[i] * 3 == s[n - 1]) thirds++;
    }

    print(ans);

	return(0);
}

