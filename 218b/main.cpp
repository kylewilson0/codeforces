#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m, t, ans_min = 0, ans_max = 0;
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<> > min_heap;

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> t;
        max_heap.push(t);
        min_heap.push(t);
    }

    for (int i = 1; i <= n; i++) {
        int ticket = max_heap.top();
        ans_max += ticket;
        max_heap.pop();
        if (ticket > 1) max_heap.push(ticket - 1);
        ticket = min_heap.top();
        ans_min += ticket;
        min_heap.pop();
        if (ticket > 1) min_heap.push(ticket - 1);
    }
    cout << ans_max << " " << ans_min;
    return 0;
}
