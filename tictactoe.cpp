#include <iostream>
bool is_winner();
bool filled_up();
void introduction();
void take_turn();
void set_position();
void update_board();
void change_player();
void draw();
void end_game();

std::string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
int player = 1;
int position = 0;


void introduction()
{
  std::cout << "Welcome To Tic-Tac-Toe\n";
  std::cout << "Press [Enter] to start the game:\n";
  std::cin.ignore();

  std::cout << "\n";
  std::cout << "             ===========================\n";
  std::cout << "                      Tic-Tac-Toe       \n";
  std::cout << "             ===========================\n";

  std::cout << "You must have 2 players to play this game.\n";
  std::cout << "Player number 1) X\n";
  std::cout << "Player number 2) O\n";

  std::cout << "The 3 x 3 grid that players will be compete:\n";
  std::cout << "     |     |     \n";
  std::cout << "  1  |  2  |  3  \n";
  std::cout << "_____|_____|_____\n";
  std::cout << "     |     |     \n";
  std::cout << "  4  |  5  |  6  \n";
  std::cout << "_____|_____|_____\n";
  std::cout << "     |     |     \n";
  std::cout << "  7  |  8  |  9  \n";
  std::cout << "     |     |     \n\n";
}

bool is_winner()
{
  bool winner = false;

  //row
  if((board[0] == board[1] && board[1] == board[2]) && board[0] != " ")
  {
    winner = true;
  }
  if((board[3] == board[4] && board[4] == board[5]) && board[3] != " ")
  {
    winner = true;
  }
    if((board[6] == board[7] && board[7] == board[8]) && board[6] != " ")
  {
    winner = true;
  }

  //columns
  if((board[0] == board[3] && board[3] == board[6]) && board[0] != " ")
  {
    winner = true;
  }
  if((board[1] == board[4] && board[4] == board[7]) && board[1] != " ")
  {
    winner = true;
  }
    if((board[2] == board[5] && board[5] == board[8]) && board[2] != " ")
  {
    winner = true;
  }

  //diagonals
    if((board[0] == board[4] && board[4] == board[8]) && board[0] != " ")
  {
    winner = true;
  }
    if((board[2] == board[4] && board[4] == board[6]) && board[2] != " ")
  {
    winner = true;
  }

return winner;

}

bool filled_up()
{
  bool filled = true;

  for(int i = 0; i < 9; i++)
  {
    if(board[i] == " ")
    {
      filled = false;
    }
  }

  return filled;
}

void draw()
 {
 
    std::cout << "     |     |      \n";
 
    std::cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
 
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
 
    std::cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
 
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
 
    std::cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
    std::cout << "     |     |      \n";
 
    std::cout << "\n";
}


void set_position()
{

  std::cout << "Player " << player << "'s Turn (Enter 1-9): ";
  while(!(std::cin >> position))
  {
    std::cout << "Player " << player << " , please enter a valid number between 1 and 9: ";
    std::cin.clear();
    std::cin.ignore();
  }
  std::cout << "\n";

  while(board[position-1] != " ")
  {
    std::cout << "Oops, This position has been taken!\n";
    std::cout << "Player " << player << "'s Turn (Please Enter 1-9): ";
    std::cin >> position;

    std::cout << "\n";
  }
}

void update_board()
{
  if(player % 2 == 1)
  {
    board[position-1] = "X";
  }
  else
  {
    board[position-1] = "O";
  }
}

void change_player()
{
  if(player == 1)
  {
    player++;
  }
  else
  {
    player--;
  }
}

void take_turn()
{
  while (!is_winner() && !filled_up())
  {
     set_position();
     update_board();
     change_player();
     draw();
  }
}

void end_game()
{
  if(is_winner())
  {
    std::cout << "Winner!\n";
  }
  else if(filled_up())
  {
    std::cout << "Tie!\n";
  }
}

int main()
{
  introduction();
  take_turn();
  end_game();
}
