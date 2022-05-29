#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using std::cin;

int numb_bit(int a) {
    int cnt = 0;
    while (a) {
        if (a & 1) {
            ++cnt;
        }
        a = a >> 1;
    }
    return cnt;
}

bool cmp(int a, int b) {
    return numb_bit(a) < numb_bit(b);
}

int main() {
    std::vector<int>  vv;
    int exm;
    while (cin >> exm) {
        vv.push_back(exm);
    }
    std::stable_sort(vv.begin(), vv.end(), cmp);
    for (auto i: vv) {
        std::cout << i << "\n";
    }
    return 0;
}
