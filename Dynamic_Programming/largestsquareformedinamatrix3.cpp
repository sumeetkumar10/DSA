#include <iostream>
#include <vector>
using namespace std;

int solve(vector<vector<int>> &mat, int &maxi)
{
    int row = mat.size();
    int col = mat[0].size();

    vector<int> curr(col+1,0);
    vector<int> next(col+1,0);

    for (int i = row - 1; i >= 0; i--)
    {
        for (int j = col - 1; j >= 0; j--)
        {
            int right = curr[j + 1];
            int down = next[j];
            int diagonal = next[j + 1];

            if (mat[i][j] == 1)
            {
                curr[j] = 1 + min(right, min(down, diagonal));
                maxi = max(maxi, curr[j]);
            }
            else
            {
                curr[j] = 0;
            }
        }
        next=curr;
    }
    return next[0];
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

    vector<vector<int>> matrix = {{0,0},
                                  {0,0}};

    cout << "The largest square formed in the matrix is " << maxSquare(n, m, matrix);

    return 0;
}