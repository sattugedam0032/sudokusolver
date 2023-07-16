#include <iostream>
#define X 9 
using namespace std;

int sudoku_problem[X][X] 
   {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
};


bool PresentInBox(int row, int col, int num){
//checking whether num is present in 3x3 box or not
  for(int i=0; i< X; i++){
      if(sudoku_problem[3*(row/3)+i/3][3*(col/3)+i%3] == num){
            return false;       // to check if there is already a entry equal to val in 3*3 submatrices
        }
  }
  return true;
}

bool PresentInCol(int col, int num){ //checking whether num is present in col or not
   for(int i=0; i<X; i++){
        if(sudoku_problem[i][col] == num){
            return false;        // to check if there is already a entry equal to val in row
        }
   }
   return true;
}

bool PresentInRow(int row, int num){ //checking whether num is present in row or not
   for(int i=0; i<X; i++){
       if(sudoku_problem[row][i] == num){    // to check if there is already a entry equal to val in row
            return false;
        }
   }
   return true;
}


void sudokuGrid(){ //To print the sudoku sudoku_problem after solve
   for (int row = 0; row < X; row++){
      for (int col = 0; col < X; col++){
         if(col == 3 || col == 6)
            cout << " | ";
         cout << sudoku_problem[row][col] <<" ";
      }
      if(row == 2 || row == 5){
         cout << endl;
         for(int i = 0; i<X; i++)
            cout << "---";
      }
      cout << endl;
   }
}

bool ValidPlace(int row, int col, int num){
   //when item not found in col, row and current 3x3 box
   return PresentInRow(row, num) && PresentInCol(col, num) && PresentInBox(row,col, num);
}

bool findEmptyPlace(int &row, int &col){ //To know empty location and update row and column
   for (row = 0; row < X; row++)
      for (col = 0; col < X; col++)
         if (sudoku_problem[row][col] == 0) //If 0 then it is empty
            return true;
   return false;
}

bool solveSudoku(){
   int row, col;
   if (!findEmptyPlace(row, col))
      return true; //if  all places are filled then return 1
   for (int num = 1; num <= 9; num++){ // For valid numbers only 1 - 9
      if (ValidPlace(row, col, num)){ //checking validation, if yes, put the number in the grid
         sudoku_problem[row][col] = num;
         if (solveSudoku()) //recursively go for other rooms in the sudoku_problem
            return true;
         sudoku_problem[row][col] = 0; //turning to unassigned space when conditions are not satisfied
      }
   }
   return false;
}
int main(){
   if (solveSudoku() == true)
      sudokuGrid();
   else
      cout << "No solution exists";
}
