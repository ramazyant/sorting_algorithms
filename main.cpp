#include <vector>
#include <list>
#include "generator.h"

#include "insertion.h"
#include "merge.h"
#include "quick.h"
#include "counting.h"
#include "radix.h"

#include <iostream>
#include <ctime>
#include "CSVwriter.h"

template <typename T>
void printArray(std::vector<T> arr) {
    for (long i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

const int NUM_ALG_APPL = 4;

int main() {
    long n;
    std::cin >> n;
    std::vector<double> I_time, M_time, Q_time, C_time, R_time;
    /*      the following encoding of sorting alg's is used:
     0 - insertion
     1 - merge
     2 - quick
     3 - counting
     4 - radix
     the vectors contain the timings
     sry I got no mood nor time to do it in a smart way as the sorting algs
     */
    //
    std::vector<int> int_vect;
    std::vector<std::string> str_vect;
    std::list<int> int_list;
    std::list<std::string> str_list;
    //
    clock_t myClock;
    double temp;
    for (int i = 1; i <= n; i += 100) {          // make the step +1000 ???
        //
        //      insertion:
        temp = 0;
        for (int j = 0; j < NUM_ALG_APPL; ++j) {
            intVectGen(int_vect, i);
            strVectGen(str_vect, i);
            intListGen(int_list, int_vect);
            strListGen(str_list, str_vect);
            //
            myClock = clock();
            insertion_sort(int_vect.begin(), int_vect.end());
            myClock = clock() - myClock;
            temp += ((double)myClock)/CLOCKS_PER_SEC;
            //
            myClock = clock();
            insertion_sort(str_vect.begin(), str_vect.end());
            myClock = clock() - myClock;
            temp += ((double)myClock)/CLOCKS_PER_SEC;
            //
            myClock = clock();
            insertion_sort(int_list.begin(), int_list.end());
            myClock = clock() - myClock;
            temp += ((double)myClock)/CLOCKS_PER_SEC;
            //
            myClock = clock();
            insertion_sort(str_list.begin(), str_list.end());
            myClock = clock() - myClock;
            temp += ((double)myClock)/CLOCKS_PER_SEC;
            //
            temp *= NUM_ALG_APPL;
        }
        I_time.push_back(temp);
        //
        //      merge:
        //
        temp = 0;
        for (int j = 0; j < NUM_ALG_APPL; ++j) {
            intVectGen(int_vect, i);
            strVectGen(str_vect, i);
            intListGen(int_list, int_vect);
            strListGen(str_list, str_vect);
            //
            myClock = clock();
            merge_sort(int_vect.begin(), int_vect.end());
            myClock = clock() - myClock;
            temp += ((double)myClock)/CLOCKS_PER_SEC;
            //
            myClock = clock();
            merge_sort(str_vect.begin(), str_vect.end());
            myClock = clock() - myClock;
            temp += ((double)myClock)/CLOCKS_PER_SEC;
            //
            myClock = clock();
            merge_sort(int_list.begin(), int_list.end());
            myClock = clock() - myClock;
            temp += ((double)myClock)/CLOCKS_PER_SEC;
            //
            myClock = clock();
            merge_sort(str_list.begin(), str_list.end());
            myClock = clock() - myClock;
            temp += ((double)myClock)/CLOCKS_PER_SEC;
            //
            temp *= NUM_ALG_APPL;
        }
        M_time.push_back(temp);
        //
        //      quick:
        //
        temp = 0;
        for (int j = 0; j < NUM_ALG_APPL; ++j) {
            intVectGen(int_vect, i);
            strVectGen(str_vect, i);
            intListGen(int_list, int_vect);
            strListGen(str_list, str_vect);
            //
            myClock = clock();
            quick_sort(int_vect.begin(), int_vect.end());
            myClock = clock() - myClock;
            temp += ((double)myClock)/CLOCKS_PER_SEC;
            //
            myClock = clock();
            quick_sort(str_vect.begin(), str_vect.end());
            myClock = clock() - myClock;
            temp += ((double)myClock)/CLOCKS_PER_SEC;
            //
            myClock = clock();
            quick_sort(int_list.begin(), int_list.end());
            myClock = clock() - myClock;
            temp += ((double)myClock)/CLOCKS_PER_SEC;
            //
            myClock = clock();
            quick_sort(str_list.begin(), str_list.end());
            myClock = clock() - myClock;
            temp += ((double)myClock)/CLOCKS_PER_SEC;
            //
            temp *= NUM_ALG_APPL;
        }
        Q_time.push_back(temp);
        //
        //      counting:
        //
        temp = 0;
        binVectGen(int_vect, i);
        myClock = clock();
        counting_sort(int_vect);
        myClock = clock() - myClock;
        C_time.push_back(((double)myClock)/CLOCKS_PER_SEC);
        //
        //      radix:
        //
        temp = 0;
        binVectGen(int_vect, i);
        myClock = clock();
        radix_sort(int_vect);
        myClock = clock() - myClock;
        temp += ((double)myClock)/CLOCKS_PER_SEC;
        //
        decVectGen(int_vect, i);
        myClock = clock();
        radix_sort(int_vect);
        myClock = clock() - myClock;
        temp += ((double)myClock)/CLOCKS_PER_SEC;
        R_time.push_back(temp);
        //
    }
    //          outputtting:
    CSVwriter output ("out.csv");
    output.algNames.push_back("INSERTION");
    output.algNames.push_back("MERGE");
    output.algNames.push_back("QUICK");
    output.algNames.push_back("COUNTING");
    output.algNames.push_back("RADIX");
    output.addDatainRow(I_time.begin(), I_time.end(), M_time.begin(), Q_time.begin(), C_time.begin(), R_time.begin());
    //
    return 0;
}
