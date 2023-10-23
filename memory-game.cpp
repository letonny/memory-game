#include <iostream>
using namespace std;

const int ROWS = 4,
          COLS = 4;

void displayBoard(int [][COLS], int, int);
void userChoice(int[][COLS], int &, int &);
void positionToCards(int, int, int &, int &, int &, int &);
bool checkMatch(int[][COLS], int, int, int, int);

//****************************************************************************************************

int main ()
{
    int labelCards[ROWS][COLS] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int hiddenValue[ROWS][COLS] = {8, 6, 12, 8, 10, 0, 6, 10, 4, 14, 2, 12, 2, 14, 4, 0};
   
    int choice1,
        choice2,
        hiddenRow1,
        hiddenCol1,
        hiddenRow2,
        hiddenCol2,
        numMatch = 0;

    bool checkValue;

    while (numMatch < ROWS*COLS/2)
    {
        displayBoard(labelCards, ROWS, COLS);

        userChoice(labelCards, choice1, choice2);

        positionToCards(choice1, choice2, hiddenRow1, hiddenCol1, hiddenRow2, hiddenCol2);

        if (checkMatch(hiddenValue, hiddenRow1, hiddenCol1, hiddenRow2, hiddenCol2)) 
        {
            labelCards[hiddenRow1][hiddenCol1] = -1;
            labelCards[hiddenRow2][hiddenCol2] = -1;
            numMatch++;
            cout << "It's a match" << endl;
        } 
        else
        {
            cout << "It's not a match" << endl;
        }
    }

    cout << "You have found all the matching pairs!" << endl;

    return 0;
}

//****************************************************************************************************

void displayBoard(int board[][COLS], int rows, int cols)
{
    cout << "The following numbers show the label of each card." << endl
         << "The value of each card is hidden under the label." << endl
         << "Please Pick two cards." << endl
         << "============================================" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << board[i][j] << "\t";

            if ((j + 1) % 4 == 0)
            {
                cout << endl << endl;
            } 
        }
            if ((i + 1) % 4 == 0)
            {
                cout << endl;
            } 
    }
}

//****************************************************************************************************

void userChoice(int board[][COLS], int & choice1, int & choice2)
{
    cin >> choice1 >> choice2;
}

//****************************************************************************************************

void positionToCards(int choice1, int choice2, int & rows1, int & cols1, int & rows2, int & cols2)
{
    rows1 = choice1 / ROWS;
    cols1 = choice1 % COLS;

    rows2 = choice2 / ROWS;
    cols2 = choice2 % COLS;
}

//****************************************************************************************************

bool checkMatch(int hiddenBoard[][COLS], int row1, int col1, int row2, int col2)
{
    bool checker;

    if (hiddenBoard[row1][col1] == hiddenBoard[row2][col2])
    {
        checker = true;
    }
    else
    {
        checker = false;
    }
    
    return checker;

}

//****************************************************************************************************

/*

The following numbers show the label of each card.
The value of each card is hidden under the label.
Please Pick two cards.
============================================
0       1       2       3

4       5       6       7

8       9       10      11

12      13      14      15


1 2
It's not a match
The following numbers show the label of each card.
The value of each card is hidden under the label.
Please Pick two cards.
============================================
0       1       2       3

4       5       6       7

8       9       10      11

12      13      14      15


0 3
It's a match
The following numbers show the label of each card.
The value of each card is hidden under the label.
Please Pick two cards.
============================================
-1      1       2       -1

4       5       6       7

8       9       10      11

12      13      14      15


1 6
It's a match
The following numbers show the label of each card.
The value of each card is hidden under the label.
Please Pick two cards.
============================================
-1      -1      2       -1

4       5       -1      7

8       9       10      11

12      13      14      15


9 13
It's a match
The following numbers show the label of each card.
The value of each card is hidden under the label.
Please Pick two cards.
============================================
-1      -1      2       -1

4       5       -1      7

8       -1      10      11

12      -1      14      15


5 15
It's a match
The following numbers show the label of each card.
The value of each card is hidden under the label.
Please Pick two cards.
============================================
-1      -1      2       -1

4       -1      -1      7

8       -1      10      11

12      -1      14      -1


8 14
It's a match
The following numbers show the label of each card.
The value of each card is hidden under the label.
Please Pick two cards.
============================================
-1      -1      2       -1

4       -1      -1      7

-1      -1      10      11

12      -1      -1      -1


10 12
It's a match
The following numbers show the label of each card.
The value of each card is hidden under the label.
Please Pick two cards.
============================================
-1      -1      2       -1

4       -1      -1      7

-1      -1      -1      11

-1      -1      -1      -1


2 11
It's a match
The following numbers show the label of each card.
The value of each card is hidden under the label.
Please Pick two cards.
============================================
-1      -1      -1      -1

4       -1      -1      7

-1      -1      -1      -1

-1      -1      -1      -1


4 7
It's a match
You have found all the matching pairs!

*/