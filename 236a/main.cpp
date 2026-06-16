#include <iostream>
using namespace std;

constexpr char msg[2][20] = {"IGNORE HIM!", "CHAT WITH HER!"};

int main() {
    bool a[26] = {false};
    char ch;
    while (scanf("%c", &ch) != EOF && ch != '\n') a[ch - 'a'] = true;

    int tot = 0;
    for (const bool i: a) if (i) tot++;

    if (tot & 1) printf("%s\n", msg[0]);
    else printf("%s\n", msg[1]);
    return 0;
}
