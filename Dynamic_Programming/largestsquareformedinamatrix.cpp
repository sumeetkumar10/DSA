#include <iostream>
#include <vector>
using namespace std;

int solve(vector<vector<int>> &mat, int i, int j, int &maxi)
{
    if (i >= mat.size() || j >= mat[0].size())
    {
        return 0;
    }

    int right = solve(mat, i, j + 1, maxi);
    int down = solve(mat, i + 1, j, maxi);
    int diagonal = solve(mat, i + 1, j + 1, maxi);

    if (mat[i][j] == 1)
    {
        int ans = 1 + min(right, min(down, diagonal));
        maxi = max(maxi, ans);
        return ans;
    }
    else
    {
        return 0;
    }
}

int maxSquare(int n, int m, vector<vector<int>> &mat)
{
    int maxi = 0;
    int ans = solve(mat, 0, 0, maxi);
    return ans;
}

int main()
{
    int n = 2;

    int m = 2;

    vector<vector<int>> matrix = {{1, 1},
                                  {1, 1}};

    cout << "The largest square formed in the matrix is " << maxSquare(n, m, matrix);

    return 0;
}