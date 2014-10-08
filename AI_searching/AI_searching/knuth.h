//
//  Knuth.h
//  AIDFS
//
//  Created by David Kozloff on 10/5/14.
//  Copyright (c) 2014 David. All rights reserved.
//

#ifndef AIDFS_Knuth_h
#define AIDFS_Knuth_h
#include <iostream>
#include <vector>
#include <math.h>
#include <string>


class knuth {
    
public:
    long double start;
    long double end;
    string prevaction;
    string domain = "Knuth ";
 
    knuth() {
        
    }
    
    knuth(long double x,long double y, string s) { //x and y are positive ints
        start = x;
        end = y;
        prevaction = s;
    }
    
    ~knuth() {
        
    }
    
    void init(long double x, long double y) {
        start = x;
        end = y;
        prevaction = "Start ";
    }
    
    vector<knuth> successors() {
        vector<knuth> successors;
        if(!(start < 2 && end > 2)) {
            successors.push_back(knuth(floor(start),end,"floor("));
            if(start > end)
                successors.push_back(knuth(sqrt(start),end,"sqrt("));
            if(start < pow(10,3) && floor(start) == start && factorial(start) > 0) {
                successors.push_back(knuth(factorial(start),end,"factorial("));
            }
        }
        return successors;
    }
    
    long double factorial(long double x) {
        long double factorial = 1;
        for(int i = 0; x - i > 0; i++) {
            factorial = factorial * (x-i);
        }
        return factorial;
    }
    
    int branch() {
        return 3;
    }
    
    bool goal() {
        if (start == end) {
            return true;
        }
        return false;
    }
    
    void print() {
        cout << "At: " << start << " Goal: " << end << "\n" << "Action just taken: " << prevaction << "\n\n";
    }
    
    bool operator==(const knuth& other) {
        return !operator!=(other);
    }

    bool operator!=(const knuth& other) {
        if ( start != other.start || end != other.end || prevaction.compare(other.prevaction) != 0) {
            return true;
        }
        return false;
    }
    
    void solution(list<knuth> path) {
        cout << "Length of Soln. Path: " << path.size() << endl;
        list<knuth>::iterator itr = path.end();
        itr--;
        while(itr != path.begin()) {
            cout << itr->prevaction;
            itr--;
        }
        cout << start;
        for(int i = 0; i < path.size() - 1; i++) {
            cout << ")";
        }
        cout << " = " << end << "\n";
        cout << "Path size: " << path.size() << "\n";
    }
    
    string string() {
        char numstr[21];
        sprintf(numstr,"%Lf %Lf",start,end);
        return numstr;
    }
    
    long hashkey() {
        return (long) (start*pow(10,5));
        
    }
    
};

#endif
