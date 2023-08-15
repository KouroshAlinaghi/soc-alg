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
int a[maxn];
stack<pii> s;
set<pii> se;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int last_less_index = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        se.insert({i, a[i]});
    }

    for (int i = 0; i < n; i++) {
        auto sexe_khales = se.lower_bound({i, a[i]});
        cout << "---------------" << endl;
        s.push({a[i], (sexe_khales == se.begin() ? -1 : sexe_khales->first)});
        cout << a[i] << " " << i << " " << s.top().first << endl;
    }

    int max_area = 0;
    for (int i = n - 1; i; i--) {
        auto casemiro = s.top();
        s.pop();
        max_area = max(max_area, casemiro.first * (i - casemiro.first));
    }
    
    cout << max_area << endl;

    return(0);
}

