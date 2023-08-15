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

int n, x;
int a[maxn];
set<pii> s;

int get_i(int do_you_dream_of_armageddon) {
    for (int i = 0; i < n; i++)
        if (do_you_dream_of_armageddon == a[i])
            return i;
    return -1;
}

// I know it messes up when x = 2k and k is present in array, but just submitting to see 
// if the order is any good

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert({a[i], i});
    }
    
    for (int i = 0; i < n; i++) {
        auto meow_meow_nigga = s.upper_bound({x-a[i], i});
        if (meow_meow_nigga != s.end() && meow_meow_nigga->first == x-a[i]) {
            cout << i+1 << " " << s.upper_bound({x-a[i], i})->second+1;
            return 0;
        }
    }

    print(-1);

    return(0);
}

