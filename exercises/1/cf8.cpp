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

int t, n;
pair<char, int> state[maxn];

ll count_sheeps() {
    ll res = 0;
    for (auto c : state)
        res += c.first == '*';
    return res;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> t;
    char h;

    for (int test = 0; test < t; test++) {
        cin >> n >> h;
        state[0] = {h, h == '*'};
        for (int q = 1; q < n; q++) {
            cin >> h;
            state[q] = {h, state[q-1].second + (int)(h == '*')};
        }
        ll sheeps = state[n-1].second;
        int mid_i = 0;
        for (; state[mid_i].second <= sheeps/2; mid_i++);
        ll res = 0;
        for (int i = 0; i < n; i++) {
            if (state[i].first == '*' and i != mid_i) {
                res += abs(i - mid_i) - abs(state[mid_i].second - state[i].second);
            }
        }
        print(res);
    }

	return(0);
}
