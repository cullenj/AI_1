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
#include <unordered_map>
using namespace std;
template <class T>

class DFS {
    
    private:
    
    struct Node
    {
        Node* previous;
        T state;
        Node() {  }
        Node(const T& x) {
            state = x;
            }
        
    };
    
    Node start;
    long nodeslookedat;
    bool over;
    stack <Node> tree;
    unordered_map <long,int> explored; //Unique string expression for every possible state,
                                         //Set to 1 if visited and 0 if not
    long size;
    
    public:
        DFS(T& problem) {
            over = false;
            tree.push(Node(problem));
            nodeslookedat = 0;
        }
        
        DFS() {
            over = false;
            nodeslookedat = 0;
        }
        
        ~DFS()
        {
            while(!tree.empty()) {
                tree.pop();
            }
        }
        
        void search(T& problem) {
            cout << "\nDepth first search on domain " << problem.domain << "\n";
            tree.push(Node(problem));
            start = tree.top();
            expand();
        }
        
        int expand() {
            
            if (over) {
                return 0;
            }
            
            if (tree.empty()) {
                over = true;
                cout << "No solution found";
                cout << "Number of nodes expanded: " << nodeslookedat << "\n\n";
                return -1;
            }
            
            size = tree.size();
            Node* fringe = &tree.top();
            fringe->state.print(); //Check State

            
            vector<T> successors;
            successors = fringe->state.successors();
            
            if(fringe->state.goal()) {
                over = true;
                printsolution();
                return 1;
            }
            
            for (int i = 0 ; i < successors.size() ; i++ ) {
                if (!duplicate(successors[i])) {
                    nodeslookedat++;
                    tree.push(Node(successors[i]));
                    explored[successors[i].hashkey()] = 1;
                    tree.top().previous = fringe;
                    expand();
                    } //Take first option that isn't a duplicate.
                
            }
            
            if(over) {
                return 0;
            }
            
            explored[tree.top().state.hashkey()] = 0;
            tree.pop();
            
            return 0;
        }
    
        bool duplicate(T& check) {
            if (explored[check.hashkey()] == 0) {
                return false;
            }
            return true;
        }
    
        /*bool duplicate(T& check) {
            Node itr = tree.top();
            while(itr.state != start.state) {
                if (check == itr.state)
                    return true;
                itr = *itr.previous;
            }
            return false;
        }*/
    
        void printsolution() {
            cout << "Solution Found!\n";
            cout << "Number of nodes expanded: " << nodeslookedat << "\n\n";
            list<T> path;
            Node* itr = &tree.top();
            while (tree.size() > 1) {
                path.push_front(itr->state);
                itr = itr->previous;
                while(tree.top().state != itr->state) {
                    tree.pop();
                }
            }
            path.push_front(tree.top().state);
            tree.top().state.solution(path);
        }
    
        bool isOver() {
            return over;
        }
};
#endif /* defined(__AIDFS__DFS__) */
