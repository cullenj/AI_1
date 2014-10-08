#include <iostream>
#include <time.h>
#include "DFS.h"
#include "UCS.h"
#include "DLS.h"
#include "IDS.h"
#include "npuzzle.h"
#include "knuth.h"


using namespace std;

int main()
{
    
    
    time_t begin;
    time_t end;
    int *init = new int[9];
    for (int i = 0; i < 9; i++) {
        init[i] = i;
    }
    
    /*
    init[0] = 3; init[3] = 0;
    init[4] = 0; init[3] = 4;
     */
    
    init[0] = 3; init [3] = 4; init[4] = 0;
    
    npuzzle start;
    start.puzzleinit(8,init);
    
    /*
    time(&begin);
    
    
    DFS<npuzzle> search;
    search.problem(start);
    cout << "Search Starting\n";
    
    
    
    
   search.expand();
     
    */
    
    /*
    DLS<npuzzle> searchtwo;
    searchtwo.search(*start, 2);
    
    
    time(&end);
    cout << "Run Time: " << difftime(end,begin);
    */
    
    knuth problem = knuth(3,10,"Start");
    
    DFS<npuzzle> searchthree;
    searchthree.problem(start);
    searchthree.expand();
    
    /*
    IDS<npuzzle> searchfour;
    searchfour.search(*start);
    */
    
    return 0;
};