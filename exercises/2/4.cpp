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

ll f(int);

ll g(int n) {
    if (n == 2) return 0;
    if (n == 1) return 1;
    return f(n - 1) + g(n - 2);
}

ll f(int n) {
    if (n < 2) return 0;
    if (n == 3) return 0;
    if (n == 2) return 3;
    return g(n - 1) + 2 * f (n - 2) + g(n - 3);
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    print(2 * f(n));

	return(0);
}

