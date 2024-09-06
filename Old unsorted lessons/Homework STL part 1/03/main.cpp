#include <iostream>
#include <stdexcept>

template<typename T>
class Vector {
private:
    T* data;         // указатель на массив элементов
    size_t current_size;  // текущее количество элементов
    size_t allocated_size; // текущий размер выделенной памяти

    void allocate(size_t new_size) {
        T* new_data = new T[new_size];
        // копируем старые элементы в новый массив
        for (size_t i = 0; i < current_size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;  // удаляем старый массив
        data = new_data;  // переключаем указатель на новый массив
        allocated_size = new_size;  // обновляем выделенный размер
    }

public:
    // конструктор по умолчанию
    Vector() : data(nullptr), current_size(0), allocated_size(0) {}

    // деструктор
    ~Vector() {
        delete[] data;
    }

    // доступ к элементу по индексу (ат)
    T& at(size_t index) {
        if (index >= current_size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // добавление элемента в конец массива
    void push_back(const T& value) {
        if (current_size >= allocated_size) {
            size_t new_size = (allocated_size == 0) ? 1 : allocated_size * 2;
            allocate(new_size);
        }
        data[current_size++] = value;
    }

    // количество элементов в контейнере
    size_t size() const {
        return current_size;
    }

    // количество элементов, которое может вместить контейнер
    size_t capacity() const {
        return allocated_size;
    }
};
int main() {
    Vector<int> vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    std::cout << "Size: " << vec.size() << std::endl;
    std::cout << "Capacity: " << vec.capacity() << std::endl;

    std::cout << "Elements:";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << " " << vec.at(i);
    }
    std::cout << std::endl;

    return 0;
}
