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

string rec(ll i, bool s) {
    if (i >= n) return to_string(pw(2, i-1) + !s);
    return to_string(pw(2, i-1) - !s) + "+\\frac{" + rec(i+1, s) + "}{" + rec(i+1, !s) + "}";
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    print(rec(1, true));

	return(0);
}
