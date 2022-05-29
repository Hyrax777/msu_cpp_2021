#include <algorithm>

template<typename randit, typename Predicat> 
void myapply(randit it1, randit it2, Predicat func) {
    for (auto i = it1; i != it2; ++i) {
        func(*i);
    }
}

template<typename randit, typename Predicat> 
void myapply(randit *it1, randit *it2, Predicat func) {
    for (auto i = it1; i != it2; ++i) {
        func(*i);
    }
}


template<typename randit, typename Predicat> 
auto myfilter2(randit it1, randit it2, Predicat func) {
    std::vector<std::reference_wrapper<typename randit::value_type>> vv;
    for (auto i = it1; i != it2; ++i) {
        if (func(*i)) {
            vv.push_back(std::ref(*i));
        }
    }
    return vv;
}

template<typename randit, typename Predicat> 
auto myfilter2(randit *it1, randit *it2, Predicat func) {
    std::vector<std::reference_wrapper<randit>> vv;
    for (auto i = it1; i != it2; ++i) {
        if (func(*i)) {
            vv.push_back(std::ref(*i));
        }
    }
    return vv;
}
