#include <iostream>
using namespace std;

int main() {
    string st;
    cin >> st;
    int start = 0, end = st.size();

    while (start + 3 < end && st.substr(start, 3) == "WUB") start += 3;
    while (end - 3 > start && st.substr(end - 3, 3) == "WUB") end -= 3;

    while (start < end) {
        while (start < end && st.substr(start, 3) != "WUB") cout << st[start++];
        if (start < end) cout << " ";
        while (start < end && st.substr(start, 3) == "WUB") start += 3;
    }
    return 0;
}
