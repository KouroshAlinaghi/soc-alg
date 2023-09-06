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
int h[maxn], p[maxn];

bool can_break(int x) {
    if (x) {
        p[0]++;
        p[x]--;
        p[n-x]++;
        p[n]--;
    }
    for (int i = 0; i < n; i++) {
        int ezaf = x - h[i];
        if (ezaf < 0) continue;
        p[max(0, i - ezaf)]++;
        p[min(n - 1, i + ezaf) + 1]--;
    }

    for (int i = 1; i < n; i++)
        p[i] += p[i-1];

    for (int i = 0; i < n; i++) {
        if (p[i] <= 0) return false;
    }
    return true;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> h[i];

    int l = 0, r = (n+2)/2, mid = 0;
    while (r - l > 1) {
        mid = (r + l) / 2;
        if (can_break(mid)) {
            r = mid;
        } else {
            l = mid;
        }
        for (int i = 0; i <= n; i++) p[i] = 0;
    }

    if (can_break(l)) dokme(l);
    dokme(r);

	return(0);
}

