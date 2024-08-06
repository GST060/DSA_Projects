#include <bits/stdc++.h>
using namespace std;

bool ratInMAze(char maze[][5], int i, int j, int n, int m, int sol[][10])
{
    // base case
    if (i == n - 1 and j == m - 1)
    {
        // Destination bhi solution ka part hogi
        sol[i][j] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return false;//Mill gayi hai,phir bhi mei bol raha hu nahi milli
        //return true; //Base case se return true,kyuki destination reached
    }

    // Recursive case
    // Jaha khado ho usse sol ka part maanlo
    sol[i][j] = 1;

    // Right mei jaakar dekho maze solve hoti hai ya nahi hoti
    if (j + 1 < m and maze[i][j + 1] != 'X')
    {
        bool rigthSeRaastaMilla = ratInMAze(maze, i, j + 1, n, m, sol);
        if (rigthSeRaastaMilla == true)
        {
            // Agar right se maze solve ho gayi, toh return true kardo
            return true;
        }
    }

    // Right se nahi milla toh neeche se dekh jaakar
    if (i + 1 < n and maze[i + 1][j] != 'X')
    {
        bool neecheSeRaastaMilla = ratInMAze(maze, i + 1, j, n, m, sol);
        if (neecheSeRaastaMilla == true)
        {
            return true;
        }
    }

    // Naa right se milla , na neeche se milla
    sol[i][j] = 0; // Backtracking
    return false;
}

int main()
{
    char maze[][5] = {
        "0000",
        "00XX",
        "0000",
        "XX00"};
    int sol[10][10] = {0};
    ratInMAze(maze, 0, 0, 4, 4, sol);
    return 0;
}
