#include <vector>

//A
std::vector<int> merge(std::vector<int> &l, std::vector<int> &r) {
    std::vector<int> c(l.size() + r.size());
    int i = 0, j = 0;
    while (i < l.size() || j < r.size()) {
        if (j == r.size() || i < l.size() && l[i] < r[j]) {
            c[i + j] = l[i];
            i++;
        } else {
            c[i + j] = r[j];
            j++;
        }
    }
    return c;
}

std::vector<int> Sort(std::vector<int> &a) {
    int n = a.size();
    if (n == 1)
        return a;
    else {
        std::vector<int> l(a.begin(), a.begin() + n / 2);
        std::vector<int> r = {a.begin() + n / 2, a.end()};
        l = Sort(l);
        r = Sort(r);
        return merge(l, r);
    }
}