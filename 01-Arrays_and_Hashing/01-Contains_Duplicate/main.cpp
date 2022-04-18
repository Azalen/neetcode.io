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

/**     https://leetcode.com/problems/contains-duplicate/
 * 
 *      APPROACHES: 
 *          (1) BRUTE FORCE     time: O(n²)         space: O(1)
 *          (2) SORTING         time: O(n*logn)     space: O(1)
 *          (3) HASH TABLE      time: O(n)          space: O(n)
 * */

bool containsDuplicatesBruteForce(const vector<int> & nums){

    for(int i = 0; i < nums.size(); i++){
        for(int j = i+1; j < nums.size(); j++){
            if(nums[i] == nums[j])
                return true;
        }
    }
    return false;
}

bool containsDuplicatesSorting(vector<int> & nums){

    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size()-1; i++){
        // because in an ordered vector duplicates need to be next to each other
        if(nums[i] == nums[i+1])
            return true;
    }
    return false;
}

bool containsDuplicatesHashing(const vector<int> & nums){

    unordered_set<int> us;
    for(int i = 0; i < nums.size(); i++){
        if(us.find(nums[i]) != us.end())
            return true;
        us.insert(nums[i]);
    }
    return false;
}

int main(){

    // WORST CASE FOR BRUTE FORCE (duplicates at the exact end)
    vector<int> bruteForceNums;
    for(int i = SIZE; i > 0; i--)
        bruteForceNums.push_back(i);
    bruteForceNums.push_back(1);

    vector<int> sortingNums;
    for(int i = SIZE; i > 0; i--)
        sortingNums.push_back(i);
    sortingNums.push_back(SIZE);

    clock_t start, end;
    double runtime;
    cout << endl;
    
    start = clock();
    cout << boolalpha << setw(26) << containsDuplicatesBruteForce(bruteForceNums) << endl;
    end = clock();
    runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << setw(16) << "BRUTE FORCE" << ":" << setw(7) << runtime << "ms" << endl << endl;

    start = clock();
    cout << boolalpha << setw(26) << containsDuplicatesSorting(sortingNums) << endl;
    end = clock();
    runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << setw(16) << "SORTING" << ":" << setw(7) << runtime << "ms" << endl << endl;

    start = clock();
    cout << boolalpha << setw(26) << containsDuplicatesHashing(bruteForceNums) << endl;
    end = clock();
    runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << setw(16) << "HASH TABLE" << ":" << setw(7) << runtime << "ms" << endl << endl;

    
    
    return 0;
}