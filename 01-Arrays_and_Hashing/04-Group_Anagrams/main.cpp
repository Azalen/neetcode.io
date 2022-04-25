#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 100000;

/**     https://leetcode.com/problems/group-anagrams/
 * 
 *      APPROACHES:
 *          n = strs.size()
 *          m = max{ strs[i].size() }
 * 
 *          (1) SORTING + HASHING         time: O(n * m*logm)     space: O(n*m)
 *          (2) ADVANCED HASH MAP         time: O(n * m)          space:
 * 
 * */

vector<vector<string>> groupAnagrams(vector<string>& strs) {

    vector<string> strsSorted = strs;
    for(int i = 0; i < strs.size(); i++){
        sort(strsSorted[i].begin(), strsSorted[i].end());
    }
    
    unordered_map<string, int> um;
    vector<vector<string>> res;
    int index = 0;
    for(int i = 0; i < strs.size(); i++){
        // new anagram 
        if(um.find(strsSorted[i]) == um.end()){
            um[strsSorted[i]] = index++;
            res.push_back({strs[i]});
        }
        // old anagram
        else{
            int j = um[strsSorted[i]];
            res[j].push_back(strs[i]);
        }

    }
    return res;

}


int main(){

    clock_t start, end;
    double runtime;
    cout << endl;

    vector<string> strs = {"ana", "naa", "btw", "xix"};

    start = clock();
    
    groupAnagrams(strs);

    end = clock();
    runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << setw(16) << "SORTING" << ":" << setw(7) << runtime << "ms" << endl << endl;


    return 0;
}