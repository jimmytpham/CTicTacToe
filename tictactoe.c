/**
 *Jimmy Pham
 *April 7, 2023
 *
 *
 *Allows user to play a game of Tic-Tac-Toe against a computer.
 *The player is X and the computer is O
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

// Function Declarations
void setBoard();
void drawBoard();
int roundCount();
void playerMove();
void computerMove();
char checkWinner();
void displayWinner(char);

//variables
char board[3][3];
char PLAYER = 'X';
char COMPUTER = 'O';

int main()
{
    //sets winner to none
    char winner = ' ';


    printf("******************************\n");
    printf("Tic Tac Toe\n");
    printf("COMP 2131 - 2023\n");
    printf("You will be playing against the computer\n");
    printf("******************************\n");


    char name[50];
    printf("What is your name?");
    scanf("%[^\n]%*c",name);
    printf("Hello %s... Let's have fun!! You = X | Computer = O",name);

    //sets board empty
    setBoard();

    //while loop to keep playing until there is a winner or draw
    while(winner == ' ' && roundCount() != 9)
    {
        drawBoard();

        playerMove();
        winner = checkWinner();

        if(winner != ' ' || roundCount() == 9)
        {
            break;
        }

        computerMove();
        winner = checkWinner();

        if(winner !=' ' || roundCount() == 9)
        {
            break;
        }
    }

    drawBoard();
    displayWinner(winner);

    printf("Thanks for playing!");
    return 0;
}

void setBoard()
{
    for(int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            board[i][j]=' ';
        }
    }
}

void drawBoard()
{
    //draw the board using the board array to place characters in
    printf("\n------------------------------");
    printf("\n %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n------------------------------\n");


}
int roundCount()

{   //if roundcount = 9 (max moves possible) then it is a draw
    int roundCount = 0;

    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if(board[i][j] !=' ')
            {
                roundCount++;
            }
        }
    }

    return roundCount;
}
void playerMove()
{
    int x, y;


    do
    {
        //user enters 2 numbers for board array
        printf("Enter X(1-3), Y(1-3) coordinates for your move (ex, 1,1): ");
        scanf("%d%*c%d", &x, &y);
        x--; //array position is from 0-2, so the input 3 needs to turn into 2 and so on
        y--;

        if(board[x][y] != ' ')
        {
            printf("Invalid move!\n");
        } else {
            board[x][y] = PLAYER;
            break;
        }
    }
    while(board[x][y] != ' ');
}




void computerMove()
{
    //randomly generated numbers for cpu move
    int x, y;

    if(roundCount() < 9)
    {
        do
        {
            x = rand () % 3;
            y = rand () % 3;

        } while (board[x][y] != ' ');

        board[x][y] = COMPUTER;
    }else{
        displayWinner(' ');
    }
}

char checkWinner()
{
    //checks rows
    for(int i = 0; i<3; i++)
    {
        if(board[i][0] == board [i][1] && board[i][0] == board [i][2])
        {
            return board[i][0];
        }
    }

    //check columns
    for(int i = 0; i<3; i++)
    {
        if(board[0][i] == board [1][i] && board[0][i] == board [2][i])
        {
            return board[0][i];

        }
    }

    //check diagonals
    if(board[0][0] == board[1][1] && board [0][0] == board[2][2])
    {
        return board[0][0];
    }
    if(board[0][2] == board[1][1] && board [0][2] == board[2][0])
    {
        return board[0][2];
    }

    return ' ';

}

void displayWinner(char winner)
{
    if(winner == PLAYER)
    {
        printf("YOU WIN!\n");
    }
    else if(winner == COMPUTER)
    {
        printf("YOU LOSE!\n");
    }
    else
    {
        printf("DRAW!\n");
    }

}
