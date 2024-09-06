#include <iostream>
#include "header.h"
// #include "vehicle.h"
// #include "ground_vehicle.h"
// #include "cammel.h"
// #include "cammel_speedboat.h"
// #include "centaur.h"
// #include "walking_boots.h"
// #include "eagle.h"
// #include "flying_carpet.h"
// #include "broom.h"

int main()
{
    while(true){

        vehicle vehicle;
        GroundVehicle GroundVehicle;
        cammel cammel;
        cammel_speedboat cammel_speedboat;
        centaur centaur;
        walking_boots walking_boots;
        eagle eagle;
        flying_carpet flying_carpet;
        broom broom;


        // std::cout << "CAMMEL " << cammel.calculateTime(distance) << std::endl;
        // std::cout << "CAMMEL SPEEDBOAT " << cammel_speedboat.calculateTime(distance) << std::endl;
        // std::cout << "CENTAUR " << centaur.calculateTime(distance) << std::endl;
        // std::cout << "WALKING BOOTS " << walking_boots.calculateTime(distance) << std::endl;
        // std::cout << "EAGLE " <<eagle.calculateTime(distance) << std::endl;
        // std::cout << "FLYING CARPET " <<flying_carpet.calculateTime(distance) << std::endl;
        // std::cout << "BROOM " <<broom.calculateTime(distance) << std::endl;
    double distance = 0;
    int RaceType = 0;
    int NumOfRegVehicle = 1;
    int decision = 0;
    int RegChoice = 0;
    bool buffer = true;
    int counter = 0;

    std::cout << "Добро пожаловать в симулятор гонок!" << std::endl;
    //arrays needed to store and get info from
    std::string nameRaceType[4] = { "null","Гонка для наземного транспорта.","Гонка для воздушного транспорта.","Гонка для наземного и воздушного транспорта." };
    int arrOfIndex[8]= {};
    double arrOfTime[8] = {};
    std::string arrOfNames[8] = {};
    std::string transport[8] = { "null","Ботинки - вездеходы", "Метла", "Верблюд", "Кентавр", "Орёл", "Верблюд-быстроход", "Ковёр-самолёт"};


    std::cout << "1. " << nameRaceType[1] << "\n2. " << nameRaceType[2] << "\n" <<"3. " << nameRaceType[3] << "\n" <<"Выберите тип гонки: ";
    std::cin >> RaceType;

    std::cout << "\nУкажите длинну дистанции (должна быть положительна): ";
    std::cin >> distance;

    do{
        if(NumOfRegVehicle >= 2){
            std::cout << "1. Зарегистрировать транспорт." << "\n2. Начать гонку.\n Выберите действие: ";
        }else{
            std::cout << "\nДолжно быть зарегистрировано хотябы 2 транспортных средства. \n 1. Зарегистрировать транспорт.\nВыберите действие: ";
        }
        std::cin >> decision;
        if(decision == 1){

            do{

                std::cout << nameRaceType[RaceType] << " Расстояние: " << distance;
                if(NumOfRegVehicle != 0){//if there are registered transports print them
                    std::cout << "\nЗарегистрированные транспортные средства: ";
                    for(int i = 1; i < NumOfRegVehicle; i++){
                        std::cout << arrOfNames[i] << ", ";
                    }
                }
                //printed list of vehicles
                std::cout <<  "\n 1. " << transport[1] << "\n 2. " << transport[2] << "\n 3. " << transport[3] << "\n 4. " << transport[4] << "\n 5. " << transport[5] << "\n 6. "
                << transport[6] << "\n 7. " << transport[7];
                std::cout <<"\n 0. Закончить регистрацию" << "\n Выберите транспорт или 0 для окончания процесса регистрации: ";
                std::cin >> RegChoice;
                if(RegChoice == 0)
                    break;
                if(RaceType == 1){//ground race registration
                    if(RegChoice == 1 || RegChoice == 3|| RegChoice == 4 || RegChoice == 6){
                        for(int i =1; i < 8; i++){
                            if(arrOfNames[i] == transport[RegChoice]){
                                std::cout << transport[RegChoice]<<" уже зарегистрирован.\n";
                                buffer = false;
                                break;
                            }
                        }
                        if(buffer){
                        arrOfIndex[NumOfRegVehicle] = RegChoice;
                        arrOfNames[NumOfRegVehicle] = transport[RegChoice];
                        ++NumOfRegVehicle;
                        std::cout << transport[RegChoice]<< " успешно зарегестрирован.\n";
                        buffer = true;
                        }
                    }else{
                        std::cout << "\nДанный тип транспорта не подходит для данной трассы!\n";
                        continue;
                    }
                }else if(RaceType == 2){//air race registration
                    if(RegChoice == 2 || RegChoice == 5|| RegChoice == 7){
                        for(int i =1; i < 8; i++){
                            if(arrOfNames[i] == transport[RegChoice]){
                                std::cout << transport[RegChoice]<<" уже зарегистрирован.\n";
                                buffer = false;
                                break;
                            }
                        }
                        if(buffer){
                            arrOfIndex[NumOfRegVehicle] = RegChoice;
                            arrOfNames[NumOfRegVehicle] = transport[RegChoice];
                            ++NumOfRegVehicle;
                            std::cout << transport[RegChoice]<< " успешно зарегестрирован.\n";
                            buffer = true;
                        }
                    }else{
                        std::cout << "\nДанный тип транспорта не подходит для данной трассы!\n";
                        continue;
                    }
                }else if(RaceType == 3){//ground and air race registration
                    if(RegChoice > 0 && RegChoice < 8){
                        for(int i =1; i < 8; i++){
                            if(arrOfNames[i] == transport[RegChoice]){
                                std::cout << transport[RegChoice]<<" уже зарегистрирован.\n";
                                buffer = false;
                                break;
                            }
                        }
                        if(buffer){
                            arrOfIndex[NumOfRegVehicle] = RegChoice;
                            arrOfNames[NumOfRegVehicle] = transport[RegChoice];
                            ++NumOfRegVehicle;
                            std::cout << transport[RegChoice]<< " успешно зарегестрирован.\n";
                            buffer = true;
                        }
                    }else{
                        std::cout << "\nДанный тип транспорта не подходит для данной трассы!\n";
                        continue;
                    }
                }
            }while(RegChoice != 0);
        }
    }while(decision != 2);
//checking for registrated vehicles and writing down time they need to cross the distance
    for(int i =0; i < 8; i++){
        if(arrOfIndex[i] == 1){
            arrOfTime[i] = walking_boots.calculateTime(distance);
            counter++;
        }else if(arrOfIndex[i] == 2){
            arrOfTime[i] = broom.calculateTime(distance);
            counter++;
        }else if(arrOfIndex[i] == 3){
            arrOfTime[i] = cammel.calculateTime(distance);
            counter++;
        }else if(arrOfIndex[i] == 4){
            arrOfTime[i] = centaur.calculateTime(distance);
            counter++;
        }else if(arrOfIndex[i] == 5){
            arrOfTime[i] = eagle.calculateTime(distance);
            counter++;
        }else if(arrOfIndex[i] == 6){
            arrOfTime[i] = cammel_speedboat.calculateTime(distance);
            counter++;
        }else if(arrOfIndex[i] == 7){
            arrOfTime[i] = flying_carpet.calculateTime(distance);
            counter++;
        }
    }
    //bubble sort to got them in proper order
    for(int i = 1; i<counter; i++){
        for(int j = 1; j<counter; j++){
            if(arrOfTime[j] > arrOfTime[j +1]){
                std::swap(arrOfTime[j], arrOfTime[j+1]);
                std::swap(arrOfNames[j], arrOfNames[j+1]);
            }
        }
    }
    std::cout << "\nРезультат гонки: ";
    for (int i = 1; i < counter + 1; ++i) {
        std::cout << "\n" << i << ". " << arrOfNames[i] << ". Время: " << arrOfTime[i];
    }
    std::cout << "\n\n1. Провести ещё одну гонку\n2. Выйти\nВыберите действие: ";
    std::cin >> decision;
    if(decision == 2){
        break;
    }
    }
    return 0;
}
