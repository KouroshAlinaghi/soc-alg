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

int n, m;
vector<int> adj[maxn];
int visited[maxn], cats[maxn], leaf[maxn];

int dfs(int v, int cnt) {
    visited[v] = true;
    if (cnt > m) return 0;

    int res = 0;
    for (auto u : adj[v]) {
        if (!visited[u]) {
            leaf[v] = 0;
            res += dfs(u, cats[u] ? cnt + cats[u] : 0);
        }
    }

    return leaf[v] ? 1 : res;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        leaf[i] = 1;
        cin >> cats[i];
    }
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    print(dfs(1, cats[1]));

    // for (int i = 1; i <= n; i++) {
    //     cout << i << ": " << leaf[i] << endl;
    // }

	return(0);
}

