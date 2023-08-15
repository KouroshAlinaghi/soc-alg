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

int n, m, k;
bool a[2000][2000];
ll x, y;

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> k;

    int iar = 0;
    for (int i = 0; i < n; i++) {
        iar = 0;
        char c;
        for (int j = 0; j < m; j++) {
            cin >> c;
            a[i][j] = c == '.';
            if (a[i][j]) {
                iar++;
            } else {
                x += max(0, iar - k + 1);
                iar = 0;
            }
        }
        x += max(0, iar - k + 1);
    }

    if (k == 1) {
        ll res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res += (a[i][j]);
            }
        }
        cout << res << endl;
        return 0;
    }

    iar = 0;
    for (int j = 0; j < m; j++) {
        iar = 0;
        for (int i = 0; i < n; i++) {
            if (a[i][j]) {
                iar++;
            } else {
                y += max(0, iar - k + 1);
                iar = 0;
            }
        }
        y += max(0, iar - k + 1);
    }

    print(x+y);

	return(0);
}
