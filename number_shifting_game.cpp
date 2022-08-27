#include <iostream>
#include <conio.h>
#include <vector>
#include <time.h>
#include <windows.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER_PRESS 13
using namespace std;
int board[4][4];  
bool check(vector<int> ar, int num)  //function to check if the number is not previously available 
{
  for (int i : ar)
  {
    if (i == num)
      return false;
  }
  return true;
}
void convert(vector<int> v)  //function to put vector array element into board element
{

  int temp = 0;
  short k, l;
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      board[i][j] = v[temp];
      if (v[temp] == 0)
      {
        k = i;
        l = j;
      }
      temp++;
    }
  }
  temp = board[3][3];
  board[3][3] = '\0';
  board[k][l] = temp;
}
void print()    //print the board
{
  cout << endl;
  cout << "-----------------" << endl;
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {

      cout << "| ";
      if (board[i][j] == 0)
        cout << " ";
      else
        cout << board[i][j];
      if (board[i][j] <= 9)
        cout << " ";
    }
    cout << "|" << endl;
    cout << "-----------------" << endl;
  }
}
void checkWinning()  //funtion to check the winning state
{
  int temp = 1;
  bool result = true;
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      if (i == 3 && j == 3 && board[3][3] == 0)
        break;

      if (board[i][j] != temp)
      {
        result = false;
        break;
      }
      temp++;
    }
  }
  if (result)
  {

    cout << "\ncongrates you won the game!";
    exit(0);
  }
  else
  {
    cout << "\n not won yet!\n";
  }
}

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int main()
{
  srand(time(0));
  SetConsoleTextAttribute(hConsole, rand() % 100);
  cout << "---------------------------------------------------------------------------------------------------------" << endl;
  cout << "\t\t\t\t WELCOME TO NUMBER SHIFTING GAME " << endl;
  cout << "---------------------------------------------------------------------------------------------------------" << endl;
  SetConsoleTextAttribute(hConsole, 0);
  cout << "Use Arrow keys to move the empty field \nuse Enter key after arranging" << endl;
  vector<int> ar;
  int matrix[4][4];
  int num;
  // random function work according to current time
  for (int i = 0;; i++)
  {
    if (ar.size() == 16)
      break;
    num = rand() % 16;
    if (check(ar, num))
      ar.push_back(num);
  }
  convert(ar); // convert vector into 2d array
  print();
  int chances = 100;  //you can also insert move chance according to your wish
  int times = 0, mv;
  int i = 3, j = 3;
  int temp;
  while (times < chances)  
  {
    // checkWinning();  uncomment if you want to check every time then remove case ENTER_PRESS case
    mv = getch(); // taking input from keyboard
    switch (mv)
    {
    case KEY_UP: // up arrow
      if (i > 0 && i <= 3)
      {
        temp = board[i - 1][j];
        board[i][j] = temp;
        board[i - 1][j] = 0;
        i--;
        print();
      }
      break;

    case KEY_DOWN: // down arrow
      if (i >= 0 && i < 3)
      {
        temp = board[i + 1][j];
        board[i][j] = temp;
        board[i + 1][j] = 0;
        i++;
        print();
      }
      break;

    case KEY_LEFT: // left arrow
      if (j > 0 && j <= 3)
      {
        temp = board[i][j - 1];
        board[i][j] = temp;
        board[i][j - 1] = 0;
        j--;
        print();
      }
      break;

    case KEY_RIGHT: // right arrow
      if (j >= 0 && j < 3)
      {
        temp = board[i][j + 1];
        board[i][j] = temp;
        board[i][j + 1] = 0;
        j++;
        print();
      }
      break;
    case ENTER_PRESS:
      checkWinning();
      break;
    }
  }
  cout << "out of move!";
}