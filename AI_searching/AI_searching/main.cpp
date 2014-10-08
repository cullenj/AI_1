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
    
    
    time_t begin;
    time_t end;
    
    
    int *init = new int[9];
    for (int i = 0; i < 9; i++) {
        init[i] = i;
    }
    //init[0] = 3; init[3] = 6; init[6] = 7; init[7] = 8; init[8] = 5; init[5] = 0;
    init[0] = 5; init[1] = 1; init[2] = 4; init[3] = 0; init[4] = 8; init[5] = 2; init[6] = 7; init[7] = 3; init[8] = 6;
    npuzzle probone; probone.puzzleinit(8, init);
    
    DFS<npuzzle> srchone;
    DLS<npuzzle> srchtwo;
    IDS<npuzzle> srchthree;
    
    /*
    time(&begin);
    srchone.search(probone);
    time(&end);
    cout << "\n\nRun Time: " << difftime(end,begin) << "\n";
    */
    
    time(&begin);
    srchtwo.search(probone,25);
    time(&end);
    cout << "\n\nRun Time: " << difftime(end,begin) << "\n";
    time(&begin);
    srchthree.search(probone);
    time(&end);
    cout << "\n\nRun Time: " << difftime(end,begin) << "\n";
    
    knuth probtwo;
    probtwo.init(4,5);
    
    DFS<knuth> srchfour;
    DLS<knuth> srchfive;
    IDS<knuth> srchsix;
    
    time(&begin);
    srchfour.search(probtwo);
    time(&end);
    cout << "\n\nRun Time: " << difftime(end,begin) << "\n";
    time(&begin);
    srchfive.search(probtwo,15);
    time(&end);
    cout << "\n\nRun Time: " << difftime(end,begin) << "\n";
    time(&begin);
    srchsix.search(probtwo);
    time(&end);
    cout << "\n\nRun Time: " << difftime(end,begin) << "\n";
    
    nqueens probthree;
    probthree.init(8);
    
    DFS<nqueens> srchseven;
    DLS<nqueens> srcheight;
    IDS<nqueens> srchnine;
    
    time(&begin);
    srchseven.search(probthree);
    time(&end);
    cout << "\n\nRun Time: " << difftime(end,begin) << "\n";
    time(&begin);
    srcheight.search(probthree,8);
    time(&end);
    cout << "\n\nRun Time: " << difftime(end,begin) << "\n";
    time(&begin);
    srchnine.search(probthree);
    time(&end);
    cout << "\n\nRun Time: " << difftime(end,begin) << "\n";
    
    return 0;
};