//
//  nqueens.h
//  AI_searching
//
//  Created by Joe Cullen on 10/5/14.
//  Copyright (c) 2014 Joseph Cullen. All rights reserved.
//

#ifndef AI_searching_nqueens_h
#define AI_searching_nqueens_h

#include <iostream>
#include <math.h>
#include <vector>
#include <list>

using namespace std;

class nqueens{

private:
    vector<int> board;
    int n;
    
public:
    
    nqueens(){
        n=0;
    }
    
    nqueens(int x){
        n=x;
        vector<int> board(x,-1);
    }
    
    nqueens(vector<int> x,int y){
        board=x;
        n=y;
    }
    
    bool operator==(const nqueens& other) {
        for (int i = 0; i < other.board.size(); i++) {
            if(other.board[i] != board[i]) {
                return false;
            }
        }
        return true;
    }
    
    bool operator!=(const nqueens& other) {
        return !(operator==(other));
    }
    
    bool goal(){
        if(board.size()==n){
            return true;
        } else{
            return false;
        }
    }
    
    list<int> get_queen_pos(){
        list<int> positions;
        for (int queen_pos=0; queen_pos < n; queen_pos++){
            for (int k=0; k<board.size();k++){
                if (queen_pos == board[k]) break; //same row?
                if ((board[k]-k)==(queen_pos-board.size()+1)) break; //down diagonal?
                if ((board[k]+k)==(queen_pos+board.size()+1)) break; //up diagonal?
                positions.push_back(queen_pos); //postion does not attack other "k" queens so add to list
            }
        }
        return positions;
    }
    
    vector<int> new_board(int queen_pos){
        vector<int> board_update;
        board_update=board;
        board_update.push_back(queen_pos);
        return board_update;
    }
    
    vector<nqueens> successors() {
        vector<nqueens> successors;
        
        list<int> positions = get_queen_pos();
        
        for (list<int>::iterator itr = positions.begin(); itr !=positions.end() ;itr++)
            successors.push_back(nqueens(new_board(*itr),n+1));
        
        return successors;
    }
    
    
    void print(){
        cout << "The board vector is " << board.size() << endl;
        cout << "The board size is " << n << endl;
        for(int i=0; i<board.size();i++) {
            cout << board[i] << " ";
        }
    }
    
   /* void print_sol(){
        for(int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                    if (j==board[i]){
                        cout << "X ";
                    } else {
                        cout << "0 ";
                    }
            }
                cout << endl;
        }
    }
    */
    
};


#endif
