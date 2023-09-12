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

int k, ans_l_meow, ans_r_wagh;
ll ans;
bool a[maxn];
int p[maxn];

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> k;
    string str;
    cin >> str;
    p[0] = str[0] == '1';
    a[0] = p[0];
    p[str.size()] = mod;
    for (int i = 1; i < str.size(); i++) {
        a[i] = str[i] == '1';
        p[i] = p[i-1] + a[i];
    }

    for (int kooft = 0; kooft < str.size(); kooft++) {
        int l = kooft - 1, r = str.size();
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (p[mid] - p[kooft-1] > k) {
                r = mid;
            } else {
                l = mid;
            }
        }
        ans_r_wagh = l;
        l = kooft - 1, r = str.size();
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (p[mid] - p[kooft - 1] < k) {
                l = mid;
            } else {
                r = mid;
            }
        }
        ans_l_meow = r;
        ans += (ans_r_wagh - ans_l_meow + 1);
    }

    print(ans);

	return(0);
}
