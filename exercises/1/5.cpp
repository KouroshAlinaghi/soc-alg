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

set<int> s;
int n, p;
string command;

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "size") {
            print(s.size());
        } else if (command == "erase") {
            cin >> p;
            if (!s.empty()) {
                s.erase(p);
            }
        } else if (command == "insert") {
            cin >> p;
            s.insert(p);
        } else if (command == "empty") {
            print((s.empty() ? 1 : 0));
        } else if (command == "upper_bound") {
            cin >> p;
            auto sex = s.upper_bound(p);
            cout << (sex == s.end() ? -1 : *sex) << endl;
        } else if (command == "lower_bound") {
            cin >> p;
            auto sex = s.lower_bound(p);
            cout << (sex == s.end() ? -1 : *sex) << endl;
        } else if (command == "find") {
            cin >> p;
            cout << (s.find(p) == s.end() ? 0 : 1) << endl;
        }
    }

	return(0);
}