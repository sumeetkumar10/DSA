#include <iostream>
#include <vector>
using namespace std;

void getProductArrayExceptSelf(int *arr, int n)
{
    int mod = 1e9 + 7;

    int *ans = new int[n];

    for (int i = 0; i < n; i++)
    {

        ans[i] = 1;
    }

    int left = 1, right = 1;

    for (int i = 0, j = n - 1; i < n - 1; i++, j--)
    {

        left = (left * arr[i]) % mod;

        right = (right * arr[j]) % mod;

        ans[i + 1] = (ans[i + 1] * left) % mod;

        ans[j - 1] = (ans[j - 1] * right) % mod;
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array you want to create" << endl;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    getProductArrayExceptSelf(arr, n);

    return 0;
}