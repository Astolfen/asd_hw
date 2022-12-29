#include <iostream>
#include <vector>

//B
void B() {
    std::vector<int> c(101, 0);
    int x;
    while (std::cin >> x) {
        c[x]++;
    }

    for (int i = 0; i < c.size(); i++) {
        if (c[i]) {
            while (c[i]--) {
                std::cout << i << ' ';
            }
        }
    }
}