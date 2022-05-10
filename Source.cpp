#include <iostream>

/*ici on définie la taile du plateau et le nombre de reine a poser*/
#define X 8


using namespace std;

/* ici on print la sollution */
void Solution(int board[X][X])
{
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < X; j++)
            cout << " " << board[i][j] << " ";
        printf("\n");
    }
}

/*  ici on teste si la reine peut etre placé sans etre mangée */
bool Safe(int board[X][X], int row, int col)
{
    int i, j;

    /* on verifie a gauche */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    /* on verifie la diagonale a gauche */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    /* on verifie la diagonale a droite */
    for (i = row, j = col; j >= 0 && i < X; i++, j--)
        if (board[i][j])
            return false;

    return true;
}


bool solution(int board[X][X], int col)
{
    /* ci toute les reines sont placée, sa fait vrais */
    if (col >= X)
        return true;

    /* ici on place la rene sur les colones et on verifie une par une */
    for (int i = 0; i < X; i++) {
        if (Safe(board, i, col)) {
            board[i][col] = 1;

            if (solution(board, col + 1))
                return true;

            /* si la reine placée ne donne pas de solution alors on l'enlève */
            board[i][col] = 0;
        }
    }

    /* si la reine ne peut etre placer ici, sa fait False */
    return false;
}

bool solveNQ()
{
    int board[X][X] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };

    if (solution(board, 0) == false) {
        cout << "la solution n'existe pas";
        return false;
    }

    Solution(board);
    return true;
}

// driver program to test above function
int main()
{
    solveNQ();
    return 0;
}