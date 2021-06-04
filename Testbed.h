//
//

#ifndef TASK4_CODE_TESTBED_H
#define TASK4_CODE_TESTBED_H
#include "Sorter.h"
#include <string>
using namespace std;
class Sorter;
class Testbed {
private:

public:
    int* generateRandomList( const int &min , const int &max , const int &size);
    double runOnce(const string & sorter, int* data , const int & size);
    double runAndAverage(const string &sorter,const int &min , const int &max ,const int &size );
    double* runExperiment(const string & ,int min , int max , int MIN_SIZE, int MAX_SIZE);

};


#endif //TASK4_CODE_TESTBED_H
