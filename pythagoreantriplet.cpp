/*
        Time Complexity : O(N^3)
        Space Complexity : O(1),

        where N = number of elements in the array.
 */
/*
bool check(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {

            for (int k = j + 1; k < n; k++) {

                // a is the least element among the three
                int a = min({arr[i], arr[j], arr[k]});

                // b is the maximum element among the three
                int b = max({arr[i], arr[j], arr[k]});

                // Using xor operation, we can find the middle element as a^a = 0
                int c = a ^ b ^ arr[i] ^ arr[j] ^ arr[k];
                if (a * a + c * c == b * b) {
                    return true;
                }

            }
        }
    }
    return false;
}
*/


/*
        Time Complexity : O(M^2)
        Space Complexity : O(N),

        where N = number of elements in the array.
              M = maximum element in the array
 */
/*
#include <math.h>

bool check(vector<int> &arr) {
    int n = arr.size();


    int mx = *max_element(arr.begin(), arr.end());

    // You can use a hashmap, hashset etc. also to store the frequencies
    int freq[mx + 1] = {0};
    for (auto it : arr) {
        freq[it]++;
    }

    for (int i = 1; i <= mx; i++) {

        // If the number is not present, continue
        if (freq[i] == 0) {
            continue;
        }

        for (int j = 1; j <= mx; j++) {
            if ((i == j && freq[i] <= 1) || freq[j] == 0) {
                continue;
            }

            int val = sqrt(i * i + j * j);

            // Calculate the square root , and check if it is present in the hashmap or not
            if (val > mx) {
                continue;
            }

            if (val * val == (i * i + j * j) && freq[val] >= 1) {

                return true;
            }

        }
    }
    return false;
}*/

/*
        Time Complexity : O(N^2)
        Space Complexity : O(1),

        where N = number of elements in the array.
 */
/*
bool check(vector<int> &arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());

    // Start from 3rd element of the array to look for a possible candidate of 'c'
    for (int i = 2; i < n; i++) {

        // calculate c^2
        int rhs = arr[i] * arr[i];
        int j = 0, k = i - 1;
        while (j < k) {
            int lhs = arr[j] * arr[j] + arr[k] * arr[k];
            if (lhs == rhs) {
                return true;
            }
            // If the sum > c^2, then we need to look for a smaller 'b' , thus we decrement 'k pointer
            else if (lhs > rhs) {
                k--;
            }
            // If the sum < c^2, then we need to look for a larger 'a' , thus we increment 'j pointer
            else {
                j++;
            }
        }

    }

    return false;
}*/