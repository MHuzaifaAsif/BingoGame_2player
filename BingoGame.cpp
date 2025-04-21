#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
using namespace std;
// FUNCTION SECTION
void printMenu();
void instructions();
void credits();
void gameHistory();
void funcgameid();
void printCard1();
void printCard2();
void winCondition1(int &, int &, int &);
void winCondition2(int &, int &, int &);
bool isNumberNulled(int num);
// GLOBAL VARIABLES
int choice = 0;
int card1[5][5];
int card2[5][5];
int gameId;

int main()
{
    system("color 2");
label:
    srand(time(0));
    // I DECLARE ALL VARIABLES HERE
    string player1;
    string player2;
    int toss;
    int row = 0;       // variable to count bingo rows for card1
    int diagonal1 = 0; // variable to count bingo diagonals for card1
    int col = 0;       // variable to count bingo columns for card1
    int d1 = 0;
    int d2 = 0;
    int row2 = 0;      // variable to count bingo rows for card2
    int diagonal2 = 0; // variable to count bingo diagonals for card2
    int col2 = 0;      // variable to count bingo columns for card2
    int sum1 = 0;      // total points of hom many bingo rows ,cols or diagonals for card1
    int sum2 = 0;      // total points of hom many bingo rows ,cols or diagonals for card2
    int d11 = 0;
    int d22 = 0;

    cout << "\t\t\t\t\t\tBINGO GAME coded by Error 404" << endl;
    cout << "\t\t\t\t\t\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
    printMenu();
    if (choice == 2)
    {
        system("CLS");
        funcgameid();
        cout << "\n ENTER Player 1 Name " << endl;
        cin >> player1;
        cout << " ENTER Player 2 NAME " << endl;
        cin >> player2;
        // RANDOM CARD FOR PLAYER 1
        int i, j, count;
        int array[25];
        for (i = 0; i < 25; i++) // stored numbers from 1-25 in a 1D array
        {
            array[i] = (rand() % 25) + 1;
            for (j = 0, count = 0; j <= i; j++) // loops chek that from 0 index till j index if value repeated
            {
                if ((array[i] == array[j]) && (i != j)) // if value repeated then increase count
                {
                    count++;
                }
            }
            if (count > 0) // and if count >1 then it again stores value in same index and and agin checks the whole array
            {
                i--; // again that index if value repeted in array
            }
        }
        int l = 0;              // length of 1D started from 0 index
        for (i = 0; i < 5; i++) // storing values in card of player 1
        {
            for (j = 0, l; j < 5 && l < 25; j++, l++)
            {
                card1[i][j] = array[l];
            }
        }
        cout << endl
             << endl;
        // RANDOM CARD FOR PLAYER 2
        int x, y, count2;
        int array2[25];
        for (x = 0; x < 25; x++) // stored numbers from 1-25 in a 1D array
        {
            array2[x] = (rand() % 25) + 1;
            for (y = 0, count2 = 0; y <= x; y++) // loops chek that from 0 index till j index if value repeated
            {
                if ((array2[x] == array2[y]) && (x != y)) // if value repeated then increase count2
                {
                    count2++;
                }
            }
            if (count2 > 0) // if count >1 then it again stores value in same index and and agin checks the whole array
            {
                x--;
            }
        }
        int a = 0; // a is used to initialize index of array2 with 0
        for (x = 0; x < 5; x++)
        {
            for (y = 0, a; y < 5 && a < 25; y++, a++)
            {
                card2[x][y] = array2[a];
            }
        }
        system("pause ");
        system("CLS");
        toss = rand() % 2 + 1;
        if (toss % 2 == 0)
            cout << endl
                 << player1 << " win the toss!!!!!!\n";
        else
            cout << endl
                 << player2 << " win the toss!!!!!!\n";
        while (sum1 < 5 && sum2 < 5)
        {
            if (toss % 2 == 0)
            {
                winCondition1(row, col, diagonal1);
                sum1 = col + row + diagonal1;
                if (sum1 < 5)
                {
                    cout << player1 << " YOUR BINGO CARD IS :" << endl;
                    printCard1();
                    int num;
                    cout << player1 << " " << "ENTER NUMBER BETWEEN 1-25" << endl;
                    cin >> num;
                    while (num > 25 || num < 1 || isNumberNulled(num))

                    {
                        if (isNumberNulled(num))
                        {
                            cout << "\nThis number has already been called or nulled. Try again: ";
                        }
                        else
                        {
                            cout << "\nInvalid card entry. Try again: ";
                        }
                        cin >> num;
                    }
                    for (int i = 0; i < 5; i++)
                    {
                        for (int j = 0; j < 5; j++)
                        {
                            if (card1[i][j] == num)
                            {
                                card1[i][j] = 0;
                            }
                            if (card2[i][j] == num)
                            {
                                card2[i][j] = 0;
                            }
                        }
                    }
                    winCondition1(row, col, diagonal1);
                }
                printCard1();
                toss++;
                sum1 = col + row + diagonal1;
                cout << "\nPoints: " << sum1 << endl;
                system("pause");
            }

            else
            {
                winCondition2(row2, col2, diagonal2);
                sum2 = col2 + row2 + diagonal2;
                if (sum2 < 5)
                {
                    cout << player2 << " YOUR BINGO CARD IS :" << endl;
                    printCard2();
                    int num2;
                    cout << player2 << " " << "ENTER NUMBER BETWEEN 1-25" << endl;
                    cin >> num2;

                    while (num2 > 25 || num2 < 1)
                    {
                        cout << "\n Invalid card entry .Try Again :";
                        cin >> num2;
                    }
                    for (int i = 0; i < 5; i++)
                    {

                        for (int j = 0; j < 5; j++)
                        {

                            if (card2[i][j] == num2)
                            {

                                card2[i][j] = 0;
                            }
                            if (card1[i][j] == num2)
                            {

                                card1[i][j] = 0;
                            }
                        }
                    }
                    winCondition2(row2, col2, diagonal2);
                }
                printCard2();
                sum2 = col2 + row2 + diagonal2;
                toss++;
                cout << "\nPoints:" << sum2 << endl;
                system("pause");
            }
            if (sum1 >= 5 || sum2 >= 5)
            {
                if (sum1 >= 5)
                {
                    cout << "CONGRATS " << player1 << " " << " .YOU WIN THE BINGO GAME!!!!" << endl;
                    sum1 = 10;
                    system("pause");
                    system("CLS");
                }
                else if (sum2 >= 5)
                {
                    cout << "CONGRATS " << player2 << " " << " .YOU WIN THE BINGO GAME!!!!" << endl;
                    sum2 = 10;
                    system("pause");
                    system("CLS");
                }
                ofstream fout;
                fout.open("Game History.txt", ios::app);
                if (!fout.is_open())
                {
                    cout << "\n File can't be opened to save game history";
                }
                else
                {
                    fout << "\nGame ID is " << gameId << endl;
                    fout << player1 << " vs " << player2 << endl;
                    ;
                    if (sum1 > sum2)
                        fout << player1 << " won the game" << endl;
                    else
                        fout << player2 << " won the game" << endl;
                }
                fout.close();
                goto label;
            }
            system("CLS");
        }
    }
    else if (choice == 0)
    {
        cout << "HOPE YOU WILL PLAY NEXT TIME";
    }
    system("pause");

    return 0;
}
void winCondition1(int &row, int &col, int &diagonal1)
{
    row = 0;
    col = 0;
    diagonal1 = 0;
    for (int i = 0; i < 5; i++)
    {
        if (card1[i][0] == 0 && card1[i][1] == 0 && card1[i][2] == 0 && card1[i][3] == 0 && card1[i][4] == 0)
        {
            row++;
        }
    }
    for (int j = 0; j < 5; j++)
    {
        if (card1[0][j] == 0 && card1[1][j] == 0 && card1[2][j] == 0 && card1[3][j] == 0 && card1[4][j] == 0)
        {
            col++;
        }
    }
    if (card1[0][0] == 0 && card1[1][1] == 0 && card1[2][2] == 0 && card1[3][3] == 0 && card1[4][4] == 0)
    {
        diagonal1++;
    }
    if (card1[4][0] == 0 && card1[3][1] == 0 && card1[2][2] == 0 && card1[1][3] == 0 && card1[0][4] == 0)
    {
        diagonal1++;
    }
    return;
}
void winCondition2(int &row2, int &col2, int &diagonal2)
{
    row2 = 0;
    col2 = 0;
    diagonal2 = 0;
    for (int i = 0; i < 5; i++)
    {
        if (card2[i][0] == 0 && card2[i][1] == 0 && card2[i][2] == 0 && card2[i][3] == 0 && card2[i][4] == 0)
        {

            row2++;
        }
    }

    for (int j = 0; j < 5; j++)
    {
        if (card2[0][j] == 0 && card2[1][j] == 0 && card2[2][j] == 0 && card2[3][j] == 0 && card2[4][j] == 0)
        {
            col2++;
        }
    }

    if (card2[0][0] == 0 && card2[1][1] == 0 && card2[2][2] == 0 && card2[3][3] == 0 && card2[4][4] == 0)
    {
        diagonal2++;
    }

    if (card2[4][0] == 0 && card2[3][1] == 0 && card2[2][2] == 0 && card2[1][3] == 0 && card2[0][4] == 0)
    {
        diagonal2++;
    }
    return;
}
void printCard1()
{
    for (int i = 0; i < 5; i++) // printing card of player 1
    {
        cout << "|............................|\n|";
        for (int j = 0; j < 5; j++)
        {
            cout << setw(3) << card1[i][j] << " | ";
        }
        cout << endl;
    }
    cout << "|............................|\n|";
    return;
}
void printCard2()
{
    for (int i = 0; i < 5; i++) // printing card of player 1
    {
        cout << "|............................|\n|";
        for (int j = 0; j < 5; j++)
        {
            cout << setw(3) << card2[i][j] << " | ";
        }
        cout << endl;
    }
    cout << "|............................|\n|";
    return;
}

void printMenu()
{
    system("CLS");
    cout << "\t\t\t\t\t\tBINGO GAME coded by Error 404" << endl;
    cout << "\t\t\t\t\t\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
    cout << "\n\t MAIN MENU ";
    cout << "\n1.INSTRUCTIONS";
    cout << "\n2.PLAY THE GAME";
    cout << "\n3.CREDITS";
    cout << "\n4.GAME HISTORY";
    cout << "\n5.EXIT";
    cout << endl;
    cout << "Enter Menu Input :";
    cin >> choice;
    while (choice < 1 || choice > 4)
    {
        cout << "\n Invalid Menu Input .Try Again : ";
        cin >> choice;
    }
    switch (choice)
    {
    case 1:
    {
        choice = 1;
        instructions();
        return;
    }

    case 2:
    {
        choice = 2;
        return;
    }
    case 3:
    {
        choice = 3;
        credits();
        return;
    }
    case 4:
    {
        choice = 4;
        gameHistory();
        return;
    }
    case 5:
    {
        choice = 0;
        return;
    }
    }
}
void instructions()
{
    system("CLS");
    int l = 0;
    cout << "\n \t\t\t\t INSTRUCTIONS";
    cout << "\n1.It is  a two-player game.";
    cout << "\n2.Both users will be provided with bingo cards of 5 rows and 5 columns with random number";
    cout << "\n3.Randomly one player starts the game and enter a number between 1 to 25";
    cout << "\n4.The number entered will be replaced by 0 in both cards";
    cout << "\n5.First user to get five  0's in 5 columns,rows or diagonal wins the game . ";
    cout << "\n\n\t\tSAMPLE CARD \n";
    for (int i = 0; i < 5; i++) // printing card of player 1
    {
        cout << "|............................|\n|";
        for (int j = 0; j < 5; j++)
        {
            cout << setw(3) << l << " | ";
            ++l;
        }
        cout << endl;
    }
    cout << "|............................|\n|";
    cout << "\n\n \t\tTip:Choose your numbers wisely\n";
    system("pause");
    printMenu();
}
void credits()
{
    system("CLS");
    cout << "\n\t\t\t\t CREDITS ";
    cout << "\nBingo coded by ERROR 404\n\n\n ";
    cout << "\n\tAlgorithm and flowchart by : Rafay";
    cout << "\n\tLogic and checks by : Rafay";
    cout << "\n\tGame coded by : Rafay";
    system("pause");
    printMenu();
}
void gameHistory()
{
    system("CLS");
    ifstream fin;
    string output;
    fin.open("Game History.txt");
    if (!fin.is_open())
        cout << "\n Game History file can't be opened ";
    else
    {
        while (!fin.eof())
        {
            getline(fin, output);
            cout << output << endl;
        }
    }
    system("pause");
    printMenu();
}
void funcgameid()
{
    srand(time(0));
    gameId = (rand() % 1000) + 10000;
    cout << "GAME ID : " << gameId;
    cout << endl;
}

bool isNumberNulled(int num)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (card1[i][j] == num || card2[i][j] == num)
            {
                return false; // Number exists and is valid (not nulled)
            }
        }
    }
    return true; // Number is already nulled (0) in both cards
}