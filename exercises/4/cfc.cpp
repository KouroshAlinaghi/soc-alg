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

int n, m, q;
vector<int> adj[102];
bool visited[102];
int edges[102][102][102];

bool can_get(int s, int d, int c) {
    if (s == d) return true;
    visited[s] = true;

    int res = 0;
    for (auto u : adj[s]) {
        if (edges[s][u][c] || edges[u][s][c]) {
            if (!visited[u]) {
                res += can_get(u, d, c);
            }
        }
    }

    return res;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int v, u, c;
        cin >> v >> u >> c;
        edges[v][u][c] = true;
        edges[u][v][c] = true;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        int v, u;
        cin >> v >> u;
        ll res = 0;
        for (int c = 1; c <= m; c++) {
            res += can_get(v, u, c);
            for (int j = 1; j <= n; j++) visited[j] = false;
        }
        print(res);
    }

	return(0);
}

