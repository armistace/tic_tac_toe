#include <iostream>
#include <string>
using namespace std;

//This function will handle the input from the user
int choose_position()
{
    int x;
    cout <<"Please Select A corresponding Position on the Grid\n";
    cout <<"1 2 3\n4 5 6\n7 8 9";
    cout <<"Position: ";
    cin >> x;
    return x;
}

//This function will draw the board on the screen for the user to see what is available
void draw_board(char current_choices[8])
{
    cout <<"\n"
    cout << current_choices[0] << " " << current_choices[1] << " " << current_choices[2] << "\n";
    cout << current_choices[3] << " " << current_choices[4] << " " << current_choices[5] << "\n";
    cout << current_choices[6] << " " << current_choices[7] << " " << current_choices[8] << "\n";
    cout <<"\n";
}

//This function Checks for a win condition
bool win_condition(char current_board[8])
{
    bool won;
    if (current_board[0] == current_board[1] && current_board[0] == current_board[2] && current_board[1] == current_board[2])
    {
        won = true;
    }
    else if (current_board[3] == current_board[4] && current_board[3] == current_board[5] && current_board[4] == current_board[5])
    {
        won = true;
    }
    else if (current_board[6] == current_board[7] && current_board[6] == current_board[8] && current_board[7] == current_board[8])
    {
        won = true;
    }
    else if (current_board[0] == current_board[3] && current_board[0] == current_board[6] && current_board[3] == current_board[6])
    {
        won = true;
    }
    else if (current_board[1] == current_board[4] && current_board[1] == current_board[7] && current_board[4] == current_board[7])
    {
        won = true;
    }
    else if (current_board[2] == current_board[5] && current_board[2] == current_board[8] && current_board[5] == current_board[8])
    {
        won = true;
    }
    else if (current_board[0] == current_board[4] && current_board[0] == current_board[8] && current_board[4] == current_board[8])
    {
        won = true;
    }
    else if (current_board[2] == current_board[4] && current_board[2] == current_board[6] && current_board[4] == current_board[6])
    {
        won = true;
    }
    else
    {
        won = false;
    }
}

//function to check if position is taken
//It will return true IF THE POSITION IS TAKEN!
bool position_check (current_board[8], int choice)
{
    if (current_board[choice = 1] != ".")
    {
	return true;
    }
    else
    {
	return false;
    }
}

