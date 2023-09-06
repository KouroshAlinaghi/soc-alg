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
vector<int> adj[304];
bool visited[304], leaf[304], l[304];

void know_leafs(int v) {
    visited[v] = true;

    for (auto u : adj[v]) {
        if (!visited[u]) {
            know_leafs(u);
            leaf[v] = false;
        }
    }
}

void sort_tree(int v) {
    if (leaf[v]) return;

    for (auto u : adj[v]) {
        if (!visited[u]) {
            sort_tree(u);
        }
    }
}

void dfs(int v) {
    visited[v] = true;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i < n; i++) {
        leaf[i] = true;
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    leaf[n] = true;
    know_leafs(1);

    for (int i = 1, k = 1; i <= n; i++) {
        visited[i] = false;
        if (leaf[i]) {
            cin >> l[k++];
        }
    }

    dfs(1);

	return(0);
}

