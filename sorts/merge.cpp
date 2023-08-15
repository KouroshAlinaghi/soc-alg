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

vector<int> merge_sort(vector<int>& v, int n) {
    if (n == 1) return v;

    vector<int> ans, left, right;
    for (int i = 0; i < n / 2; i++)
        left.push_back(v[i]);
    for (int i = n / 2; i < n; i++)
        right.push_back(v[i]);

    left = merge_sort(left, n / 2);
    right = merge_sort(right, (n + 1) / 2);

    auto l = left.begin(), r = right.begin();

    while (l < left.end() && r != right.end()) {
        if (*l > *r) {
            ans.push_back(*r);
            r++;
        } else {
            ans.push_back(*l);
            l++;
        }
    }
    while (r != right.end()) {
        ans.push_back(*r);
        r++;
    }
    while (l != left.end()) {
        ans.push_back(*l);
        l++;
    }
    return ans;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    vector<int> v(maxn);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];

    v = merge_sort(v, n);

    for (auto i : v)
        cout << i << " ";
    cout << endl;

	return(0);
}
