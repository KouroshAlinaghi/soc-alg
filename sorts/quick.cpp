#include <bits/stdc++.h>
#include <cstdlib>

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

void quick_sort(vector<int>& v, int n) {
    if (n <= 1) return;
    auto x = rand() % n;
    vector<int> res, left, right;
    int left_size = 0, right_size = 0;
    for (int i = 0; i < n; i++) {
        if (i == x) continue;
        if (v[i] < v[x]) {
            left.push_back(v[i]);
            left_size++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == x) continue;
        if (v[i] >= v[x]) {
            right.push_back(v[i]);
            right_size++;
        }
    }

    quick_sort(left, left_size);
    quick_sort(right, right_size);

    for (int i = 0; i < left_size; i++)
        res.push_back(left[i]);
    res.push_back(v[x]);
    for (int i = 0; i < right_size; i++)
        res.push_back(right[i]);

    v = res;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    int n;
    vector<int> v(maxn);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];

    quick_sort(v, n);

    for (auto i : v)
        cout << i << " ";
    cout << endl;

	return(0);
}

