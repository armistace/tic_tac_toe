#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

//This function will handle the input from the user
int choose_position()
{
    int x;
    cout <<"Please Select A corresponding Position on the Grid\n";
    cout <<"1 2 3\n4 5 6\n7 8 9\n";
    cout <<"Position: ";
    cin >> x;
    cout << "\n";
    return x;
}

//This function will draw the board on the screen for the user to see what is available
void draw_board(char current_choices[8])
{
    cout <<"\n";
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
    
    return won;
}

//function to check if position is taken
//It will return true IF THE POSITION IS TAKEN!
//Always remember that the function takes in 1 - 9 as the board is drawn
//not 0 - 8 as the array is referenced!
bool position_taken (char current_board[8], int choice)
{
    
    char check = '.';
    int position = choice -1;
    

    if (current_board[position] != check)
    {
	return true;
    }
    else
    {
	return false;
    }
}

//Random AI
//Generates a random number between 1 and 9 and returns it
int random_ai()
{
    int x;
    //generate random seed
    srand (time(NULL));
    
    //Generate Random number between 0 and 9
    x = rand() % 10;
    
    //This ensures that 0 is discarded as it does not make sense on the board
    while (x == 0)
    {
	//Need to generate a new seed each time to ensure a different number
	//if 0 is chosen above
	srand(time(NULL));
	x = rand() % 10;
    }
    
    return x;
}
    
    

//Unbeatable AI
//returns the position that the AI must use given certain conditions
//returns the literal board position as int not the array posistion
int unbeatable_ai(char current_board[8])
{
    //Horizontal check
    //Line 1
    if (current_board[0] == current_board[1] && !position_taken(current_board, 3))
    {
        return 3;
    }
    else if (current_board[2] == current_board[1] && !position_taken(current_board, 1))
    {
        return 1;
    }
    else if (current_board[0] == current_board[2] && !position_taken(current_board, 2))
    {
        return 2;
    }
    //Line 2
    else if (current_board[3] == current_board[4] && !position_taken(current_board, 6))
    {
        return 6;
    }
    else if (current_board[4] == current_board[5] && !position_taken(current_board, 4))
    {
	return 4;
    }
    else if (current_board[3] == current_board[5] && !position_taken(current_board, 5))
    {
	return 5;
    }
    //Line 3
    else if (current_board[6] == current_board[7] && !position_taken(current_board, 9))
    {
	return 9;
    }
    else if (current_board[6] == current_board[8] && !position_taken(current_board, 8))
    {
	return 8;
    }
    else if (current_board[7] == current_board[8] && !position_taken(current_board, 7))
    {
	return 7;
    }
    //Vertical Check
    //Line 1
    else if (current_board[0] == current_board[3] && !position_taken(current_board, 7))
    {
	return 7;
    }
    else if (current_board[3] == current_board[6] && !position_taken(current_board, 1))
    {
	return 1;
    }
    else if (current_board[0] == current_board[6] && !position_taken(current_board, 4))
    {
	return 4;
    }
    //Line 2
    else if (current_board[1] == current_board[4] && !position_taken(current_board, 8))
    {
	return 8;
    }
    else if (current_board[4] == current_board[7] && !position_taken(current_board, 2))
    {
	return 2;
    }
    else if (current_board[1] == current_board[7] && !position_taken(current_board, 5))
    {
	return 5;
    }
    //Line 3
    else if (current_board[2] == current_board[5] && !position_taken(current_board, 9))
    {
	return 9;
    }
    else if (current_board[5] == current_board[8] && !position_taken(current_board, 3))
    {
	return 3;
    }
    else if (current_board[2] == current_board[8] && !position_taken(current_board, 6))
    {
	return 6;
    }
    //Diagonal Check
    //line 1
    else if (current_board[0] == current_board[4] && !position_taken(current_board, 9))
    {
	return 9;
    }
    else if (current_board[4] == current_board[8] && !position_taken(current_board, 1))
    {
	return 1;
    }
    else if (current_board[0] == current_board[8] && !position_taken(current_board, 5))
    {
	return 5;
    }
    //Line 2
    else if (current_board[2] == current_board[4] && !position_taken(current_board, 7))
    {
	return 7;
    }
    else if (current_board[4] == current_board[6] && !position_taken(current_board, 3))
    {
	return 3;
    }
    //to get rid of a compiler warning I need an else, as the only viable option now is 5 that is what we will return
    else
    {
	return 5;
    }
    
}

//User Intro
void user_intro()
{
    cout <<".............................................................\n";
    cout << "\n";
    cout <<"Welcome!\n";
    cout <<"This is Tic Tac Toe\n";
    cout <<"Written by armistace\n";
    cout <<"\n";
    cout <<".............................................................\n";
    cout <<"\n";
}    

int main()
{
    bool wincheck = false;
    char current_board[8];
    int user_choice;
    int ai_choice;
    
    for (int x = 0; x < 9; x++)
    {
	current_board[x] = '.';
    }
    
    user_intro();
    draw_board(current_board);
    
    while (!wincheck)
    {

	user_choice = choose_position();
	while (position_taken(current_board, user_choice) == true)
	{
	    user_choice = choose_position();
	}
	current_board[user_choice - 1] = 'X';
	
	draw_board(current_board);
	
	cout << "AI is now thinking";
	ai_choice = random_ai();
	while (position_taken(current_board, ai_choice) == true)
	{
	    ai_choice = random_ai();
	}
	current_board[ai_choice - 1] = 'O';
	
	draw_board(current_board);
	
	wincheck = win_condition(current_board);
	if (wincheck == true)
	{
	    cout << "true";
	}
	else
	{
	    cout << "false";
	}
    }
    
    
    
    
   
    
}
