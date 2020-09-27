// Given a 8x8 chess board. Give an algorithm to print the arrangements 8 queens in such a way that
// no two queens shares the same row,column and diagonals

#include<iostream>
#include<vector>
#include<cstdlib>
#define BOARD_SIZE 8

using namespace std;

typedef vector<vector<int> > Matrix;

void Print(Matrix board){
    for(int i=0;i<BOARD_SIZE;i++){
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\n";
}

void ModifyBoard(Matrix board, const vector<int> &columns){
    for(int row=0;row<columns.size();row++){
        board[row][columns[row]] =1;
    }
    Print(board);
}
bool CheckValid(int row1, int col1, const vector<int> &columns){
    for(int row2=0;row2<row1;row2++){
        int col2 = columns[row2];
        //If in the same column
        if(col1 == col2){
            return false;
        }   
        //Checking diagonals
        int colDiff = abs(col1-col2);
        int rowDiff = row1-row2; 
        if(rowDiff==colDiff){
            return false;
        }
    }
    return true;
}

void PlaceQueens(Matrix board, int row, vector<int> &columns){
    if(row==BOARD_SIZE){
        ModifyBoard(board,columns);
        return;
    }

    //Loop through all the columns
    for(int col=0;col<BOARD_SIZE;col++){
        if(CheckValid(row,col,columns)){
            columns[row]=col;
            PlaceQueens(board,row+1,columns);
        } 
    }
}


int main(){
    Matrix board(BOARD_SIZE, vector<int>(BOARD_SIZE,0));
    vector<int> columns(BOARD_SIZE,0);
    PlaceQueens(board,0,columns);
    return 0;
}