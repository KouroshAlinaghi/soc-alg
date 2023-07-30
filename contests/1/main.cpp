#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b, c, x;
    cin >> a >> b >> c;

    vector<vector<int>> l(a, vector<int>(b, 0));
    vector<vector<int>> r(b, vector<int>(c, 0));

    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++) {
            cin >> x;
            l[i][j] = x;
        }

    for (int i = 0; i < b; i++)
        for (int j = 0; j < c; j++) {
            cin >> x;
            r[i][j] = x;
        }

    vector<vector<int>> res(a, vector<int>(c, 0));
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < c; j++) {
            for (int k = 0; k < b; k++) {
                res[i][j] += l[i][k] * r[k][j];
            }
        }
    }

    for (auto r : res) {
        for (auto i : r) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
