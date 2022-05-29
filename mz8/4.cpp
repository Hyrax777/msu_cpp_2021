#include <cmath>

namespace Game {
    template <typename T>
    class Coord {
    public:
        T row, col;
        typedef T value_type;
        Coord(): row(), col() {}
        Coord(value_type arg1 = 0): row(arg1), col() {}
        Coord(value_type arg1 = 0, value_type arg2 = 0): row(arg1), col(arg2) {}
    };

    template <typename T>
    T dist(Coord<T>& size, Coord<T>& p1, Coord<T>& p2) {
        T x1 = p1.col;
        T z1 = p1.row - (p1.col + (p1.col & 1)) / 2;
        T y1 = -x1 - z1;
        T x2 = p2.col;
        T z2 = p2.row - (p2.col + (p2.col & 1)) / 2;
        T y2 = -x2 - z2;
        return (abs(x1 - x2) + abs(y1 - y2) + abs(z1 - z2)) / 2;
    }
}