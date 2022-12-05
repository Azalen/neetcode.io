#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 100000;

/**     https://leetcode.com/problems/product-of-array-except-self/
 * 
 */

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result;

    int fullProd = 1;
    int fullProdWithoutZeros = 1;

    bool moreThanOneZero = false;
    bool oneZero = false;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 0){
            if(oneZero){
                moreThanOneZero = true;
                break;
            }
            oneZero = true;
        }
    }

    if(moreThanOneZero){
        for(int i = 0; i < nums.size(); i++){
            result.push_back(0);
        }
        return result;
    }

    for(int i = 0; i < nums.size(); i++){
        fullProd *= nums[i];
        if(nums[i] != 0){
            fullProdWithoutZeros *= nums[i];
        }
    }

    cout << fullProd << " | " << fullProdWithoutZeros << endl;

    
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 0){
            result.push_back(fullProdWithoutZeros);
        }
        else{
            result.push_back(fullProd / nums[i]);
        }
    }
    return result;
}


int main(){

    clock_t start, end;
    double runtime;
    cout << endl;

    vector<int> nums = {1,2,3,4};

    start = clock();
    
    productExceptSelf(nums);

    end = clock();
    runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << setw(16) << "RUNTIME" << ":" << setw(7) << runtime << "ms" << endl << endl;


    return 0;
}