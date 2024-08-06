#include <bits/stdc++.h>
using namespace std;

bool Safehai(int board[][100], int r, int c, int n)
{
    //1. Column mei raani nhi honi chahiye
    for (int i = 0; i < r; i++)
    {
        if (board[i][c] == 1)
        {
            return false;// Agar same column mei raani hai toh,r,c,mei raani nhi rakh skte
        }
    }
     
     // 2. upper left and upper right diagonal par raani nhi honi chahiye
    int copy_r = r, copy_c = c;

    //Upper right Diagonal
    while (r >= 0 && c < n)
    {
        if (board[r][c] == 1)
        {
            return false;
        }
        r--;
        c++;
    }
    r = copy_r;
    c = copy_c;

    //Check upper left diagonal
    while (r >= 0 && c >= 0)
    {
        if (board[r][c] == 1)
        {
            //Ab boldo safe hai, rakhlo raani on r,c cell par
            return false;
        }
        r--;
        c--;
    }

    return true;
}

bool NQueen(int board[][100], int r, int n)
{
    // base case
    if (r == n)
    {
        //Agar saari raani place ho gai, toh base case
        //Ab user ko batado kaha raani place hui hai, i.e. board ko print krdo
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                board[i][j] == 1 ? cout << "Q" : cout << "_";
            }
            cout << endl;
        }

        //Saari rani place ho gayi, therefore return true;
        return true;
    }

    // Recursive case
    for (int c = 0; c < n; c++)
    {
        //Pehle check karo r,c safe hai queen rakhne ke liye
        if (Safehai(board, r, c, n))
        {
            //If safe hai toh rakho
            board[r][c] = 1;// Queen place krdi r,c par

            //Recursive ko bolo baaki ka tu bata de place hui ya nahi
            bool ans = NQueen(board, r + 1, n);

            // Agar baaki place ho gai, ans==true aaega is case mai
            if (ans == true)
            {
                return true;//Badhai ho, bann gai baat
            }

            //Agar ans false aaya, toh baat nahi bani, jo rani rakhi hai
            //Usse jaldi waha se hatao
            board[r][c] = 0; //Backtracking karna 
        }
    }

    //loop ke bahar aa gaye, matlab kisi bhi column par raani nhi rakh paye
    return false; // Currnet row mei raani rakhna possible nhi hai
}

int main()
{
    int board[100][100] = {0};  //Har bucket par zero daalo, zero represents queen nhi hai
    int n;
    cin >> n;
    NQueen(board, 0, n);

    return 0;
}
