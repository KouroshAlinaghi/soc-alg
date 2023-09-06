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

ll pw(ll a, ll b){ll res = 1;while(b){if(b&1){res=(a*res);}a=(a*a);b>>=1;}return(res);}

int n, m, ans;
vector<int> adj[100];
bool visited[100];

void dfs(int v) {
    visited[v] = true;

    for (auto u : adj[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int v, u;
        cin >> v >> u;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int v = 1; v <= n; v++) {
        if (!visited[v]) {
            ans++;
            dfs(v);
        }
    }

    print(pw(2, n - ans));

	return(0);
}

