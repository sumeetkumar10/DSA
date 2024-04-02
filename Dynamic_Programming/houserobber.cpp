#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &nums, int n, vector<int> &dp)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return nums[0];
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int incl = solve(nums, n - 2, dp) + nums[n];
    int excl = solve(nums, n - 1, dp) + 0;

    dp[n] = max(incl, excl);
    return dp[n];
}

int rob(vector<int> &nums)
{
    int n = nums.size();

    vector<int> dp(n, -1);

    vector<int> first, second;

    for (int i = 0; i < n - 1; i++)
    {
        if (i != n - 1)
        {
            first.push_back(nums[i]);
        }
        if (i != 0)
        {
            second.push_back(nums[i]);
        }
    }
    return max(solve(first, n - 1, dp), solve(second, n - 1, dp));
}

int main()
{

    return 0;
}