#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 20000;

/**     https://leetcode.com/problems/two-sum/
 * 
 *      APPROACHES:
 *          (1) BRUTE FORCE     time: O(n²)         space: O(1)
 *          (2) HASH MAP        time: O(n)          space: O(n)
 * 
 * */



int main(){

    clock_t start, end;
    double runtime;
    cout << endl;

    vector<int> nums;
    vector<int> res;
    for(int i = 0; i < SIZE; i++){
        nums.push_back(i+1);
    }
    nums.push_back(SIZE+1);
    int target = 2*SIZE;

    // BRUTE FORCE
    start = clock();
    
    for(int i = 0; i < nums.size(); i++){
        for(int j = 0; j < nums.size(); j++){
            if(nums[i]+nums[j] == target){
                res.push_back(i);
                res.push_back(j);
                break;
            }
        }
    }

    end = clock();
    runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << setw(16) << "BRUTE FORCE" << ":" << setw(7) << runtime << "ms" << endl;
    cout << setw(16) << "RESULT" << ":" << setw(7) << res[0] << "/" << res[1] << endl << endl;

    // HASH MAP
    res.clear();
    start = clock();
    
    unordered_map<int, int> um;
    for(int i = 0; i < nums.size(); i++){
        int diff = target - nums[i];
        if(um.find(diff) == um.end()){
            um[nums[i]] = i;
            // um.emplace(nums[i], i)
        }
        else{
            res.push_back(um[diff]);
            res.push_back(i);
            break;
        }
    }

    end = clock();
    runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << setw(16) << "HASH MAP" << ":" << setw(7) << runtime << "ms" << endl;
    cout << setw(16) << "RESULT" << ":" << setw(7) << res[0] << "/" << res[1] << endl << endl;


    return 0;
}