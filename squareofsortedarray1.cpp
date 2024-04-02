/*
vector < int > sqsorted(vector < int > & arr) {
    int n = arr.size();

    // This array will store the resulting array.
    vector < int > ans(n);

    int pos = n - 1;

    // Starting and ending pointers.
    int st = 0;
    int  end = n - 1;

    while (pos >= 0) {
        if (abs(arr[st]) > abs(arr[end])){
            ans[pos] = arr[st] * arr[st];
            st++;
        }
        else {
            ans[pos] = arr[end] * arr[end];
            end--;
        }
        pos--;
    }    
    return ans;
}

*/