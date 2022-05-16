#define N 10
#include<iostream>
using namespace std;


bool isValid(int board[N][N], int row, int col)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])  return false;

    for (i = 0; i < row; i++)
        if (board[i][col])  return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])    return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])    return false;

    return true;
}

bool Find_Place(int board[N][N], int col)
{
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (isValid(board, i, col)) {
            board[i][col] = 1;

            if (Find_Place(board, col + 1))
                return true;

            board[i][col] = 0; 
        }
    }

    return false;
}

bool N_Q()
{
    int board[N][N];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            board[i][j] = 0;
        }
    }

    if (Find_Place(board, 0) == false) {
        printf("Solution does not exist");
        return false;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++){
            if(board[i][j] == 1){
                cout << "👸" << " ";
            }
            else{
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
    }
    return true;
}

int main()
{
    if(N_Q()==false){
        cout<<"No solution found" << endl;
    };
    return 0;
}