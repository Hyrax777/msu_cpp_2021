template<typename Container> 
auto process(Container cont) {
    typename Container::value_type sum {};
    int cnt  = 0;
    for (auto it = cont.rbegin(); (it != cont.rend()) && (cnt <= 5); ++it) {
        if (cnt % 2 == 0) {
            sum += *it;
        }
        ++cnt;
    }
    return sum;
}
