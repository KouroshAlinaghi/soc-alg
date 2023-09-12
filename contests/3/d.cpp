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
int mor, les, equ;
int a[maxn];

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mor += a[i] > m;
        les += a[i] < m;
        equ += a[i] == m;
    }

    auto m = abs(mor-les);

    if (les > mor) {
        dokme(max(0, les + 1 - mor - equ));
    } else if (mor > les) {
        dokme(max(0, mor - les - equ));
    } else {
        if (equ) {
            dokme(0);
        } else {
            dokme(1);
        }
    }

	return(0);
}
