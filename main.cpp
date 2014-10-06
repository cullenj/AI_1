#include <iostream>
#include <time.h>
#include "DFS.h"
#include "UCS.h"
#include "DLS.h"
#include "IDS.h"
#include "npuzzle.h"

using namespace std;

int main()
{
    time_t begin;
    time_t end;
    int *init = new int[9];
    for (int i = 0; i < 9; i++) {
        init[i] = i;
    }
    //init[0] = 3; init[3] = 0;
    init[4] = 0; init[3] = 4;
    
    npuzzle* start = new npuzzle();
    start->puzzleinit(8,init);
    
    
    /*DFS<npuzzle> search;
    search.problem(*start);
    */
    
    IDS<npuzzle> search3;
//    DLS<npuzzle> search_tree;
    cout << "Search Starting\n";
    
    time(&begin);
    
    search3.search(*start,10);
    
    
    /*
    while (!search.isOver()) {
        search.expand();
        cout<< "Searching..\n";
    }
    */
    
    /*DLS<npuzzle> searchtwo;
    searchtwo.search(*start, 2);
    */
    time(&end);
    cout << "Run Time: " << difftime(end,begin);
    
    return 0;
};