template<typename Container, typename Predicat> 
Container myfilter(Container& cont, Predicat f) {
    Container nw;
    for (auto it: cont) {
        if (f(it)) {
            nw.insert(nw.end(), it);
        }
    }
    return nw;
}