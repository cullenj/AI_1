#include <iostream>
#include <time.h>
#include "DFS.h"
#include "DLS.h"
#include "IDS.h"
#include "npuzzle.h"
#include "nqueens.h"
#include "knuth.h"


using namespace std;

int main()
{
    
    
    //time_t begin;
    //time_t end;
    int *init = new int[9];
    for (int i = 0; i < 9; i++) {
        init[i] = i;
    }
    
    /*
    init[0] = 3; init[3] = 0;
    init[4] = 0; init[3] = 4;
     */
    /*
    npuzzle* start = new npuzzle();
    start->puzzleinit(8,init);

    knuth problem = knuth(3,10,"Start");
    */
    int x=8;
    
    vector<int> vect_test(1,4);
    nqueens eightqueens = nqueens(vect_test,x);

//    npuzzle start;
//    start.puzzleinit(x,init);
    
    eightqueens.print();
    
    cout << "Search Starting\n";
    DLS<nqueens> eightq;
    eightq.search(eightqueens,x);
    
    /*
    
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

    
<<<<<<< Updated upstream:AI_searching/AI_searching/main.cpp
    knuth problem = knuth(3,10,"Start");
    
    DFS<npuzzle> searchthree;
    searchthree.problem(start);
    searchthree.expand();
    
=======
    DLS<knuth> searchthree;
    searchthree.search(problem, 20);
     */
    /*
    IDS<npuzzle> searchfour;
    searchfour.search(*start);
    */
    
    return 0;
};