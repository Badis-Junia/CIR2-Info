#include <iostream>
#include <vector>

int main() {
    std::vector<int> test = {1,2,4,1,2,9,4};
    for(long unsigned int i = 0;i<test.size();i++) {
        std::cout << test[i];
    }
}
