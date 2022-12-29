#include <iostream>
#include <vector>

//D
void Insert(int x, int i, std::vector<int> &a) {
    a[i++] = x;
    int j = i - 1;
    while (j > 0 && a[j] > a[(j - 1) / 2]) {
        std::swap(a[j], a[(j - 1) / 2]);
        j = (j - 1) / 2;
    }
}

int Extract(std::vector<int> &a, int n) {
    int x = a[0];
    std::swap(a[0], a[--n]);
    int i = 0;
    while (2 * i + 1 < n) {
        int j = 2 * i + 1;
        if (j + 1 < n && a[j + 1] > a[j])
            j++;

        if (a[i] >= a[j])
            break;
        else {
            std::swap(a[i], a[j]);
            i = j;
        }
    }

    return x;
}

void D() {
    int n;
    std::cin >> n;

    std::vector<int> heap(n, 0);
    int i = 0;
    while (n--) {
        int com;
        std::cin >> com;
        if (com) {
            std::cout << Extract(heap, i--) << '\n';
        } else {
            int x;
            std::cin >> x;
            Insert(x, i++, heap);
        }
    }
}