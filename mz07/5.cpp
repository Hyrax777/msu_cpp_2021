#include <algorithm>

template<typename randit> 
void selection_sort(randit it1, randit it2) {
    for (auto i = it1; i != it2; ++i) {
        auto min = i;
        for (auto j = i + 1; j != it2; ++j) {
            if (*j < *min) {
                min = j;
            }
        }
        if (min != i) {
            std::iter_swap(i, min);
        }
    }
}


template<typename randit, typename Predicat> 
void selection_sort(randit it1, randit it2, Predicat func) {
    for (auto i = it1; i != it2; ++i) {
        auto min = i;
        for (auto j = i + 1; j != it2; ++j) {
            if (func(*j, *min)) {
                min = j;
            }
        }
        if (min != i) {
            std::iter_swap(i, min);
        }
    }
}
