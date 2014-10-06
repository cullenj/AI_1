//
//  DLS.h
//  AIDFS
//
//  Created by David Kozloff on 10/4/14.
//  Copyright (c) 2014 David. All rights reserved.
//

#ifndef AIDFS_DLS_h
#define AIDFS_DLS_h
#include <stack>
#include <iostream>
#include <vector>
#include <list>
using namespace std;
template <class T>


class DLS {
    
private:
    struct Node
    {
        Node* parent;
        T state;
        int *deadends;
        int depth;
        Node() {  }
        Node(const T& x) {
            state = x;
            depth = 0;
        }
    };
    
    Node solution;
    bool over;
    long size;
    list <Node> explored;
    int depthlimit;
    
    
public:
    
    DLS() {
        over = false;
        depthlimit = 0;
        size = 0;
    }
    
    void search(T& problem,int maxdepth) {
        depthlimit = maxdepth;
        expand(Node(problem));
    }
    
    ~DLS() {
        while(!explored.empty()) {
            explored.pop_back();
        }
    }
    
    int expand(Node leaf) {
        
        
        if(over) {
            return 0;
        } //Solution was found in some other recursive call of expand
        
        leaf.state.print();
        
        size = explored.size();
        Node successor;
        successor.parent = &leaf;
        successor.depth = leaf.depth+1;

        if(leaf.state.goal()) {
            solution = leaf;
            cout << "SOLUTION FOUND\n\n";
            over = true;
            //printsolution();
            return 1;
        } //Goal is found
        
        if(successor.depth > depthlimit) {
            return 0;
        } //Depth limit reached
        
        explored.push_back(leaf);
        
        vector<T> successors = leaf.state.successors();
        for(int i = 0; i < successors.size(); i++) {
            if(!duplicate(successors[i])) { //Expand all non duplicate successors
                successor.state = successors[i];
                expand(successor);
            }
        }
        return 0;
    }
    
    bool duplicate(T& successor) {
        for(typename list<Node>::iterator itr = explored.begin(); itr != explored.end(); itr++) {
            if(itr->state == successor) {
                return true;
            }
        }
        return false;
    }
    
/*    void printsolution() {
        list<T> solutionpath;
        while(solution.state != explored.begin()->state) {
            solutionpath.push_front(solution.state);
            solution = *solution.parent;
        }
        solution.state.solution(solutionpath);
    }
*/
};

#endif
