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

int k;
string s;

bool check(int width) {
    int ind = 0;
    for (int i = 0; i < k; i++) {
        int last_space = -1;
        int last_hyphen = -1;
        for (int j = ind; j <= ind; j++) {
            if (s[j] == '-') last_hyphen = j;
            if (s[j] == ' ') last_space = j;
        }
        if (last_space > last_hyphen) {
            ind = last_space + 1;
            continue;
        }
        if (last_space == -1 && last_hyphen == -1) return false;
    }
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> k;
    getline(cin, s);
    int l = 0, r = 1e6 + 3;
    while (r - l > 1) {
        int mid = (r + l) / 2;

    }

    print(r);

	return(0);
}

