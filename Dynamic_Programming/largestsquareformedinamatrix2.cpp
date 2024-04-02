#include <iostream>
#include <vector>
using namespace std;

int solve(vector<vector<int>> &mat, int &maxi)
{
    int row = mat.size();
    int col = mat[0].size();

    vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));

    for (int i = row - 1; i >= 0; i--)
    {
        for (int j = col - 1; j >= 0; j--)
        {
            int right = dp[i][j + 1];
            int down = dp[i + 1][j];
            int diagonal = dp[i + 1][j + 1];

            if (mat[i][j] == 1)
            {
                dp[i][j] = 1 + min(right, min(down, diagonal));
                maxi = max(maxi, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return dp[0][0];
}

int maxSquare(int n, int m, vector<vector<int>> &mat)
{
    int maxi = 0;
    int ans=solve(mat, maxi);
    return ans;
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