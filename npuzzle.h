//
//  8puzzle.h
//  AIDFS
//
//  Created by David Kozloff on 10/1/14.
//  Copyright (c) 2014 David. All rights reserved.
//

#ifndef __AIDFS___puzzle__
#define __AIDFS___puzzle__

#include <iostream>
#include <math.h>
#include <vector>
#include <string>

using namespace std;

class npuzzle {
private:
    int dimension;
    int n;
    int* puzzle;
    int zero;
    string prevaction;
    
public:
    npuzzle() {
        dimension = 0;
        n=0;
        zero = 0;
        prevaction="Start ";
    }
    
    npuzzle(int x,int* y, string s, int z) {
        puzzleinit(x,y);
        prevaction = s;
        zero = z;
    }
    
    bool operator==(const npuzzle& other) {
        for (int i = 0; i < n+1; i++) {
                if(other.puzzle[i] != puzzle[i]) {
                    return false;
                }
        }
        return true;
    }
    
    bool operator!=(const npuzzle& other) {
        return !(operator==(other));
    }
    
    void puzzleinit(int y,int* x) {
        n=y;
        for(int i = 0; i < n + 1; i++) {
            if(x[i] == 0)
                zero = i;
        }
        dimension = sqrt(n+1);
        puzzle = x;
    }
    
    void print() {
        for(int i = 0; i < n+1; i++) {
            cout << puzzle[i] << " ";
            if ((i+1)%dimension == 0) {
                cout << "\n";
            }
        }
        cout << "\n";
    }
        
    bool goal() {
        for(int i = 0; i < n+1; i++) {
            if(puzzle[i] != i)
                return false;
        }
        return true;
    }
    
    int* left(int* y) {
        int* x = copyarray(puzzle);
        x[zero] = x[zero-1];
        x[zero-1] = 0;
        return x;
    }
    
    int* right(int* y) {
        int* x = copyarray(puzzle);
        x[zero] = x[zero+1];
        x[zero+1] = 0;
        return x;
    }
    
    int* up(int* y) {
        int* x = copyarray(puzzle);
        x[zero] = x[zero-dimension];
        x[zero-dimension] = 0;
        return x;
    }
    
    int* down(int* y) {
        int* x = copyarray(puzzle);
        x[zero] = x[zero+dimension];
        x[zero+dimension] = 0;
        return x;
    }
    
    int* copyarray(int* y) {
        int* x; x = new int[n+1];
        for(int i = 0; i < n+1; i++) {
                x[i] = y[i];
        }
        return x;
    }
    
    vector<npuzzle> successors() {
        vector<npuzzle> successors;
        if(zero%dimension!= 0 && prevaction.compare("Right ") != 0) {
            successors.push_back(npuzzle(n,left(puzzle),"Left ",zero-1));
        }
        if(zero>dimension-1 && prevaction.compare("Down ") != 0) {
            successors.push_back(npuzzle(n,up(puzzle),"Up ",zero-dimension));
        }
        if(zero<n+1-dimension && prevaction.compare("Up ") != 0) {
            successors.push_back(npuzzle(n,down(puzzle),"Down ",zero+dimension));
        }
        if((zero+1)%dimension!=0 && prevaction.compare("Left ") != 0) {
            successors.push_back(npuzzle(n,right(puzzle),"Right ",zero+1));
        }
        return successors;
    }
    
    int getzero() {
        return zero;
    }
    
    void changeprevaction(npuzzle previous) {
        if(previous.getzero() == zero+1) {
            prevaction = "Left ";
        }
        else if(previous.getzero() == zero+dimension) {
            prevaction = "Up ";
        }
        else if(previous.getzero() == zero-dimension) {
            prevaction = "Down ";
        }
        else if(previous.getzero() == zero-1) {
            prevaction = "Right ";
        }
    }
    
    int branch() {
        return 4;
    }
    
    void solution(list<npuzzle> path) {
        list<npuzzle>::iterator itr = path.begin();
        cout << "Start\n";
        print();
        while(itr != path.end()) {
            cout << itr->prevaction << " ";
            itr++;
        }
        cout << "\nTo get \n";
        itr->print();
    }
    
};


#endif /* defined(__AIDFS___puzzle__) */
