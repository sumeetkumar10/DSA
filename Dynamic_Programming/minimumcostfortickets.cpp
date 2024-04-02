#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &days, vector<int> &costs, int index)
{
    int n = days.size();

    if (index >= n)
    {
        return 0;
    }

    // 1 day pass
    int op1 = costs[0] + solve(days, costs, index + 1);

    int i;
    // 7 days pass
    for (i = index; i < n && days[i] < days[index] + 7; i++)
        ;

    int op2 = costs[1] + solve(days, costs, i);

    // 30 days pass
    for (i = index; i < n && days[i] < days[index] + 30; i++)
        ;

    int op3 = costs[2] + solve(days, costs, i);

    return min(op1, min(op2, op3));
}

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    return solve(days, costs, 0);
}

int main()
{
    vector<int> days = {1,4,6,7,8,20};

    vector<int> costs = {2,7,15};

    cout<<"The minimum cost for tickets is "<<mincostTickets(days,costs)<<endl;

    return 0;
}