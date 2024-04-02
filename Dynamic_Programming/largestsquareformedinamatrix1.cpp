#include <iostream>
#include <vector>
using namespace std;

int solve(vector<vector<int>> &mat, int i, int j, int &maxi,vector<vector<int>>& dp)
{
    if (i >= mat.size() || j >= mat[0].size())
    {
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int right = solve(mat, i, j + 1, maxi,dp);
    int down = solve(mat, i + 1, j, maxi,dp);
    int diagonal = solve(mat, i + 1, j + 1, maxi,dp);

    if (mat[i][j] == 1)
    {
        dp[i][j] = 1 + min(right, min(down, diagonal));
        maxi = max(maxi, dp[i][j]);
        return dp[i][j];
    }
    else
    {
        return dp[i][j]=0;
    }
}

int maxSquare(int n, int m, vector<vector<int>> &mat)
{
    int maxi = 0;
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return solve(mat, 0, 0, maxi,dp);
}

int main()
{
    int n = 2;

    int m = 2;

    vector<vector<int>> matrix = {{1,1},
                                  {1,1}};

    cout << "The largest square formed in the matrix is " << maxSquare(n, m, matrix);

    return 0;
}