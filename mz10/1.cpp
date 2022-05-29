#include <iostream>
#include <string>


int main()  {
    std::string str;
    while (std::cin >> str) {
        int ok = 1;
        int i = 0;
        for (i = 0; i <  ssize_t(str.size()); ++i) {
            if (!(str[i] == '3' || str[i] == '4')) {
                break;
            }
        }
        for (int j = i; j <  ssize_t(str.size()); ++j) {
            if (!(str[j] == '1' || str[j] == '2')) {
                ok = 0;
                break;
            }
        }
        std::cout << ok << "\n";
    }
    return 0;
}
