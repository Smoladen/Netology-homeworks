// HW2-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <mutex>
#include <string>
#include <thread>
#include <vector>
#include <chrono>

HANDLE hStdOut;
std::mutex mutex;
COORD point;

void drawProgress( int tNum, int level)
{
    mutex.lock();
    auto tId = std::this_thread::get_id();
    auto timerBeg = std::chrono::high_resolution_clock::now();
    mutex.unlock();

    for (int i = 0; i < level; i++)
    {
        mutex.lock();
        point.X = i;
        point.Y = tNum * 2;
        SetConsoleCursorPosition(hStdOut, point);
        std::cout << char(219);
        mutex.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    mutex.lock();
    auto timerEnd = std::chrono::high_resolution_clock::now();
    auto timeElapsed = std::chrono::duration_cast<std::chrono::duration<double, std::ratio<1> > >(timerEnd - timerBeg).count();
    point.X = level+5;
    point.Y = tNum * 2;
    SetConsoleCursorPosition(hStdOut, point);
    std::cout << "  #" << tNum + 1 << "  ID = " << tId << "   Timer = " << timeElapsed << std::endl;
    mutex.unlock();
}

int main()
{
    int tCount{ 4 };
    int pLen{ 20 };

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    std::vector<std::thread> vThread(tCount);

    for (int i = 0; i < tCount; i++)
    {
        vThread[i] = std::thread(drawProgress, i, pLen);
    }
    for (auto& i : vThread)
    {
        i.join();
    }
    point.X = 0;
    point.Y = tCount * 2;
    SetConsoleCursorPosition(hStdOut, point);


}


//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <vector>
//#include <chrono>
//#include <random>
//#include <iomanip>
//#include <sstream>
//#include <windows.h>

//std::mutex console_mutex;

//void move_cursor_to(int x, int y) {
//    COORD coord;
//    coord.X = x;
//    coord.Y = y;
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}

//void thread_function(int thread_num, int length, int min_delay, int max_delay, int y_pos) {
//    std::random_device rd;
//    std::mt19937 gen(rd());
//    std::uniform_int_distribution<> dis(min_delay, max_delay);
//    std::uniform_int_distribution<> error_dis(0, 9);

//    auto start_time = std::chrono::high_resolution_clock::now();
//    std::ostringstream progress;
//    progress << "Поток " << thread_num << " [ID " << std::this_thread::get_id() << "]: [";

//    for (int i = 0; i < length; ++i) {
//        std::this_thread::sleep_for(std::chrono::milliseconds(dis(gen)));

//        // Генерация случайной ошибки с вероятностью 10%
//        bool error_occurred = error_dis(gen) == 0;
//        {
//            std::lock_guard<std::mutex> lock(console_mutex);
//            move_cursor_to(0, y_pos);
//            if (error_occurred) {
//                std::cout << "\033[31m";
//                progress << "X";
//            }
//            else {
//                std::cout << "\033[32m";
//                progress << "#";
//            }
//            std::cout << "\033[0m";
//            std::cout << progress.str() << std::setw(length - i) << "]" << std::flush;
//        }
//    }

//    auto end_time = std::chrono::high_resolution_clock::now();
//    std::chrono::duration<double> elapsed = end_time - start_time;

//    {
//        std::lock_guard<std::mutex> lock(console_mutex);
//        move_cursor_to(0, y_pos);
//        std::cout << progress.str() << std::setw(length - 1) << "] - выполнено за "
//                  << elapsed.count() << "s\n";
//    }
//}

//int main() {
//    setlocale(LC_ALL, "RU");
//    const int num_threads = 5; // количество потоков
//    const int bar_length = 20; // длина прогресс-бара
//    const int min_delay = 100; // минимальная задержка
//    const int max_delay = 300; // максимальная задержка

//    std::vector<std::thread> threads;

//    for (int i = 0; i < num_threads; ++i) {
//        threads.emplace_back(thread_function, i + 1, bar_length, min_delay, max_delay, i);
//    }

//    for (auto& thread : threads) {
//        thread.join();
//    }

//    return 0;
//}
