#include <iostream>
#include <iomanip>
#include <math.h>

int main() {
    double a, mean = 0, sum_sq = 0, sigma;
    int numb = 0;
    while (std::cin >> a) {
        numb++;
        mean += a;
        sum_sq += a*a;
    }
    mean /= numb;
    sigma = sqrt(sum_sq/numb - mean*mean);
    std::cout << std::fixed <<std::setprecision(10) << mean << '\n' << sigma << '\n';
    return 0;
}
