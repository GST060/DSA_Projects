#include <bits/stdc++.h>
using namespace std;

bool SafeHai(int a[][9], int i, int j, int no, int n)
{
    //1. no. row ya column mei nahi hona chahiye
    for (int k = 0; k < n; k++)
    {
        if (a[k][j] == no || a[i][k] == no)
        {
            return false;
        }
    }
 
    // 2. no. current 3*3 wale matrix mei nhi hona chahiye
    n = sqrt(n); // n ab sqrt of n kr diya hai
    int si = (i / n) * n;
    int sj = (j / n) * n;

    for (int r = si; r < si + n; r++)
    {
        for (int c = sj; c < sj + n; c++)
        {
            if (a[r][c] == no)
                return false;
        }
    }

    // agar number upar 2 mei nahi hai, toh rakhna safe hai
    return true;
}

bool SudokuSolver(int a[][9], int i, int j, int n)
{
    // base case
    if (i == n)
    {
        // Print the Sudoku
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                cout << a[r][c] << " ";
            }
            cout << endl;
        }

        // Sudoku Solve ho gaya toh enjoy
        return true;
    }

    // Recursive case se pehele 2 cheeze check krna jarrori hai

    // 1. Agar j==n ho gaya toh bhai agli row par jaao and col-->0 par jaao
    if (j == n)
    {
        bool SolveHuaBaaki = SudokuSolver(a, i + 1, 0, n);
        return SolveHuaBaaki;
    }

    // 2. Cell empty nhi hai, toh isse fill nahi karna , choti problem mei tod do aur
    if (a[i][j] != 0)
    {
        bool SolveHuaBaaki = SudokuSolver(a, i, j + 1, n);
        return SolveHuaBaaki;
    }

    // Agar upar ki dono cheeze theek hai toh mtlb mei empty cell par hoon, uska kaam karo

    // Recursive case

    //Sare Empty cell fill karna --> Ek empty cell mei fill kr deta hoon, Baaki Recursion krega
    // Ek empty cell par hum 1-N tak number fill kr skte hai
    for (int no = 1; no <= n; no++)
    {
        // Current no. rakhna safe hai ya nahi pehle yeh check karna hai
        if (SafeHai(a, i, j, no, n) == true)
        {
            // if number rakhna safe hai to rakhdo
            a[i][j] = no;

            // Ab baaki ka kaam recursion ko boldo
            bool ans = SudokuSolver(a, i, j + 1, n);
            if (ans == true)
            {
                return true;
            }
            
            // if recursion baaki solve nhi kr paaya, therefore no. rakhna galat hai
            a[i][j] = 0; // Backtracking
        }
    }

    // 1-N tak koi bhi number i,j par place nhi hota, that is loop se bahar aa gaye
    return false; // current empty cell fill krna possible nhi hai
}

int main()
{
    int a[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9}

    };
    SudokuSolver(a,0,0,9);

    return 0;
}
