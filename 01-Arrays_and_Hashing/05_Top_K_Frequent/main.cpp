#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 100000;

/**     https://leetcode.com/problems/top-k-frequent-elements/
 * 
 */

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> result;
    
    // (1) build hash map and vector-value as key and number of occurences as value in O(n)
    unordered_map<int, int> um;
    for(int i = 0; i < nums.size(); i++){
        if(um[nums[i]]){
            um[nums[i]]++;
        }
        else{
            um[nums[i]] = 1;
        }
    }

    // (2) transform back to vector of key-value-pairs in O(n)
    vector<pair<int, int>> elems(um.begin(), um.end());

    // (3) sort this vector with heap sort in O(n log n)
    sort(elems.begin(), elems.end(), [](auto &left, auto &right) {
        return left.second > right.second;
    });

    // (4) push first k < n elements into result in O(n)
    for(int i = 0; i < k; i++){
        result.push_back(elems[i].first);
    }

    // total runtime 3*O(n) + O(n log n) = O(n log n)
    return result;
}


int main(){

    clock_t start, end;
    double runtime;
    cout << endl;

    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;

    start = clock();
    
    topKFrequent(nums, k);

    end = clock();
    runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << setw(16) << "RUNTIME" << ":" << setw(7) << runtime << "ms" << endl << endl;


    return 0;
}