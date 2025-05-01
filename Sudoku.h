#ifndef SUDOKU_H
#define SUDOKU_H  

/*    @file Sudoku.h   
      @author Allyssa Dalton
      @date 02/09/2025

			@description Implements a class for solving Sudoku boards
*/

#include <string>
#include <vector>
#include <algorithm>


using namespace std;

#define EMPTY 0


class SCompare{
  public:
    bool operator() (vector<char> a, vector<char> b){
      /// True if a < b, false otherwise - Max queue
      int a_empty = count(a.begin(), a.end(), EMPTY);
      int b_empty = count(b.begin(), b.end(), EMPTY);
      return a_empty > b_empty;
    }
};
// Class used to specify how a priority_queue orders elements.
// Assumes the elements in the queue are vector<char> type.

class Sudoku{
  public:
  Sudoku();
    // Sets an empty board

  Sudoku(string state);
    // A starting state as a string of digits, with spaces
    // for blanks, row by row.  Any string less than 81 characters long
    // (9 wide by 9 high) will assume blanks for the rest of the board.

  bool solve();
    // Attempts to solve the current board.

  char& at(unsigned x, unsigned y);
    // Allows reading and changing of a position on the current board.

  void print();
    // Prints the current board to the screen

  int numSolutions(int limit = -1, bool print_solutions = true); // Extra credit
    // Returns how many solutions there are to the current board up
    // to limit.  If limit is -1, find all.  Print all solutions if
    // print is true.
  

  
  
  //private:  // Making public for testing purposes.

  vector<char> starting;
    // Internal board used to set up the board to solve.

  void print(const vector<char> &data);
    // Prints the given board
  bool validBoard(const vector<char> &data);
    // Returns true if the given board is valid (no conflicts)
  bool completeBoard(const vector<char> &data);
    // Returns true if the given board is a complete solution.

  // Helper function
  unsigned XY(unsigned x, unsigned y);

};


  
#endif