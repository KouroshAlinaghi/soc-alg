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
#define print(x) cout << x << endl

ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n, m;
vector<int> adj[maxn];
vector<int> teams[50], comp[50];
vector<int> ones, twos;
bool visited[50];

void dfs(int v, int t) {
    visited[v] = true;
    comp[t].pb(v);

    for (auto u : adj[v]) {
        if (!visited[u]) {
            dfs(u, t);
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

    int cnt = 0;
    for (int v = 1; v <= n; v++) {
        if (!visited[v]) {
            dfs(v, cnt);
            cnt++;
        }
    }

    auto c = cnt;
    cnt = 0;
    for (int i = 0; i < c; i++) {
        auto c = comp[i];
        if (c.empty()) continue;
        if (c.size() > 3) dokme(-1);
        if (c.size() == 3) {
            for (auto v : c) {
                teams[cnt].pb(v);
            }
            cnt++;
        }
        if (c.size() == 2) twos.pb(i);
        if (c.size() == 1) ones.pb(i);
    }

    if (twos.size() > ones.size()) dokme(-1);

    for (int i = 0; i < twos.size(); i++) {
        teams[cnt].pb(comp[ones[i]][0]);
        teams[cnt].pb(comp[twos[i]][0]);
        teams[cnt].pb(comp[twos[i]][1]);
        cnt++;
    }

    if ((ones.size() - twos.size()) % 3) dokme(-1);

    for (int i = twos.size(); i < ones.size(); i += 3) {
        teams[cnt].pb(comp[ones[i]][0]);
        teams[cnt].pb(comp[ones[i+1]][0]);
        teams[cnt].pb(comp[ones[i+2]][0]);
        cnt++;
    }

    for (auto team : teams) {
        if (team.empty()) continue;
        for (auto v : team) {
            cout << v << " ";
        }
        cout << endl;
    }

	return(0);
}

