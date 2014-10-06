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
    init[5] = 4; init [4] = 5;
    
    
    npuzzle* start = new npuzzle();
    start->puzzleinit(8,init);
    
    knuth problem = knuth(3,10,"Start");
    
    
    time(&begin);
    
    /*
    DFS<npuzzle> search;
    search.problem(*start);
    cout << "Search Starting\n";
    
    
    
    
    while (!search.isOver()) {
        search.expand();
        cout<< "Searching..\n";
    }
     
    
    */
    /*
    DLS<npuzzle> searchtwo;
    searchtwo.search(*start, 2);
    
    
    time(&end);
    cout << "Run Time: " << difftime(end,begin);
    
    DLS<knuth> searchthree;
    searchthree.search(problem, 20);
     */
    
    IDS<npuzzle> searchfour;
    searchfour.search(*start);
    
    
    return 0;
};