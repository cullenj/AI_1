#include <iostream>
#include <time.h>
#include "DFS.h"
#include "UCS.h"
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
    
    /*
    init[0] = 3; init[3] = 0;
    init[4] = 0; init[3] = 4;
     */
<<<<<<< Updated upstream:AI_searching/AI_searching/main.cpp
    
    init[0] = 3; init [3] = 4; init[4] = 0;
=======
    init[5] = 4; init [4] = 5;
    
    /*
    npuzzle* start = new npuzzle();
    start->puzzleinit(8,init);

    knuth problem = knuth(3,10,"Start");
    */
    
    vector<int> vect_test(8,2);
    nqueens eightqueens = nqueens(vect_test,8);
>>>>>>> Stashed changes:AI_searching/AI_searching/main 12.33.19 AM.cpp
    
    npuzzle start;
    start.puzzleinit(8,init);
    
<<<<<<< Updated upstream:AI_searching/AI_searching/main.cpp
    /*
=======
    
    eightqueens.print();
    
>>>>>>> Stashed changes:AI_searching/AI_searching/main 12.33.19 AM.cpp
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
    
<<<<<<< Updated upstream:AI_searching/AI_searching/main.cpp
    knuth problem = knuth(3,10,"Start");
    
    DFS<npuzzle> searchthree;
    searchthree.problem(start);
    searchthree.expand();
    
=======
    DLS<knuth> searchthree;
    searchthree.search(problem, 20);
     */
>>>>>>> Stashed changes:AI_searching/AI_searching/main 12.33.19 AM.cpp
    /*
    IDS<npuzzle> searchfour;
    searchfour.search(*start);
    */
    
    return 0;
};