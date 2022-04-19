#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 1000000;

/**     https://leetcode.com/problems/valid-anagram/
 * 
 *      APPROACHES:
 *          (1) SORTING         time: O(n*logn)     space: O(1)
 *          (2) HASH MAP        time: O(n)          space: O(n)
 * 
 * */

bool isAnagramSorting(string & s, string & t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return (s == t);
}

bool isAnagramHashing(const string & s, const string & t) {
    // can only be anagram if same length
    if(s.length() != t.length())
        return false;

    // create hash map for string S    
    unordered_map<char,int> ums;
    for(char c : s){
        if(ums.find(c) == ums.end())
            ums[c] = 1;
        else
            ums[c]++;
    }

    // create hash map for string t
    unordered_map<char,int> umt;
    for(char c : t){
        if(umt.find(c) == umt.end())
            umt[c] = 1;
        else
            umt[c]++;
    }

    // run through hash map an compare values
    // this is valid because we made sure both strings are same length at this point
    for(auto it : ums){
        char c = it.first;
        if(ums[c] != umt[c])
            return false;
    }

    return true;
}

int main(){

    clock_t start, end;
    double runtime;
    cout << endl;

    string s,t;
    for(int i = 0; i < SIZE; i++){
        s += 'A' + (i % 25);
        t += 'A' + (i % 25);
    }

    

    start = clock();
    cout << boolalpha << setw(26) << isAnagramHashing(s,t) << endl;
    end = clock();
    runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << setw(16) << "HASH MAP" << ":" << setw(7) << runtime << "ms" << endl << endl;

    start = clock();
    cout << boolalpha << setw(26) << isAnagramSorting(s,t) << endl;
    end = clock();
    runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << setw(16) << "SORTING" << ":" << setw(7) << runtime << "ms" << endl << endl;

    return 0;
}