#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>
#include <numeric>

void partial_sum(const std::vector<int>& vec1, const std::vector<int>& vec2, std::vector<int>& result, size_t start, size_t end) {
    for (size_t i = start; i < end; ++i) {
        result[i] = vec1[i] + vec2[i];
    }
}

double run_test(int num_elements, int num_threads) {
    std::vector<int> vec1(num_elements, 1);
    std::vector<int> vec2(num_elements, 2);
    std::vector<int> result(num_elements, 0);

    size_t chunk_size = num_elements / num_threads;
    std::vector<std::thread> threads;

    auto start_time = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < num_threads; ++i) {
        size_t start = i * chunk_size;
        size_t end = (i == num_threads - 1) ? num_elements : start + chunk_size;
        threads.emplace_back(partial_sum, std::cref(vec1), std::cref(vec2), std::ref(result), start, end);
    }

    for (auto& th : threads) {
        th.join();
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;

    return elapsed.count();
}

int main() {

    unsigned int num_cores = std::thread::hardware_concurrency();
    std::cout << "Ammount of operative cores: " << num_cores << std::endl;


    std::vector<int> sizes = {1000, 10000, 100000, 1000000};

    std::vector<int> threads = {1, 2, 4, 8, 16};



//    for (int size : sizes) {
//        for (int num_threads : threads) {
//            double time_taken = run_test(size, num_threads);
//            std::cout << size << "            | " << num_threads << "      | " << time_taken << " sec\n";
//        }
//    }

    std::cout << "         1000          10000         100000        1000000\n";
    for (int t : threads) {
        std::cout << t << " threads ";
        for (int size : sizes) {
            double time_taken = run_test(size, t);
            std::cout << time_taken << "s    ";
        }
        std::cout << std::endl;
    }
    return 0;
}

