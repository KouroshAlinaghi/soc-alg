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
vector<int> adj[maxn];
pii ver[maxn];
bool visited[maxn];

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

    cin >> n;
    int v = 1;
    for (int useless = 0; useless < n; useless++) {
        int q, a, b;
        cin >> q >> a >> b;
        if (q == 1) {
            ver[v] = {a, b};
            for (int u = 1; u < v; u++) {
                int c = ver[u].first, d = ver[u].second;
                if ((c < a and a < d) or (c < b and b < d)) {
                    adj[v].pb(u);
                }
                if ((a < c and c < b) or (a < d and d < b)) {
                    adj[u].pb(v);
                }
            }
            v++;
        } else if (q == 2) {
            for (int i = 1; i <= n; i++) visited[i] = false;
            dfs(a);
            print((visited[b] ? "YES" : "NO"));
        }
    }

	return(0);
}

