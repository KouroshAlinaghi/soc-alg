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
int a[maxn], b[maxn];

int part(int l, int r) {
    int last = a[r], g = l - 1;
    for (int i = l; i < r; i++) {
        if (a[i] <= last) {
            g++;
            swap(a[i], a[g]);
        }
    }
    
    swap(a[++g], a[r]);
    return g;
}

void quick_sort(int l = 0, int r = n -1) {
    if (l >= r) return;

    int p = part(l, r);

    quick_sort(l, p - 1);
    quick_sort(p + 1, r);
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    quick_sort();

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

	return(0);
}

