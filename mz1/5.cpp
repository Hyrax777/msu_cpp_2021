#include <iostream>

using std::hex;
using std::dec;
using std::cin;
using std::cout;

enum
{
    CNT = 4, // число байт в числе
};

int main() {
    uint32_t off, numb, input, ok = 1;
    const uint32_t BIAS[4] = {24, 16, 8, 0};  // смещения байтов
    while (cin >> hex >> off) {
        for (int j = 0; j < CNT; ++j) {
            numb = 0;
            ok = 1;
            for (int i = 0; i < CNT; ++i) {
                if (cin >> hex >> input) {
                    numb |= input << BIAS[i];
                } else {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                cout << dec << numb << '\n';
            } else {
                break;
            }
        }

    }
    return 0;
}