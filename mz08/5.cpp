#include <complex>
#include <array>
#include <vector>
#include <limits>
#include <iostream>

using std::pair;
using std::vector;
using std::complex;
using std::norm;


namespace Equations {
    template <typename T>
    pair<bool, vector<complex<T>>> quadratic(std::array<complex<T>, 3> v) {
        const T eps = std::numeric_limits<T>::epsilon();
        if (norm(v[2]) < 32 * eps) {
            if (norm(v[1]) < 32 * eps) {
                if (norm(v[0]) < 32 * eps) {
                    return std::make_pair<bool, vector<complex<T>>>(false, {});
                }
                return std::make_pair<bool, vector<complex<T>>>(true, {}); 
            }
            return std::make_pair<bool, vector<complex<T>>>(true, {-v[0]/v[1]}); 
        }
        complex <T> discr = v[1]*v[1] - complex<T>(4)*v[0]*v[2];
        complex <T> x1 = (-v[1] + std::sqrt(discr))/(complex<T>(2)*v[2]);
        complex <T> x2 = (-v[1] - std::sqrt(discr))/(complex<T>(2)*v[2]);
        return std::make_pair<bool, vector<complex<T>>>(true, {x1, x2}); 
    } 
}

