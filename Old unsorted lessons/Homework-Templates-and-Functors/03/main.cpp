#include <iostream>
#include <vector>
#include <algorithm>

class Counter {
private:
    int sum;
    int count;

public:
    Counter() : sum(0), count(0) {}

    void operator()(int number) {
        if (number % 3 == 0) {
            sum += number;
            count++;
        }
    }

    int get_sum() const {
        return sum;
    }

    int get_count() const {
        return count;
    }
};

int main() {
    std::vector<int> numbers = {4, 1, 3, 6, 25, 54};

    Counter counter = std::for_each(numbers.begin(), numbers.end(), Counter());

    std::cout << "get_sum() = " << counter.get_sum() << std::endl;
    std::cout << "get_count() = " << counter.get_count() << std::endl;

    return 0;
}
