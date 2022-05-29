#include <iostream>
#include <vector>

using std::vector;

void process(vector<long long>& vv, long long thrs) {
    size_t cnt = 0;
    while (cnt < vv.size()) {
        for (auto iter = vv.rbegin() + cnt; iter< vv.rend(); ++iter) {
            ++cnt;
            if (*iter >= thrs) {
                vv.push_back(*iter);
                ++cnt;
                break;
            }
        }
    }
}
