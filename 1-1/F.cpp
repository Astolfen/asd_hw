#include <iostream>
#include <vector>

//F
int binSearch(std::vector<int> &a, int x) {
    int l = 0;
    int r = a.size();
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (a[m] <= x) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

long long abs(long long a, long long b) {
    if (a > b)
        return a - b;
    return b - a;
}

void F() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (auto &i: a) {
        std::cin >> i;
    }

    std::vector<int> b(k);
    for (auto &i: b) {
        std::cin >> i;
    }

    for (const auto &i: b) {
        int pos = binSearch(a, i);
        int res = pos;
        if (pos + 1 < a.size()) {
            res += abs(i, a[pos]) > abs(i, a[pos + 1]) ? 1 : 0;
        }
        std::cout << a[res] << '\n';
    }
}