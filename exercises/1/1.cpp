#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;
    int n, p;
    string command;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "size") {
            cout << q.size() << endl;
        } else if (command == "pop") {
            if (q.empty()) {
                cout << -1 << endl;
            } else {
                cout << q.front() << endl;
                q.pop();
            }
        } else if (command == "push") {
            cin >> p;
            q.push(p);
            cout << q.size() << endl;
        }
    }

    return 0;
}
