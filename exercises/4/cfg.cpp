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
int p[304], ans[304];
vector<int> adj[304];
bool visited[305];
pair<vector<int>, vector<int>> s[304];

void dfs(int v, int mol) {
    visited[v] = true;
    s[mol].first.pb(p[v]);
    s[mol].second.pb(v);

    for (auto u : adj[v])
        if (!visited[u])
            dfs(u, mol);
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i];

    char c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c;
            if (c == '1') {
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }

    int mol = 0;
    for (int v = 0; v <= n; v++) {
        if (!visited[v]) {
            dfs(v, mol);
        }
        sort(s[mol].first.begin(), s[mol].first.end());
        sort(s[mol].second.begin(), s[mol].second.end());
        mol++;
    }

    for (auto m : s) {
        for (int i = 0; i < m.first.size(); i++) {
            ans[m.second[i]] = m.first[i];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;

	return(0);
}

