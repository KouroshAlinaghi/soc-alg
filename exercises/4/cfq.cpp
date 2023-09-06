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
vector<int> adj[2002];
bool visited[2004], leaf[2004], root[2004];

int dfs(int v, int h) {
    visited[v] = true;

    int ans = -maxn;
    for (auto u : adj[v]) {
        if (!visited[u]) {
            leaf[v] = false;
            ans = max(ans, dfs(u, h+1));
        }
    }

    if (leaf[v]) return h;
    return ans;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        leaf[i] = true;
        int v;
        cin >> v;
        if (v != -1) {
            adj[v].pb(i);
            adj[i].pb(v);
        } else {
            root[i] = true;
        }
    }

    int ans = -maxn;
    for (int v = 1; v <= n; v++) {
        if (root[v] && !visited[v]) {
            ans = max(ans, dfs(v, 1));
        }
    }

    print(ans);

	return(0);
}

