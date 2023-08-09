#include <iostream>
using namespace std;

int main(){

  int q[8][8] = {};// Initialize the board to 0
  int r = 0, c = 0;// Start in the 1st row, 1st column
  q[r][c] = 1; // Place the first queen on the upper left corner

nextCol:
  // Move to the next column
  c++;
  // If you passed the last column
      //goto print
  if (c == 8) goto print;
  r = -1;

nextRow:
  // testing rows
  r++;
  if (r == 8) goto backtrack;
  // row test:
  for (int i = 0; i < c; i++){
    if (q[r][i] == 1) goto nextRow;
  }
  // up diagonal test
  for (int i = 1; ((r-i)>=0 && (c-i)>=0); i++){
    if (q[r-i][c-i] == 1) goto nextRow;
  }
  // down diagonal test
  for (int i = 1; ((r+i)<8 && (c-i)>=0); i++){
    if (q[r+i][c-i] == 1) goto nextRow;
  }
  q[r][c] = 1;
  goto nextCol;

backtrack:
  // Move to previous column
  c--;
 //if move  to the left of the board
        //exit the program
  if (c == -1){
    return 0;
  }
  // Find the square in the column with a queen in it and set r to the row number of that square
  r = 0;
  while (q[r][c] != 1){
    r++;
  }
  // Remove the queen from the current square
  q[r][c] = 0;
  //goto nextRow;
  goto nextRow;

print:
  static int sol_num = 0;
  cout << "Solution #" << ++sol_num << ":\n";
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      cout << q[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  goto backtrack;
}


