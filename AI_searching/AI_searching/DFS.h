//
//  DFS.h
//  AIDFS
//
//  Created by David Kozloff on 10/1/14.
//  Copyright (c) 2014 David. All rights reserved.
//

#ifndef __AIDFS__DFS__
#define __AIDFS__DFS__
#include <stack>
#include <list>
#include <iostream>
#include <vector>
using namespace std;
template <class T>

class DFS {
    
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
    list <Node> explored;
    long size;
    long exploredsize;
    
    public:
        DFS(T& problem) {
            over = false;
            tree.push(Node(problem,problem.branch()));
            tree.top().previous = new Node(T(0),problem.branch());
            //Marker for where to stop when looking back through the list
        }
        
        DFS() {
            over = false;
            
        }
        
        ~DFS()
        {
            while(!tree.empty()) {
                tree.pop();
            }
        }
        
        void problem(T& problem) {
            tree.push(Node(problem,problem.branch()));
            tree.top().previous = new Node(T(0),problem.branch());
        }
        
        int expand() {
            size = tree.size();
            exploredsize = explored.size();
            tree.top().state.print(); //Check State
            
            if (tree.empty()) {
                end(T(0));  //No solution found, and (ideally) all possible branches checked
                return -1;
            }
            
            Node* fringe = &tree.top();
            vector<T> successors;
            successors = fringe->state.successors();
            
            if(fringe->state.goal()) {
                end(fringe->state);  //Check if we are at goal (if so stop
                return 1;
            }
            
            for (int i = 0 ; i < successors.size() ; i++ ) {
                if (fringe->deadends[i] == 0) {
                    if (!duplicate(successors[i])) {
                        tree.push(Node(successors[i],successors[i].branch()));
                        tree.top().previous = fringe;
                        break;
                    } //Take first option that isn't a duplicate.
                }
            }
            
            if (tree.top().state == fringe->state) { //If none of the successors were viable options
                explored.push_back(*fringe);
                tree.pop();
                successors = tree.top().state.successors();
                for (int i = 0 ; i < successors.size() ; i++ ) {
                    if(successors[i] == fringe->state) {
                        tree.top().deadends[i] = 1;
                        break;
                    }
                }
                expand();
            } //This handles if all successors were duplicates. Go up one and mark the last path as a deadend
            return 0;
        }
    
        bool duplicate(T& check) {
            Node itr = tree.top();
            while(itr.state != T(0)) {
                if(itr.state == check)
                    return true;
                itr = *itr.previous;
            }
            for(typename list<Node>::iterator itr = explored.begin(); itr != explored.end(); itr++) {
                if(itr->state == check) {
                    return true;
                }
            }
            return false;
        }
        
        void end(T solution) {
            if (solution == T(0)) {
                cout << "No solution found\n";
            }
            else
                cout << "Solution found\n";
                
            over = true;
        }
    
        bool isOver() {
            return over;
        }
};
#endif /* defined(__AIDFS__DFS__) */
