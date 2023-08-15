#include <algorithm>
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

int a;

bool has(string& str) {
    for (auto c : str) 
        if (c == '8') 
            return true;
    return false;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> a;

    for (int x = a + 1; 1; x++) {
        auto str = to_string(x);
        if (has(str)) {
            print(x-a);
            return 0;
        }
    }

	return(0);
}
