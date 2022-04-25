#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <bitset>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 1000000;

/**     https://leetcode.com/problems/two-sum/
 * 
 *      APPROACHES:
 *          (1) XOR         time: O(n)     space: O(1)
 * 
 * */

int singleNumber(vector<int>& nums){
    int init = nums[0];
    for(int i = 1; i < nums.size(); i++){
        init = init ^ nums[i];
    }
    return init;
}

int main(){

    clock_t start, end;
    double runtime;
    cout << endl;

    vector<int> v;
    for(int i = 0; i < SIZE; i++){
        v.push_back(i+1);
        v.push_back(SIZE-i);
    }
    v.erase(v.begin()+SIZE);

    start = clock();
    
    cout << setw(26) << singleNumber(v) << endl;
    
    end = clock();
    runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << setw(16) << "SORTING" << ":" << setw(7) << runtime << "ms" << endl << endl;


    return 0;
}