#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

int main(){
    int a[] = {7, 4, 9, 1, 3, 4, 8, 2, 7, 5, 3, 6, 10, 4, 8, 10, 1, 2};
    std::multiset<int> s(&a[0], &a[17]);
    std::multiset<int>::iterator p = s.begin();
    while (p != s.end()) std::cout << *p++ << " ";
    std::cout << std::endl;
    std::cout << "test"<<std::endl;

    std::vector<int> test = {1,2};
    std::sort(test.begin(), test.end());
    return 0;
}
