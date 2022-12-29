#include <iostream>
#include <vector>
#include <algorithm>

//E
int binSearchMax(std::vector<int> &a, int x) {
    int l = -1;
    int r = a.size();
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (a[m] > x) {
            r = m;
        } else {
            l = m;
        }
    }
    return r;
}

int binSearchMin(std::vector<int> &a, int x) {
    int l = -1;
    int r = a.size();
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (a[m] < x) {
            l = m;
        } else {
            r = m;
        }
    }
    return r;
}

void E() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (auto &i: a) {
        std::cin >> i;
    }

    std::sort(a.begin(), a.end());

    int k;
    std::cin >> k;
    for (int i = 0; i < k; i++) {
        int l, r;
        std::cin >> l >> r;
        int xl = binSearchMin(a, l);
        int xr = binSearchMax(a, r);
        std::cout << xr - xl << ' ';
    }
}