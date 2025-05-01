/*    @file Sudoku_test.cpp   
      @author Allyssa Dalton
      @date 02/09/2025

			@description Tests for the Sudoku class
*/

#include "gtest/gtest.h"

#include "Sudoku.h"

TEST(XY, One) {
  Sudoku a;
  EXPECT_EQ(a.XY(0,0), 0);
  EXPECT_EQ(a.XY(2,0), 2);
  EXPECT_EQ(a.XY(0,1), 9);
  EXPECT_EQ(a.XY(1,1), 10);
  EXPECT_EQ(a.XY(8,8), 80);
  EXPECT_ANY_THROW(a.XY(9,0));
  EXPECT_ANY_THROW(a.XY(0,9));
}

TEST(Valid, One) {
  Sudoku a;
  a.at(0,0) = 1;
  EXPECT_TRUE(a.validBoard(a.starting));
  a.at(1,0) = 2;
  EXPECT_TRUE(a.validBoard(a.starting));
  a.at(2,0) = 3;
  EXPECT_TRUE(a.validBoard(a.starting));
  a.at(0,1) = 4;
  EXPECT_TRUE(a.validBoard(a.starting));
  a.at(0,1) = 5;
  EXPECT_TRUE(a.validBoard(a.starting));
  a.at(1,1) = 6;
  EXPECT_TRUE(a.validBoard(a.starting));
  a.at(0,2) = 7;
  EXPECT_TRUE(a.validBoard(a.starting));
  a.at(1,2) = 8;
  EXPECT_TRUE(a.validBoard(a.starting));
  a.at(2,2) = 9;
  EXPECT_TRUE(a.validBoard(a.starting));
}

TEST(Valid, Two) {
  Sudoku a;
  a.at(0,0) = 1;
  EXPECT_TRUE(a.validBoard(a.starting));
  a.at(8,0) = 1;
  EXPECT_FALSE(a.validBoard(a.starting));
  a.at(8,0) = 2;
  EXPECT_TRUE(a.validBoard(a.starting));
  a.at(0,8) = 1;
  EXPECT_FALSE(a.validBoard(a.starting));
  a.at(0,8) = 2;
  EXPECT_TRUE(a.validBoard(a.starting));
}

TEST(Valid, Long) {
  Sudoku a("13 25 789526798 347891 42562134658974578 9362698327415345 71928861942573972583641");
  EXPECT_TRUE(a.validBoard(a.starting));
  a.at(3,0) = 3;
  EXPECT_FALSE(a.validBoard(a.starting));
  a.at(3,0) = 2;
  EXPECT_TRUE(a.validBoard(a.starting));
  a.at(0,1) = 1;
  EXPECT_FALSE(a.validBoard(a.starting));
}

TEST(Valid, Long2) {
Sudoku a("912576348345128679678349125123457896456891237789263451231785964564912783");
  EXPECT_TRUE(a.validBoard(a.starting));
}

// More validBoards TODO
TEST(Complete, One) {
  Sudoku a("134256789526798134789134256213465897457819362698327415345671928861942573972583641");
  EXPECT_TRUE(a.validBoard(a.starting));
  EXPECT_TRUE(a.completeBoard(a.starting));
}

TEST(Complete, Two) {
  Sudoku a("123456789456798123789123456214365897365879214897214365531642978642987531978531642");
  EXPECT_TRUE(a.validBoard(a.starting));
  EXPECT_TRUE(a.completeBoard(a.starting));
}

TEST(Complete, Three) {
Sudoku a("912576348345128679678349125123457896456891237789263451231785964564912783");
  EXPECT_TRUE(a.validBoard(a.starting));
  EXPECT_FALSE(a.completeBoard(a.starting));
}

TEST(Solvable, One) {
  Sudoku a("123");
  EXPECT_TRUE(a.solve());
}

TEST(Solvable, Two) {
  Sudoku a("9125763483451286796783491251234578964568912377892634512317859");
  EXPECT_TRUE(a.solve());
}

TEST(Solvable, Three) {
  Sudoku a("1342567895267981347891342562");
  EXPECT_TRUE(a.solve());
}

TEST(Solvable, Four) {
  Sudoku a("1342567895267981347198342562");
  EXPECT_FALSE(a.solve());
}

// The tests below are for extra credit
// Running 'make test' contains an exception to skip any test that starts
// with EC_
// To run the extra credit tests, run 'make ec', which includes all
// tests.

TEST(EC_numSolutions, One) {
  Sudoku a("134256789526798134789134256213465897457819362698327415345671928861942573"); 
  EXPECT_EQ(a.numSolutions(-1, false), 1);
}

TEST(EC_numSolutions, Four) {
  Sudoku a("134256789526798134789134256213465897457819362698327415345671928");
  EXPECT_EQ(a.numSolutions(-1, false), 4);
}

TEST(EC_numSolutions, More) {
  Sudoku a("134256789526798134789134256213465897457819362698327415");
  EXPECT_EQ(a.numSolutions(-1, false), 144);
}

TEST(EC_numSolutions, More2) {
  Sudoku a("1342567895267981347891342562134658974578193626983274153");
  EXPECT_EQ(a.numSolutions(-1, false), 48);
}

TEST(EC_numSolutions, Fewer) {
  Sudoku a("134256789526798134789134256213465897457819362698327415862973541");
  EXPECT_EQ(a.numSolutions(-1, false), 2);
}


