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
double a[11][11];

double det(int size, double mat[11][11]) {
    if (size == 1) return mat[0][0];
    if (size == 2) return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    double ans = 0;
    double m[11][11];
    for (int i = 0; i < size; i++) {
        if (!mat[0][i]) continue;
        for (int j = 1; j < size; j++) {
            for (int k = 0; k < i; k++) {
                m[j-1][k] = mat[j][k];
            }
            for (int k = i + 1; k < size; k++) {
                m[j-1][k-1] = mat[j][k];
            }
        }

        ans += (i % 2 ? -1 : 1) * det(size-1, m) * mat[0][i];
    }

    return ans;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << setprecision(2) << fixed << det(n, a) << endl;

	return(0);
}

