class C {
public:
    C() {};
    C(C v1, C v2) {};
    C(double v1){};
    C(const C* p){};
    C(int v1) {};

    operator int() const {
        return 0;
    };

    C operator+(int v2) {
        return 0;
    };
    C operator~() const {
        return 0;
    };
    C operator++() {
        return 0;
    };
    C operator*(C v2) {
        return 0;
    };
    C operator[](int v1) {
        return 0;
    };
};
