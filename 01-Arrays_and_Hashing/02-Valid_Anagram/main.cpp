#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 100000;

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
    if(s.length() != t.length())
        return false;
    
}

int main(){

    clock_t start, end;
    double runtime;
    cout << endl;

    string s,t;
    for(int i = 0; i < SIZE; i++){
        s += 'A' + (i % 25);
        t += 'B' + (i % 25);
    }

    start = clock();
    cout << boolalpha << setw(26) << isAnagramSorting(s,t) << endl;
    end = clock();
    runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << setw(16) << "SORTING" << ":" << setw(7) << runtime << "ms" << endl << endl;

    // start = clock();
    // cout << boolalpha << setw(26) << isAnagramSorting(s,t) << endl;
    // end = clock();
    // runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    // cout << setw(16) << "HASH TABLE" << ":" << setw(7) << runtime << "ms" << endl << endl;

    return 0;
}