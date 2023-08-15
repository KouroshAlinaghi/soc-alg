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

int kir(int goh, int mode_kiri) {
    return (goh < 0) ? goh + mode_kiri : goh;
}

string f, s;

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> f >> s;

    auto f_h = stoi(f.substr(0, 2));
    auto f_s = stoi(f.substr(3, 2));
    auto s_h = stoi(s.substr(0, 2));
    auto s_s = stoi(s.substr(3, 2));

    cout << setfill('0') << setw(2) << kir((f_h - s_h - (f_s < s_s)), 24) << ":" << setfill('0') << setw(2) << kir((f_s - s_s), 60) << endl;

	return(0);
}
