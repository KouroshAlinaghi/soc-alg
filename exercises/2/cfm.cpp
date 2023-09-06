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

ll init_x, init_y, dest_x, dest_y;
int n;
string s;
int freq[50];

pair<ll, ll> after(ll days) {
    ll res_x = init_x, res_y = init_y;
    ll times = days / n;
    res_y += times * (freq['U'-'A'] - freq['D'-'A']);
    res_x += times * (freq['R'-'A'] - freq['L'-'A']);
    for (ll i = 0; i < days % n; i++) {
        if (s[i] == 'U') res_y++;
        if (s[i] == 'D') res_y--;
        if (s[i] == 'R') res_x++;
        if (s[i] == 'L') res_x--;
    }
    return {res_x, res_y};
}

ll dist(ll x1, ll y1, ll x2, ll y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

bool check(ll days) {
    auto wind = after(days);
    return dist(wind.first, wind.second, dest_x, dest_y) <= days;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> init_x >> init_y >> dest_x >> dest_y >> n >> s;
    for (auto d : s)
        freq[d-'A']++;

    ll l = 0, r = 1e14;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    if (check(r)) dokme(r);
    dokme(-1);

	return(0);
}
