#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class big_integer{
private:
    std::string digids;
public:
    big_integer() : digids("0"){}

    big_integer(const std::string& str) : digids(str) {
        std::reverse(digids.begin(), digids.end());
    }

    big_integer(const big_integer &other) : digids(other.digids) {}

    big_integer(big_integer &&other) noexcept : digids(std::move(other.digids)) {}


    big_integer &operator=(const big_integer &other) {
        digids = other.digids;
        return *this;
    }
    big_integer &operator=(big_integer &&other) noexcept {
        digids = std::move(other.digids);
        return *this;
    }

    big_integer operator+(const big_integer& other) const {
        std::string result;
        int carry = 0;
        size_t maxLength = std::max(this->digids.length(), other.digids.length());

        for (size_t i = 0; i < maxLength; ++i) {
            int digit1 = (i < this->digids.length()) ? this->digids[i] - '0' : 0;
            int digit2 = (i < other.digids.length()) ? other.digids[i] - '0' : 0;
            int sum = digit1 + digit2 + carry;
            result.push_back((sum % 10) + '0');
            carry = sum / 10;
        }

        if (carry) {
            result.push_back(carry + '0');
        }


        std::reverse(result.begin(), result.end());
        return big_integer(result);
    }


    big_integer operator*(const big_integer& other) const {
        std::string result(this->digids.length() + other.digids.length(), '0');

        for (size_t i = 0; i < this->digids.length(); ++i) {
            int carry = 0;
            for (size_t j = 0; j < other.digids.length(); ++j) {
                int temp = (result[i + j] - '0') + (this->digids[i] - '0') * (other.digids[j] - '0') + carry;
                result[i + j] = (temp % 10) + '0';
                carry = temp / 10;
            }
            result[i + other.digids.length()] += carry;
        }


        while (result.length() > 1 && result.back() == '0') {
            result.pop_back();
        }

        std::reverse(result.begin(), result.end());
        return big_integer(result);
    }


    friend std::ostream& operator<<(std::ostream& os, const big_integer& bi) {
        std::string numberReversed = bi.digids;
        std::reverse(numberReversed.begin(), numberReversed.end());
        os << numberReversed;
        return os;
    }
};


int main()
{
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    auto result = number1 + number2;
    std::cout << result; // 193099
    return 0;
}
