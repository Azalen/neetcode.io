#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 100000;

/**     https://leetcode.com/problems/two-sum/
 * 
 *      APPROACHES:
 *          (1) SORTING         time: O(n*logn)     space: O(1)
 *          (2) HASH MAP        time: O(n)          space: O(n)
 * 
 * */



int main(){

    clock_t start, end;
    double runtime;
    cout << endl;


    start = clock();
    

    end = clock();
    runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << setw(16) << "SORTING" << ":" << setw(7) << runtime << "ms" << endl << endl;


    return 0;
}