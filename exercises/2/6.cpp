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

int a[maxn];
int b[maxn];
ll cnt;

void merge(int l, int mid, int r) {
    int i = l, j = mid, k = l;
    while (i < mid && j < r) {
        if (a[i] >= a[j]) {
            b[k] = a[j];
            j++;
            cnt += mid - i;
        } else {
            b[k] = a[i];
            i++;
        }
        k++;
    }
    while (j < r) {
        b[k] = a[j];
        j++;
        k++;
    }
    while (i < mid) {
        b[k] = a[i];
        i++;
        k++;
    }
    for (int q = l; q < r; q++) {
        a[q] = b[q];
    }
}

void merge_sort(int l, int r) {
    if (r - l <= 1) return;
    int mid = (l + r) / 2;

    merge_sort(l, mid);
    merge_sort(mid, r);

    merge(l, mid, r);
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    merge_sort(0, n);
    print(cnt);

	return(0);
}
