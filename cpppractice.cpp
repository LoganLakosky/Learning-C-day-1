#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <iomanip>

using std::vector;
using std::string;
using std::cout;
using std::pair;
using std::cin;
using std::getline;



void drawBoard(char* spaces) {
  cout << '\n';
  cout << "     |     |     " << '\n';
  cout << " " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << " " << '\n';
  cout << "_____|_____|_____" << '\n';
  cout << "     |     |     " << '\n';
  cout << " " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << " " << '\n';
  cout << "_____|_____|_____" << '\n';
  cout << "     |     |     " << '\n';
  cout << " " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << " " << '\n';
  cout << "     |     |     " << '\n';
  cout << '\n';

}

void playerMove(char* spaces, char player) {
  int number;
  do {

    cout << "Enter a spot to place a marker (1-9)";
    cin >> number;
    number--;
    if (spaces[number] == ' ') {
      spaces[number] = player;
      break;
    }

  } while (number < 0 || number > 8);
}

void computerMove(char* spaces, char computer) {
  int number;

  srand(time(0));


  while (true) {
    number = rand() % 9;
    if (spaces[number] == ' ') {
      spaces[number] = computer;
      break;
    }
  }

}

bool checkWinner(char* spaces, char player, char computer) {

  if (spaces[0] == spaces[1] && spaces[1] == spaces[2] && spaces[0] != ' ') {
    spaces[0] == player ? cout << "You win!!" : cout << "You lose!";
  }
  else if (spaces[3] == spaces[4] && spaces[4] == spaces[5] && spaces[3] != ' ') {
    spaces[3] == player ? cout << "You win!!" : cout << "You lose!";
  }
  else if (spaces[6] == spaces[7] && spaces[7] == spaces[8] && spaces[6] != ' ') {
    spaces[6] == player ? cout << "You win!!" : cout << "You lose!";
  }
  else if (spaces[0] == spaces[4] && spaces[4] == spaces[9] && spaces[0] != ' ') {
    spaces[0] == player ? cout << "You win!!" : cout << "You lose!";
  }
  else if (spaces[2] == spaces[4] && spaces[4] == spaces[6] && spaces[2] != ' ') {
    spaces[2] == player ? cout << "You win!!" : cout << "You lose!";
  }


  return 0;



}

bool checkTie(char* spaces) {
  return 0;
}



int main() {

  char spaces[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
  char player = 'X';
  char computer = 'O';
  bool running = true;

  drawBoard(spaces);

  while (running) {
    playerMove(spaces, player);
    drawBoard(spaces);

    if (checkWinner(spaces, player, computer)) {
      running = false;
      break;
    }
    else if (checkTie(spaces)) {
      running = false;
      break;
    }

    computerMove(spaces, computer);
    drawBoard(spaces);
    if (checkWinner(spaces, player, computer)) {
      running = false;
      break;
    } else if (checkTie(spaces)) {
      running = false;
      break;
    }

  }



  return 0;
}
