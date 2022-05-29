#include <iostream>
#include <string>


int main()  {
    char symb;
    int it1 = 1;
    while ((symb = getchar()) != EOF) {
        if (symb == ' ' || symb == 0x0A) {
            std::cout << '\n';
        } else {
            std::cout << symb;
        }
        int ok = 1, k_ma, m_max, k_cur, m_cur, i;
        if (it1) {
            if (symb == '0') {
                ++k_max;
            }

        }

        // for (i = 0; i <  ssize_t(str.size()); ++i) {
        //     if (!(str[i] == '3' || str[i] == '4')) {
        //         break;
        //     }
        // }
        // for (int j = i; j <  ssize_t(str.size()); ++j) {
        //     if (!(str[j] == '1' || str[j] == '2')) {
        //         ok = 0;
        //         break;
        //     }
        // }
        // std::cout << ok << "\n";
    }
    return 0;
}