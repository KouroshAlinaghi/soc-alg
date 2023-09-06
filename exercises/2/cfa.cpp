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
#define dokme(x) cout << x << endl, exit(0)
#define ms(x , y) memset(x , y , sizeof x)
#define print(x) cout << x << endl

ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
int w[maxn];
multiset<int> s;

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> w[i];
        s.insert(w[i]);
    }

    int diff = abs(w[1] - w[0]);
    pii ws = {w[1], w[0]};
    for (int i = 0; i < 2 * n; i++) {
        for (int j = i + 1; j < 2 * n; j++) {
            if (abs(w[i] - w[j]) < diff) {
                diff = abs(w[i] - w[j]);
                ws = {w[i], w[j]};
            }
        }
    }

    s.erase(s.find(ws.first));
    s.erase(s.find(ws.second));

    ll ans = diff;

    while (s.size()) {

    }

	return(0);
}
