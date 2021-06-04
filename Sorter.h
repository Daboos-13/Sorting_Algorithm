//
//

#ifndef TASK4_CODE_SORTER_H
#define TASK4_CODE_SORTER_H


class Sorter {
private:
int *dataArr;




public:
    Sorter();

    virtual void sort(int *arr, int size)=0;



};


#endif //TASK4_CODE_SORTER_H
