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
    long start;
    long end;
    string prevaction;
 
    knuth() {
        
    }
    
    knuth(long x,long y, string s) { //x and y are positive ints
        start = x;
        end = y;
        prevaction = s;
    }
    
    ~knuth() {
        
    }
    
    vector<knuth> successors() {
        vector<knuth> successors;
        successors.push_back(knuth(sqrt(start),end,"sqrt("));
        if(factorial(start) > 0) {
            successors.push_back(knuth(factorial(start),end,"factorial("));
        }
        successors.push_back(knuth(floor(start),end,"floor("));
        return successors;
    }
    
    long factorial(long x) {
        long factorial = 1;
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
        sprintf(numstr,"%ld %ld",start,end);
        return numstr;
    }
    
};

#endif
