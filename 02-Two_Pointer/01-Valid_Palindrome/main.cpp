#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 1000000;

/**     https://leetcode.com/problems/two-sum/
 * 
 *      APPROACHES:
 *          (1) RUNNING FROM TWO SIDES         time: O(n)     space: O(1)
 * 
 * */

bool isPalindrome(string s) {

    // EDGE CASE
    if (s.length() < 2)
        return true;

    int i = 0;
    int j = s.length() - 1;

    while (i < j)
    {

        // check if current s[i] is alphanumeric
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
        }
        else
        {
            i++;
            // next run into big while loop
            continue;
        }

        // check if current s[j] is alphanumeric
        if ((s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9'))
        {
        }
        else
        {
            j--;
            // next run into big while loop
            continue;
        }

        // Transform to lower case
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] -= 32;
        if (s[j] >= 'a' && s[j] <= 'z')
            s[j] -= 32;

        if (s[i] != s[j])
            return false;

        i++;
        j--;
    }
    return true;
}

int main(){

    clock_t start, end;
    double runtime;
    cout << endl;

    string s;
    for(int i = 0; i < SIZE; i++){
        s += "AB";
    }
    s += "A";

    start = clock();
    
    cout << boolalpha << setw(26) << isPalindrome(s) << endl;

    end = clock();
    runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << setw(16) << "SORTING" << ":" << setw(7) << runtime << "ms" << endl << endl;


    return 0;
}


