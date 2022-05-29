#include <algorithm>
#include <vector>

using std::vector;

template<typename randit1, typename randit2>
randit2 myremove(randit1 del_numb_f, randit1 del_numb_s, randit2 numb_f, randit2 numb_s) {
    int cnt = 0;
    auto ans = numb_f;
    vector<int> v(del_numb_f, del_numb_s);
    std::sort(v.begin(), v.end());
    auto l = std::unique(v.begin(), v.end());
    auto it = v.begin();
    for (; *it < 0 && it != l; ++it);
    for (auto i = numb_f; i != numb_s; ++i) {
        if (it >= l) {
            std::iter_swap(ans++, i);
        } else {
            if (*it != cnt) {
                std::iter_swap(ans++, i);
            } else if (*it <= cnt) {
                ++it;
            }
        }
        ++cnt;
    }
    return ans;
}