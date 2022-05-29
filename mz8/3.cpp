#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cin;
using std::cout;

Figure* make_figure(char let,  string str) {
    if (let == 'S') {
        return Square::make(str);
    } else if (let == 'R') {
        return Rectangle::make(str);
    } else if (let == 'C') {
        return Circle::make(str);
    } else {
        return nullptr;
    }
}


bool compar(const Figure *fig1, const Figure *fig2) {
    return (fig1->get_square() < fig2->get_square());
}

int main() {
    char tp;
    vector<Figure*> figs;
    while (cin >> tp) {
        string prm;
        std::getline(cin, prm);
        figs.push_back(make_figure(tp, prm));
    }
    std::stable_sort(figs.begin(), figs.end(), compar);
    for (auto i = figs.begin(); i != figs.end(); ++i) {
        cout << (*i)->to_string() << "\n";
        delete *i;
    }
    return 0;
}
