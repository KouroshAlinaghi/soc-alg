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
#define dokme(x) cout << x << endl, exit(0)
#define ms(x , y) memset(x , y , sizeof x)
#define print(x) cout << x << endl

ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
string a[maxn];

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n, [](string str1, string str2) {
        auto smaller = str1.size() == min(str1.size(), str2.size()) ? str1 : str2;
        auto bigger = smaller == str1 ? str2 : str1;
        auto comp = smaller + string(bigger.size() - smaller.size(), smaller[smaller.size() - 1]) < bigger;
        return smaller == str1 ? comp : !comp;
    });

    for (int i = 0; i < n; i++) {
        cout << a[i];
    }
    cout << endl;

	return(0);
}
