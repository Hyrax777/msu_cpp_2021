#include <iostream>
#include <cmath>

long long min(long long a, long long b) {
    return a < b ? a : b;
}

int main() {
    long long m, n, r1, c1, r2, c2, var1, var2, var3, sum = 0;
    std::cin >> m >> n;
    while (std::cin >> r1 >> c1 >> r2 >> c2) {
        sum = 0;
        var1 = abs(r2 - r1);
        var2 = abs(r2 - 0) + abs(r1 - m);
        var3 = abs(r2 - m) + abs(r1 - 0);
        sum += min(min(var1, var2), var3);
        var1 = abs(c2 - c1);
        var2 = abs(c2 - 0) + abs(c1 - n);
        var3 = abs(c2 - n) + abs(c1 - 0);
        sum += min(min(var1, var2), var3);
        std::cout << sum << "\n";
    }
    return 0;
}