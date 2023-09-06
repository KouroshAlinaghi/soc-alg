#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll , ll> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn = 3e6;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
#define prll(x) cout << x << endl

ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll n;
vector<ll> adj[maxn], ans;
ll visited[maxn], goal[maxn], init[maxn];

void dfs(ll v, int odds, int evens, int height) {
    visited[v] = true;

    bool curr = ((height % 2 ? odds : evens) % 2 ? !init[v] : init[v]);
    if (goal[v] != curr) {
        if (height % 2) 
            odds++;
        else 
            evens++;
        ans.pb(v);
    }

    for (auto u : adj[v]) {
        if (!visited[u]) {
            dfs(u, odds, evens, height + 1);
        }
    }
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (ll i = 1; i < n; i++) {
        ll v, u;
        cin >> v >> u;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (ll i = 1; i <= n; i++)
        cin >> init[i];
    for (ll i = 1; i <= n; i++)
        cin >> goal[i];

    dfs(1, 0, 0, 1);

    prll(ans.size());
    for (auto v : ans)
        prll(v);

	return(0);
}

