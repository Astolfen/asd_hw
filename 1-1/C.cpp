#include <iostream>

//C
long long merge(int a[], int res[], int l, int r, int m) {
    long long count = 0;
    int i = l, j = m, k = l;
    while (i < m || j < r) {
        if (j < r && i < m && a[i] > a[j]) {
            count += m - i;
        }
        if (j == r || i < m && a[i] < a[j]) {
            res[k++] = a[i];
            i++;
        } else {
            res[k++] = a[j];
            j++;
        }
    }

    for (i = l; i < r; i++)
        a[i] = res[i];

    return count;
}

long long _mergeSort(int arr[], int temp[], int l, int r) {
    if (r - l <= 1) {
        return 0;
    } else {
        int m = (r + l) / 2;
        long long cl = _mergeSort(arr, temp, l, m);
        long long cr = _mergeSort(arr, temp, m, r);
        return merge(arr, temp, l, r, m) + cl + cr;
    }
}

long long mergeSort(int arr[], int array_size) {
    int temp[array_size];
    return _mergeSort(arr, temp, 0, array_size);
}

void C() {
    int n;
    std::cin >> n;

    int a[n];
    for (auto &i: a) {
        std::cin >> i;
    }

    long long count = mergeSort(a, n);

    std::cout << count;
}