#include <iostream>
#include <stdlib.h>
#include<windows.h>
#include<string>
using namespace std;
//Array for the board
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
//Variable Declaration
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int choice;
int row,column;
char turn = 'X';
bool draw = false;
//function prototype
void printheader();
void display_board();
void player_turn();
bool game();
void gotoxy(int x, int y);


//Program Main Method

int main()
{
    printheader();
    
    while(game())
    {
                                                                                                               

        display_board();
        player_turn();
        game();
    }
   
    if(turn == 'X' && draw == false)
    {
      SetConsoleTextAttribute(hConsole, 2);
        cout<<"                                                       "<<endl;
        
        cout<<"\t\t\t\t\t\nCongratulations! Player with 'O' has won the game"<<endl;
        cout<<"*********************************************************"<<endl;
        exit(0);
    }
    if(turn == 'O' && draw == false)
    {
        SetConsoleTextAttribute(hConsole, 2);
        cout<<"                                                               "<<endl;
    
        cout<<"\t\t\t\t\t\nCongratulations! Player with 'X' has won the game"<<endl;
        cout<<"**************************************************************"<<endl;
        exit(0);
    }
    else
    
    cout<<"\nGAME DRAW!!!\n"<<endl;
} 
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

//Function to show the current status of the gaming board

void display_board()
{
 
  
    // Game Board LAYOUT
    system("cls");
    printheader();
    cout<<"PLAYER - 1 [X]\t PLAYER - 2 [O]\n\n";
     SetConsoleTextAttribute(hConsole, 12);
      
    cout<<"\t\t\t\t\t\t _________________\n";
    cout<<"\t\t\t\t\t\t|     |     |     |\n";
    cout<<"\t\t\t\t\t\t|  "<<board[0][0]<<"  | " <<board[0][1]<<"   |  "<<board[0][2]<<"  | "<<" \n";
    cout<<"\t\t\t\t\t\t|_____|_____|_____|\n";
    cout<<"\t\t\t\t\t\t|     |     |     |\n";
    cout<<"\t\t\t\t\t\t|  "<<board[1][0]<<"  | " <<board[1][1]<<"   |  "<<board[1][2]<<"  | "<<" \n";
    cout<<"\t\t\t\t\t\t|_____|_____|_____|\n";
    cout<<"\t\t\t\t\t\t|     |     |     |\n";
    cout<<"\t\t\t\t\t\t|  "<<board[2][0]<<"  | " <<board[2][1]<<"   |  "<<board[2][2]<<"  | "<<" \n";
    cout<<"\t\t\t\t\t\t|_____|_____|_____|\n";
}
void printheader()
{
    SetConsoleTextAttribute(hConsole, 6);
    gotoxy(15,5);
     cout<<"                                                                                                     "<<endl;
      gotoxy(15,6 );
                          cout<<" ****************************************************************************************************"<<endl;
     gotoxy(15, 7);
                         cout<<"            ****** *****    .*.* *     *****   .*.     *   .*      ******    *****  ******         " <<endl; 
                          gotoxy(15, 8);
                         cout<<"               *     *    .*             *   .*   *.   * .*           *      *   *  *.....          " <<endl; 
                          gotoxy(15, 9);
                         cout<<"               *     *    *.             *  .*******.  *  *.          *      *   *  *                " <<endl; 
                          gotoxy(15, 10);
                         cout<<"               *   *****    *.*.**       * .*       *. *    *.        *      *****  ******            " <<endl; 
                          gotoxy(15, 11);
                         cout<<" ****************************************************************************************************  " <<endl;  
                          gotoxy(15, 12);
                         cout<<"                                                                                                     "<<endl;
}

//Function to get the player input and update the board

void player_turn()
{
    if(turn == 'X')

    {
           SetConsoleTextAttribute(hConsole, 7);
        cout<<"\n\tPlayer - 1 turn   (symbol: X) : ";
    }
    else if(turn == 'O')
    {
           SetConsoleTextAttribute(hConsole, 1);
        cout<<"\n\tPlayer - 2  turn  ( symbol:O): ";
    }
    //Taking input from user
    //updating the board according to choice and reassigning the turn Start

    cin>> choice;

    //switch case to get which row and column will be update

    switch(choice)
    {
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout<<"Invalid Move"<<endl;
    }

    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'X';
        turn = 'O';
    
    }
    else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'O';
        turn = 'X';
    }else 
    {
        //if input position already filled
        cout<<"\t\t\t\tBox already filled!n Please choose another!!\n\n";
        player_turn();
    }
    /* Ends */
    display_board();
}

//Function to get the game status e.g. GAME WON, GAME DRAW GAME IN CONTINUE MODE

bool game()
{
    //checking the win for Simple Rows and Simple Column
    for(int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return false;

    //checking the win for both diagonal

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return false;

    //Checking the game is in continue mode or not
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != 'X' && board[i][j] != 'O')
    return true;

    //Checking the if game already draw
    draw = true;
    return false;
}



