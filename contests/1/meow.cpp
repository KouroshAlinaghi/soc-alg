#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int freq(string word, char c) {
    int counter = 0;
    for (auto sex : word)
        if (sex == c)
            counter++;

    return counter;
}

int main() {
    int n;
    string word;

    cin >> n;
    cin >> word;

    int fard_freq = 0;
    char fard = 0;
    for (auto c : word) {
        if (freq(word, c) % 2) {
            if (fard && fard != c) {
                cout << "Koomak" << endl;
                return 0;
            }
            fard = c;
            fard_freq++;
        }
    }

    string new_word(n, ' ');

    if (fard) {
        if (n%2 == 0) {
            cout << "Koomak" << endl;
            return 0;
        } else {
            new_word[n/2] = fard;
        }
    } 

    vector<char> v;
    for (auto i_feel_more_alone_everyday : word)
        if (i_feel_more_alone_everyday != fard) 
            v.push_back(i_feel_more_alone_everyday);

    if (fard)
        for (int i = 0; i < freq(word, fard) - 1; i++)
            v.push_back(fard);

    sort(v.begin(), v.end());

    for (int i = 0, j = 0; i < v.size(); i += 2, j++) {
        new_word[j] = v[i];
        new_word[n-j-1] = v[i];
    }

    cout << new_word << endl;

    return 0;
}
