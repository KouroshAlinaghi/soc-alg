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

int a, b, c, m;
multiset<ll> s_usb;
multiset<ll> s_ps2;

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> a >> b >> c >> m;
    for (int i = 0; i < m; i++) {
        ll sex;
        string type;
        cin >> sex >> type;
        if (type == "USB") {
            s_usb.insert(sex);
        } else {
            s_ps2.insert(sex);
        }
    }

    ll counter = 0;
    ll cost = 0;
    for (; a && s_usb.size(); a--) {
        cost += *s_usb.begin();
        s_usb.erase(s_usb.begin());
        counter++;
    }

    for (; b && s_ps2.size(); b--) {
        cost += *s_ps2.begin();
        s_ps2.erase(s_ps2.begin());
        counter++;
    }

    for (auto i : s_usb) {
        s_ps2.insert(i);
    }

    for (; c && s_ps2.size(); c--) {
        cost += *s_ps2.begin();
        s_ps2.erase(s_ps2.begin());
        counter++;
    }

    cout << counter << " " << cost << endl;

	return(0);
}

