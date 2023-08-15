#include <algorithm>
#include <bits/stdc++.h>
#include <cwctype>

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
int a[maxn];

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int left = 0, right = n - 1;
    int last_eq = 0;

    bool sorted = true;

    for (int l = 0; l < n - 1; l++) {
        last_eq += (a[l] == a[l+1]);
        if (a[l] > a[l+1]) {
            left = l - last_eq;
            sorted = false;
            break;
        }
    }

    last_eq = 0;
    for (int r = n - 1; r; r--) {
        last_eq += (a[r] == a[r-1]);
        if (a[r] < a[r-1]) {
            right = r + last_eq;
            sorted = false;
            break;
        }
    }

    if (sorted) {
        cout << "yes" << endl << (n > 1) << " " << (n > 1) << endl;
        return 0;
    }

    reverse(a + left, a + right + 1);

    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            print("no");
            return 0;
        }
    }

    print("yes");
    cout << left + 1 << " " << right + 1 << endl;

	return(0);
}
