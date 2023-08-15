#include <bits/stdc++.h>
#include <deque>

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
pair<ll, pii> a[maxn];
set<pair<ll, int>> s1, se1;
set<int> s2, se2;

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (n == 1) {
            print(x);
            return 0;
        }
        a[i] = {x, {-1, n}};
        s1.insert({x, i});
        s2.insert(i);
    }

    se1 = s1;
    se2 = s2;

    for (int i = 0; i < n; i++) {
        auto big = --(s1.end());
        auto up = s2.upper_bound(big->second);
        if (up != s2.end())
            a[big->second].second.second = *up;
        s1.erase(big);
        s2.erase(big->second);

        big = se1.lower_bound({(--(se1.end()))->first, -1});
        auto low = prev(se2.lower_bound(big->second));
        if (low != se2.end())
            a[big->second].second.first = *low;
        se1.erase(big);
        se2.erase(big->second);
    }

    ll res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, (a[i].second.second - a[i].second.first - 1) * a[i].first);
    }

    print(res);

	return(0);
}
