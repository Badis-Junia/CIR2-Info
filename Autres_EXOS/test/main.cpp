#include <iostream>


class Personne {
    private:
        int montest;
    public:
        int getTest() {
            return this->montest;
        }

        void setTest(int montest) {
            this->montest = montest;
        }


};
int main() {
    Personne test;
    test.setTest(3);
    int oiseau = test.getTest();
    std::cout << oiseau << std::endl;
    return 0;
}
