//
//  IDS.h
//  AIDFS
//
//  Created by Joe Cullen on 10/5/14.
//  Copyright (c) 2014 David. All rights reserved.
//

#ifndef AIDFS_IDS_h
#define AIDFS_IDS_h
#include <stack>
#include <iostream>
#include <vector>
#include <list>
#include "DLS.h"
using namespace std;
template <class T>


class IDS {
        
public:
    
    DLS<T> DLS_search;
    
    IDS(){
    }
    
    void search(T problem){
        
        int i = 0;
        while(true) {
            cout << "Iteration = " << i << "\n";
            DLS_search.~DLS();
            DLS_search.search(problem,i);
            if(DLS_search.over) 
                break;
            i++;
        }
    }
    
    
};


#endif
