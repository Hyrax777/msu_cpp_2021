#include <iostream>
#include <vector>

using std::vector;

void process(const vector<unsigned long long>&first, vector<unsigned long long>&second, int step) {
    auto pnt = second.rbegin();
    for (auto iter = first.begin(); (iter < first.end()) && (pnt < second.rend()); iter += step) {
        *pnt += *iter;
        ++pnt;
    }
}
