#include <stdio.h>
#include <stdlib.h>

void printBoard();
int checkWin();
void clearScreen(); // Declare clearScreen function

char board[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main()
{
    char p1[30], p2[30];
    printf("Enter first player name\n");
    scanf("%s", p1);
    printf("Enter second player name\n");
    scanf("%s", p2);
    int player = 1, input, status = -1, i;
    printBoard();

    while (status == -1)
    {
        player = (player % 2 == 0) ? 2 : 1;
        if (player == 1)
        {
            printf("Enter a number for player 1 (%s)\n", p1);
        }
        else
        {

            printf("Enter a number for player 2 (%s)\n", p2);
        }
        scanf("%d", &input);
        char mark = (player == 1) ? 'X' : 'O';
        if (input < 1 || input > 9 || board[input] == 'X' || board[input] == 'O')
        {

            printf("Invalid Input\n");
            return 0;
        }
        board[input] = mark;
        printBoard();
        int result = checkWin();
        if (result == 1)
        {
            printf("Congratulations, player %d won!\n", player);
            break;
        }
        else if (result == 0)
        {

            printf("DRAW\n");
            break;
        }

        player++;
    }
}

void printBoard()
{
    clearScreen();
    printf("\033[1;31m\033[1m\n~~~~ WELCOME TO TIC TAC TOE ~~~~\n\n");

    // Top row
    printf("          \033[1;37m|\033[0m         \033[1;37m|\033[0m        \n");
    printf("    \033[1;33m%c\033[0m     \033[1;37m|\033[0m   \033[1;33m%c\033[0m     \033[1;37m|\033[0m   \033[1;33m%c\033[0m   \n", board[1], board[2], board[3]);
    printf(" \033[1;37m_________\033[1;37m|\033[0m_________\033[1;37m|\033[0m________\n");

    // Middle row
    printf("          \033[1;37m|\033[0m         \033[1;37m|\033[0m        \n");
    printf("    \033[1;33m%c\033[0m     \033[1;37m|\033[0m   \033[1;33m%c\033[0m     \033[1;37m|\033[0m   \033[1;33m%c\033[0m  \n", board[4], board[5], board[6]);
    printf(" \033[1;37m_________\033[1;37m|\033[0m_________\033[1;37m|\033[0m________\n");

    // Bottom row
    printf("          \033[1;37m|\033[0m         \033[1;37m|\033[0m        \n");
    printf("    \033[1;33m%c\033[0m     \033[1;37m|\033[0m   \033[1;33m%c\033[0m     \033[1;37m|\033[0m   \033[1;33m%c\033[0m  \n", board[7], board[8], board[9]);
    printf("          \033[1;37m|\033[0m         \033[1;37m|\033[0m        \n\n");
}

int checkWin()
{
    if (board[1] == board[2] && board[2] == board[3])
    {
        return 1;
    }
    if (board[4] == board[5] && board[5] == board[6])
    {
        return 1;
    }
    if (board[7] == board[8] && board[8] == board[9])
    {
        return 1;
    }
    if (board[1] == board[4] && board[4] == board[7])
    {
        return 1;
    }
    if (board[2] == board[5] && board[5] == board[8])
    {
        return 1;
    }
    if (board[3] == board[6] && board[6] == board[9])
    {
        return 1;
    }
    if (board[1] == board[5] && board[5] == board[9])
    {
        return 1;
    }
    if (board[3] == board[5] && board[5] == board[7])
    {
        return 1;
    }
    int count = 0;
    for (int i = 1; i <= 9; i++)
    {
        if (board[i] == 'X' || board[i] == 'O')
        {
            count++;
        }
    }
    if (count == 9)
        return 0;

    return -1;
}

void clearScreen()
{
    system("cls");
}
