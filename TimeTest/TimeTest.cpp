////
//// Created by lukasz on 11/6/16.
////

#include "TimeTest.h"
#include "../FileReader/FileLoader.h"
#include <iostream>
TimeTest::TimeTest() {

}

double TimeTest::testAsync(int times,std::string fileName) {

    std::cout << "ASYNC FOR FILE NAMED: " << fileName << std::endl;
    //std::string fileName;
    //printf("Give filename: ");
    //std::cin >> fileName;
    file.open(fileName,std::ios_base::in);
    int size;
    if(file.is_open()) {
        file >> size;
        //printf("SIZE: %d \n",size);
        std::vector<int> data;
        int p;
        while(file >> p){
            data.push_back(p);
        }
        file.close();
        TSPAnnealing tspAnnealing(size);
        tspAnnealing.insertDataToArrayFullMatrixAsymetric(data);
        int sum = 0;
        start = std::chrono::steady_clock::now();
        for(int i = 0 ; i < times; i++) {
            sum+=tspAnnealing.calucateDistance(tspAnnealing.getResult());
        }
        tspAnnealing.deleteArray();
        end = std::chrono::steady_clock::now();
        std::cout<<"TOTAL TIME: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
        std::cout << "Time difference[ms] = " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()/times <<std::endl;
        std::cout << "Time difference[ns] = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - start).count()/times <<std::endl;
        std::cout <<"AVERAGE DISTANCE = " << sum/times << std::endl;
    }


}
//
double TimeTest::testSync(int times,std::string fileName) {
    std::cout << "SYNC FOR FILE NAMED: " << fileName << std::endl;
    //std::string fileName;
  //  printf("Give filename: ");
   // std::cin >> fileName;
    double sum = 0;
    file.open(fileName,std::ios_base::in);
    int size;
    if(file.is_open()) {
        file >> size;
        std::vector<int> data;
        int p;
        while(file >> p){
            data.push_back(p);
        }
        file.close();
        TSPAnnealing tspAnnealing(size);
        tspAnnealing.insertDataToArrayLowerTriangleMatrixSymetric(data);
        start = std::chrono::steady_clock::now();
        for(int i = 0 ; i < times; i++) {
//            printf("DISTANCE: %d \n",tspAnnealing.calucateDistance(tspAnnealing.getResult()));
            sum+=tspAnnealing.calucateDistance(tspAnnealing.getResult());
        }
        tspAnnealing.deleteArray();
        end = std::chrono::steady_clock::now();
        std::cout<<"TOTAL TIME: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
        std::cout << "Time difference[ms] = " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()/times <<std::endl;
        std::cout << "Time difference[ns] = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - start).count()/times <<std::endl;
        std::cout <<"AVERAGE DISTANCE = " << sum/times << std::endl;
    }


}
