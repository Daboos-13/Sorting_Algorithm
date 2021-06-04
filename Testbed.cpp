//
//
#include <time.h>
#include "BubbleSort.h"
#include "MergeSorter.h"
#include "Testbed.h"
#include <random>
#include <c++/4.8.3/functional>
#include <chrono>
using namespace std::chrono;
using namespace std;
int *Testbed::generateRandomList( const int &min,const   int &max, const int &size) {
    int * arr = new int [size];

    unsigned seed  = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(min,max);

    for (int i = 0; i <size ; ++i) {
        int dice_roll = distribution(generator);
        arr[i]=dice_roll;
    }
    return arr;
}

double Testbed::runOnce(const string &sorter, int *data, const int &size) {
    BubbleSort* bubbleSort;
    MergeSorter* mergeSorter;

    if (sorter=="bubble"){
        bubbleSort = new BubbleSort;
        auto startTime = high_resolution_clock::now();
        bubbleSort->sort(data,size);
        auto endTime = high_resolution_clock::now();
        auto elapsed = duration_cast<milliseconds>(endTime - startTime);
        double avgTime = elapsed.count();
        return avgTime;

    }else if (sorter=="merge"){




    }
}

double Testbed::runAndAverage(const string &sorter,const int &min, const int &max, const int &size) {
    double avg{};
    for (int i = 0; i <10 ; ++i) {
        int *arr= generateRandomList(min,max,size);
        avg+= runOnce(sorter,arr,size);

    }
    return avg;
}

double *Testbed::runExperiment(const string &sorter, int min, int max, int MIN_SIZE, int MAX_SIZE) {
    int step= MAX_SIZE/10;
    auto *arr = new double [10];
    for (int i = MIN_SIZE,j=0; i <= MAX_SIZE;i+=step ,j++) {
        arr[j]=runAndAverage(sorter,min,max,i);

    }
    return arr;

}


