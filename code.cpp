#include <iostream>
#define X 9
using namespace std;
int sudoku[X][X]; // {
//    {4, 0, 2, 4, 0, 9, 2, 5, 0},
//    {7, 2, 0, 0, 0, 0, 0, 0, 0},
//    {0, 8, 7, 0, 0, 0, 0, 3, 1},
//    {0, 0, 3, 0, 1, 0, 5, 8, 0},
//    {9, 0, 0, 4, 6, 3, 0, 0, 5},
//    {0, 5, 0, 0, 9, 2, 6, 0, 0},
//    {1, 3, 0, 0, 0, 0, 2, 5, 0},
//    {0, 0, 0, 0, 0, 0, 0, 7, 4},
//    {0, 0, 5, 2, 0, 6, 3, 0, 0}
// };
   for(int i=0;i<9;i++){
      for(int j=0;j<9;j++){
         cin>>sudoku[i][j];
      }
   }

void print_sudoku(){                                //To print the sudoku grid after solve
   for (int row = 0; row < 9; row++){
      for (int col = 0; col < 9; col++){
         if(col == 3 || col == 6)
            cout << " | ";
         cout << sudoku[row][col] <<" ";
      }
      if(row == 2 || row == 5){
         cout << endl;
         for(int i = 0; i<X; i++)
            cout << "---";
      }
      cout << endl;
   }
}


bool isSafe(int row, int col, vector<vector<char> > &A, char val){
    //char t = to_string(val);
    
    for(int i=0; i<9; i++){
        if(A[i][col] == val){
            return false;        // to check if there is already a entry equal to val in row
        }
        if(A[row][i] == val){.    // to check if there is already a entry equal to val in row
            return false;
        }
        if(A[3*(row/3)+i/3][3*(col/3)+i%3] == val){
            return false;       // to check if there is already a entry equal to val in 3*3 submatrices
        }
    }
    return true;
}

bool solve(vector<vector<char> > &A){
    
    for(int i=0; i< 9; i++){         // this is to traverse through matrix
        for(int j=0; j<9; j++){
            
            if(A[i][j]=='.'){        // any empty space found
                for(char val ='1'; val<='9'; val++){
                                                       // checking for each number from 1 to 9 
                    if(isSafe(i,j,A,val)){
                        A[i][j] = val;
                        bool nextcheck = solve(A);     // recurssive call 
                        
                        if(nextcheck){          // after recurssive call checking if solution exist or not
                            return true;
                        }else{
                            A[i][j] = '.';
                            // backtrack
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}


void solveSudoku(vector<vector<char> > &A) {
     solve (A);
}

int main(){
  if(solveSudoku() == true){
print_sudoku();
  }
else{
  cout << "No Solution exists!"
}
