#include <algorithm>
#include <cmath>
#include <vector>>

void abssort(float* x, unsigned n) {
    std::sort(x, x + n,
        // Lambda expression begins
        [](float a, float b) {
            return (std::abs(a) < std::abs(b));
        } // end of lambda expression
    );
}

int main() {
    std::vector<float> v_f{1.1, 1.3, 0.9, 4.2, 0.2, 0.6};
    abssort(static_cast v_f.begin(), v_f.size());

    for (auto const f : arr1) {

    }

}