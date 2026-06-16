#include <iostream>

using namespace std;

int main() {
    freopen("a.in", "r",stdin);
    freopen("a.out", "w",stdout);

    int n, t;
    string s;
    cin >> n >> t >> s;
    for (int i = 0; i < t; i++) {
        int j = 0;
        while (j < s.size() - 1) {
            if (s[j] == 'B' && s[j + 1] == 'G') {
                swap(s[j], s[j + 1]);
                j++;
            }
            j++;
        }
    }

    cout << s << endl;
    return 0;
}
