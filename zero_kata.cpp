// A game of Tic-Tac-Toe. No more wasting the back side of the book xd :)

#include <iostream>
#include <string>

using namespace std;

// Initialize the game board
char space[3][3] = {{'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}};

// Variables to store player names
string n1 = "";
string n2 = "";

// Flags to track game state
bool draw = false;

// Variables to store the current row and column
int row;
int column;

// Token to determine the current player ('x' or 'o')
char token = 'x';

// Function to display the Tic Tac Toe board
void tTt()
{
    cout << "   |    |   " << endl;
    cout << " " << space[0][0] << " |  " << space[0][1] << " |  " << space[0][2] << endl;
    cout << "___|____|___" << endl;
    cout << "   |    |   " << endl;
    cout << " " << space[1][0] << " |  " << space[1][1] << " |  " << space[1][2] << endl;
    cout << "___|____|___" << endl;
    cout << "   |    |   " << endl;
    cout << " " << space[2][0] << " |  " << space[2][1] << " |  " << space[2][2] << endl;
    cout << "   |    |   " << endl;
}

// Function to handle player moves and update the board
void check()
{
    int digit;
    // Prompt the current player for their move
    if (token == 'x')
    {
        cout << n1 << ", please enter: ";
        cin >> digit;
    }
    else if (token == 'o')
    {
        cout << n2 << ", please enter: ";
        cin >> digit;
    }

    // Determine the row and column based on the player's input
    switch (digit)
    {
    case 1:
        row = 0;
        column = 0;
        break;
    case 2:
        row = 0;
        column = 1;
        break;
    case 3:
        row = 0;
        column = 2;
        break;
    case 4:
        row = 1;
        column = 0;
        break;
    case 5:
        row = 1;
        column = 1;
        break;
    case 6:
        row = 1;
        column = 2;
        break;
    case 7:
        row = 2;
        column = 0;
        break;
    case 8:
        row = 2;
        column = 1;
        break;
    case 9:
        row = 2;
        column = 2;
        break;
    default:
        // Handle invalid input
        cout << "INVALID INPUT" << endl;
        check();
        return;
    }

    // Check if the selected space is already taken
    if (space[row][column] != 'x' && space[row][column] != 'o')
    {
        // Update the board with the current player's token
        space[row][column] = token;
        // Switch the token for the next player
        token = (token == 'x') ? 'o' : 'x';
    }
    else
    {
        // Prompt the player to choose another space if the selected one is taken
        cout << "There is no empty space" << endl;
        check();
    }

    // Display the updated board
    tTt();
}

// Function to check for a winning condition or a draw
bool pairing()
{
    // Check for a win in rows and columns
    for (int i = 0; i < 3; i++)
    {
        if ((space[i][0] == space[i][1] && space[i][0] == space[i][2]) ||
            (space[0][i] == space[1][i] && space[0][i] == space[2][i]))
        {
            return true;
        }
    }

    // Check for a win in diagonals
    if ((space[0][0] == space[1][1] && space[1][1] == space[2][2]) ||
        (space[0][2] == space[1][1] && space[1][1] == space[2][0]))
    {
        return true;
    }

    // Check for a draw (if all spaces are filled)
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (space[i][j] != 'x' && space[i][j] != 'o')
            {
                return false; // If there's an empty space, continue playing
            }
        }
    }

    // If no empty spaces and no win, it's a draw
    draw = true;
    return false;
}

int main()
{
    // Get player names
    cout << "Enter the name of the first player: " << endl;
    getline(cin, n1);
    cout << "Enter the name of the second player: " << endl;
    getline(cin, n2);

    // Announce the players and their turn order
    cout << n1 << " is player 1 so they will move first" << endl;
    cout << n2 << " is player 2 so they will move second" << endl;

    // Main game loop
    while (!pairing())
    {
        // Display the current board and prompt the current player for their move
        tTt();
        check();
    }

    // Announce the result of the game
    if (draw)
    {
        cout << "It's a DRAW!!" << endl;
    }
    else if (token == 'o')
    {
        cout << n1 << " WINS!!" << endl; // If 'o' was supposed to play next, 'x' won
    }
    else if (token == 'x')
    {
        cout << n2 << " WINS!!" << endl; // If 'x' was supposed to play next, 'o' won
    }

    return 0;
}
