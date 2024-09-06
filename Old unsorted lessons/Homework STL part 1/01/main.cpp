#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

bool comparePairs(const std::pair<char,int>& a, const std::pair<char,int>& b){
    return b.second < a.second;
}

int main()
{
    std::string phrase;
    //We March for Macrage!
    std::cout << "[IN]: "<< std::endl;
    std::getline(std::cin, phrase);

    std::map<char,int> frequency;
    for(char c : phrase){
        frequency[c]++;
    }

    std::vector<std::pair<char,int>> freq_vect(frequency.begin(), frequency.end());

    std::sort(freq_vect.begin(), freq_vect.end(), comparePairs);

    for(const auto& p : freq_vect){
        std::cout << p.first << ": "<< p.second << std::endl;
    }
    return 0;
}
