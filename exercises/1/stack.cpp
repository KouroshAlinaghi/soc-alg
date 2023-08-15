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
pair<ll, pii> a[maxn];
stack<pair<ll, int>> s;

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = {x, {-1, n}};
    }

    for (int i = 0; i < n; i++) {
        if (s.empty()) {
            s.push({a[i].first, i});
        } else {
            while (s.size() && s.top().first >= a[i].first) {
                s.pop();
            }
            if (s.size()) a[i].second.first = s.top().second;
            s.push({a[i].first, i});
        }
    }

    for (; s.size(); s.pop());

    for (int i = n - 1; i >= 0; i--) {
        if (s.empty()) {
            s.push({a[i].first, i});
        } else {
            while (s.size() && s.top().first >= a[i].first) {
                s.pop();
            }
            if (s.size()) a[i].second.second = s.top().second;
            s.push({a[i].first, i});
        }
    }

    ll m = 0;
    for (int i = 0; i < n; i++) {
        m = max(m, a[i].first * (a[i].second.second - a[i].second.first - 1));
    }
    print(m);

	return(0);
}
