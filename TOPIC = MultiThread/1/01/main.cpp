#include <iostream>
#include <thread>
int maxClients = 25;

void clientImitator(int& numOfClients){

    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if (numOfClients < maxClients) {
            numOfClients++;
            std::cout << "Current number of Clients: " << numOfClients << std::endl;
        } else {
            std::cout << "Reached limit. Current Number of Clients: " << numOfClients << std::endl;
            break;
        }
    }
}
void operatorImitator(int& numOfClients){
    while (true) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    if (numOfClients > 0) {
        numOfClients--;
        std::cout << "Client served. Clients Left: " << numOfClients  << std::endl;
    } else {
        std::cout << "No more clients to serve. Exiting." << std::endl;
        break;
    }
}
}
int main()
{

    int numOfClients = 0;
    std::thread client{ clientImitator, std::ref(numOfClients) };

    std::thread Operator{ operatorImitator, std::ref(numOfClients)};


    client.join();
    Operator.join();


    return 0;
}
