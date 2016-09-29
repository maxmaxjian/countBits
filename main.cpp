#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

using std::vector;

class solution {
  public:
    vector<int> countBits(int num) {
        vector<int> nbits(num+1);
        for (size_t i = 0; i < num+1; ++i) {
            if (i == 0)
                nbits[i] = 0;
            else if (std::bit_xor<int>()(i,i-1) == 0)
                nbits[i] = 1;
            else {
                int prev = (int)log2(i);
                nbits[i] = 1+nbits[i-(int)pow(2,prev)];
            }
        }
        return nbits;
    }
};

int main() {
    int num = 17;

    solution soln;
    auto nbits = soln.countBits(num);
    std::cout << "The number of bits of each number is:\n";
    std::for_each(nbits.begin(), nbits.end(), [](auto && i){std::cout << i << " ";});
    std::cout << std::endl;
}
