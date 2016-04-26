/* 
* $Id: malib2.cpp 9 2007-07-11 08:22:53Z Makhtar $
* Implementation of c++ utility functions 
*/

#include "malib.h"
#include <string>
#include <algorithm>

// use the following to speed up iostream
// ios_base::sync_with_stdio(false);

//template<typename T>
std::ostream& operator<<(std::ostream& ostr, const std::list<std::string>& list)
{
    for (auto &i : list) {
        ostr << " " << i;
    }
    ostr << "\n";
    return ostr;
}

// Maximum sum of subsets of an array/vector
int maxSum(vvi& v) {
    int n = v.size();
    
    // lowest possible value
    int maxSubRect = -127 * n * v[0].size();
    
    for (int l = 0; l < n; l++) 
        for (int r = l; r < n; r++) {
            int subRect = 0;
            
            for (int row = 0; row < n; row++) {
                // Max 1D Range Sum on columns of this row i
                if (l > 0) 
                    subRect += v[row][r] - v[row][l - 1];
                else
                    subRect += v[row][r];
                // Kadane’s algorithm on rows
                if (subRect < 0) 
                    subRect = 0;
                
                // greedy, restart if running sum < 0
                maxSubRect = std::max(maxSubRect, subRect);
            }             
        }
        return maxSubRect;
}


/* Get the execee's name and arguments then fork it */
int spawn(const char* cmd[] )
{
    std::string command(cmd[0]);
    
    for (int i = 1; cmd[i] != NULL; ++i) {
        command.append(" -");
        command.append(cmd[i]);
    }
    
    FILE* process;
    if ( (process = popen(command.c_str(), "w")) != NULL) {
        pclose(process);
        return EXIT_SUCCESS;
    }
    
    perror(cmd[0]);
    return EXIT_FAILURE;
}
