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
double x[maxn];
double v[maxn];

double calc_time(double dest) {
    double max_time_sex = -1;
    for (int i = 0; i < n; i++)
        max_time_sex = max(max_time_sex, abs((x[i]-dest))/v[i]);
    return max_time_sex;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++)
        cin >> v[i];

    double l = 0, r = 1e9;
    for (int i = 0; i < 200; i++) {
        double left_mid = (r - l) / 3 + l;
        double right_mid = (r + left_mid) / 2;
        if (calc_time(left_mid) > calc_time(right_mid)) {
            l = left_mid;
        } else {
            r = right_mid;
        }
    }
    
    cout << setprecision(9) << fixed << calc_time(l) << endl;

	return(0);
}

