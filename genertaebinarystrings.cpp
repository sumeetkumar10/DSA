#include <iostream>
#include <vector>
#include <string>
using namespace std;

void generateBinaryStrings(int n, string current, vector<string>& result) {
    if (n == 0) {
        result.push_back(current);
        return;
    }
    if (current.empty() || current.back() != '1') {
        generateBinaryStrings(n - 1, current + '1', result);
    }
    generateBinaryStrings(n - 1, current + '0', result);
}

vector<string> binaryStrings(int N) {
    vector<string> result;
    generateBinaryStrings(N, "", result);
    return result;
}

int main() {
    int N = 3;
    vector<string> result = binaryStrings(N);
    for (const string& s : result) {
        cout << s << endl;
    }
    return 0;
}