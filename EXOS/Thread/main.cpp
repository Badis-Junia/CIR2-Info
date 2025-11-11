#include <iostream>
#include <thread>
#include <chrono>

void test(int test) {
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); 
    std::cout << test << std::endl;
}

void test2(int test2) {
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); 
    std::cout << test2 << std::endl;
}

int main() {

    auto start_seq = std::chrono::high_resolution_clock::now();

    test(3);
    test2(5);

    auto end_seq = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration_seq = end_seq - start_seq;
    std::cout << "Temps séquentiel : " << duration_seq.count() << " ms" << std::endl << std::endl;


    auto start_par = std::chrono::high_resolution_clock::now();

    std::thread t1(test, 3);
    std::thread t2(test2, 5);

    t1.join();
    t2.join();

    auto end_par = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration_par = end_par - start_par;
    std::cout << "Temps parallèle : " << duration_par.count() << " ms" << std::endl;

    return 0;
}
