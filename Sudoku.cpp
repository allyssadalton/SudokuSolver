/*    @file Sudoku.cpp   
      @author Allyssa Dalton
      @date 02/09/2025

			@description Implements a class for solving Sudoku puzzles.
*/

#include <string>
#include <iostream>
#include <stdexcept>
#include <set>
#include <queue>
#include <algorithm>

#include "Sudoku.h"

Sudoku::Sudoku(): starting(9 * 9, EMPTY){
  // Nothing to do here
}

Sudoku::Sudoku(string state): starting(9 * 9, EMPTY){
  for(unsigned i = 0; i < 81 && i < state.length(); i++){
    if(state.at(i) == ' '){
      starting.at(i) = 0;
    }else{
      starting.at(i) = state.at(i) - '0';
    }
  }
}


bool Sudoku::solve(){
  priority_queue< vector<char>, vector<vector<char>>, SCompare> states;
  states.push(starting); //adds starting board to queue

  while (!states.empty()){ //continues until there are no more boards to use
    vector<char> board = states.top(); //vector becomes top of board
    states.pop(); //removes the board currently used from the queue
    if (completeBoard(board)){  //if board is complete
      print(board);
      cout << "Solved!" << endl;;
      return true;
    }
    //places the first number than works in each spot until that doesn't work
    for (unsigned i = 0; i < 81; i++){
      if (board[i] == 0){
        for (char num = 1; num <= 9; num++){
          board[i] = num;
          if (validBoard(board)){states.push(board);}
        }
        break;
      }
    }
  }
  if (states.empty()){cout << "Unsolvable." << endl;}
  return false;
}

int Sudoku::numSolutions(int limit, bool print_solutions){
  // Fill me in if doing the extra credit
  return -1;
}
  
void Sudoku::print(){
  print(starting);
}

void Sudoku::print(const vector<char> &data){
  cout << " ----------------------- " << endl;
  for (unsigned i = 0; i < 9; i++){
    cout << "| ";
    for (unsigned j = 0; j < 9; j++){
      char num = data[XY(j, i)];
      cout << (num == 0 ? ' ' : char(num + '0')) << " ";  //Shout out to Chatgpt
      if (j % 3 == 2){cout << "| ";}
    }
    cout << endl;
    if (i % 3 == 2){cout << " ----------------------- " << endl;}
  }
}

char& Sudoku::at(unsigned x, unsigned y){
  return starting.at(XY(x, y));
}

bool Sudoku::validBoard(const vector<char> &data){
  set<char> row[9], col[9], box[9]; //I used Chatgpt for this line
  for (unsigned i = 0; i < 9; i++){
    for (unsigned j = 0; j < 9; j++){
      char num = data[XY(j, i)];

      //if the spot is empty, it skips over and goes to the next spot
      if (num == 0){continue;}

      // if the num being checked has already been found in that row, col, box, then false is returned
      // if not, it's added to the set and the process is continued
      if (row[i].count(num)){return false;}
      row[i].insert(num); 
      if (col[j].count(num)){return false;}
      col[j].insert(num); 
      int k = (i / 3) * 3 + (j / 3); // I also used Chatgpt for this line because my math skills are kinda bad now
      if (box[k].count(num)){return false;}
      box[k].insert(num);
    }
  }
  return true;
}

bool Sudoku::completeBoard(const vector<char> &data){
  if (!validBoard(data)){return false;}
  //checks to see if the board is full
  for (unsigned i = 0; i < data.size(); i++) {
    if (data[i] == 0){return false;}
  }
  return true;
}

unsigned Sudoku::XY(unsigned x, unsigned y){
  if(x >= 9)throw runtime_error("x too big");
  if(y >= 9)throw runtime_error("y too big");
  return x + y * 9;
}



