//
//  UCS.h
//  AIDFS
//
//  Created by David Kozloff on 10/4/14.
//  Copyright (c) 2014 David. All rights reserved.
//

#ifndef AIDFS_UCS_h
#define AIDFS_UCS_h

#include <stack>
#include <iostream>
#include <vector>
using namespace std;
template <class T>

class UCS {
    
private:
    struct Node
    {
        Node* previous;
        T state;
        int *deadends;
        Node() {  }
        Node(const T& x,int y) {
            state = x;
            deadends = new int[y];
            for(int i = 0; i < y; i++) {
                deadends[i] = 0;
            }
        }
    };
    
    bool over;
    stack <Node> tree;
    int maxsuccessors;
    long size;
    
public:
    
    UCS() {
        
    }
    
    UCS(T& problem) {
        
    }
    
    ~UCS() {
        
    }
    
    int expand() {
        return 0;
    }
    
};


#endif
