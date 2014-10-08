#include <iostream>
#include <time.h>
#include "DFShash.h"
#include "DLS.h"
#include "IDS.h"
#include "npuzzle.h"
#include "nqueens.h"
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
    
    time(&begin);
    
    /*
    init[0] = 3; init[3] = 0;
    init[4] = 0; init[3] = 4;
     */
    init[0] = 2; init [2] = 0;
    
    int* testone = new int[9];
    testone[0] = 8; testone[1] = 3; testone[2] = 5; testone[3] = 4; testone[4] = 1; testone[5] = 6; testone[6] = 2; testone[7]=7; testone[8]=0;
    /*
    npuzzle* start = new npuzzle();
    start->puzzleinit(8,init);

    knuth problem = knuth(3,10,"Start");
    */
    
    vector<int> vect_test(8,2);
    nqueens eightqueens = nqueens(vect_test,8);
    
    npuzzle start;
    start.puzzleinit(8,testone);
    /*
    
    eightqueens.print();
    
    
    DFS<npuzzle> search;
    search.problem(start);
    cout << "Search Starting\n";
    
    
    
    
   search.expand();
     
    */
    
    /*
    DLS<npuzzle> searchtwo;
    searchtwo.search(*start, 2);
    */
    
    knuth problem = knuth(3,10,"Start");
    
    DFShash<npuzzle> searchthree;
    searchthree.problem(start);
    searchthree.expand();
    
    /*
    IDS<npuzzle> searchfour;
    searchfour.search(*start);
    */
    
    time(&end);
    cout << "\n\nRun Time: " << difftime(end,begin);
    
    return 0;
};