#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Sum
{
    void operator()(double n) { sum += n; }
    double sum{0};
};


int main() {
    std::vector<double> vv;
    int len = 0;
    double exm;
    while (std::cin >> exm) {
        vv.push_back(exm);
        ++len;
    }
    int quant = len / 10;
    vv.erase(vv.begin(), vv.begin() + quant);
    vv.erase(vv.end() - quant, vv.end());
    quant = vv.size() / 10;
    std::sort(vv.begin(), vv.end());
    vv.erase(vv.begin(), vv.begin() + quant);
    vv.erase(vv.end() - quant, vv.end());
    Sum s = std::for_each(vv.begin(), vv.end(), Sum());
    std::cout << std::fixed << std::setprecision(10) << s.sum / vv.size();
    return 0;
}