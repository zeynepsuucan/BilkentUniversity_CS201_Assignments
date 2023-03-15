// written by Zeynep Su Uçan - 22103044
// CS 201- section 3

#include <iostream>
#include <ctime>
#include "findMedian.h"
#include <string>
using namespace std;
int main()
{
    string cont;
    do{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    int* randArray1 = new int[size];
    int* randArray2 = new int[size];
    int* randArray3 = new int[size];

    for (int i = 0; i < size; i++){
        randArray1[i] = (rand() % size*2) - size;
        randArray2[i] = randArray1[i];
        randArray3[i] = randArray1[i];
    }

    double duration;
    clock_t startTime = clock();
    FIND_MEDIAN_1(randArray1, size);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << "Execution 1 took " << duration << " milliseconds." << endl;

    double duration2;
    clock_t startTime2 = clock();
    FIND_MEDIAN_2(randArray2, size);
    duration2 = 1000 * double(clock() - startTime2) / CLOCKS_PER_SEC;
    cout << "Execution 2 took " << duration2 << " milliseconds." << endl;
    
    double duration3;
    clock_t startTime3 = clock();
    FIND_MEDIAN_3(randArray3, size);
    duration3 = 1000 * double(clock() - startTime3) / CLOCKS_PER_SEC;
    cout << "Execution 3 took " << duration3 << " milliseconds." << endl;

    cout << "Would you like to continue? (write yes or no)" << endl;
    cin >> cont;
    cout << endl;

    delete[] randArray1;
    delete[] randArray2;
    delete[] randArray3;
    
    }while(cont == "yes");
}
