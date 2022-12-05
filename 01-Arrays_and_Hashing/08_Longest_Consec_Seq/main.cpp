#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 100000;

/**     https://leetcode.com/problems/longest-consecutive-sequence/
 * 
 */

int longestConsecutiveSequence(vector<int>& nums) {
    // build hash set in O(n)
        unordered_set<int> us;
        for(int i = 0; i < nums.size(); i++){
            us.insert(nums[i]);
        }
        
        int maxLen = 0;
        // run until set is empty and all elements have been checked
        while(!us.empty()){
            int cur = *us.begin();
            int len = 1;
            us.erase(cur);

            // run forward
            int forward = cur;
            while(us.find(++forward) != us.end()){
                len++;
                us.erase(forward);
            }

            // run backwards
            int backward = cur;
            while(us.find(--backward) != us.end()){
                len++;
                us.erase(backward);
            }
            
            if(maxLen < len)
                maxLen = len;
        }
        
        return maxLen;
}


int main(){

    clock_t start, end;
    double runtime;
    cout << endl;

    vector<int> nums = {1,2,3,4};

    start = clock();
    
    longestConsecutiveSequence(nums);

    end = clock();
    runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << setw(16) << "RUNTIME" << ":" << setw(7) << runtime << "ms" << endl << endl;


    return 0;
}