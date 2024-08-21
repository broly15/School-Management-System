#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to check if T is a subsequence of str
bool isSubsequence(const string &str, const string &T)
{
    int m = T.length();
    int n = str.length();
    int j = 0; // Pointer for T

    // Traverse str and check if T is a subsequence of str
    for (int i = 0; i < n && j < m; ++i)
    {
        if (str[i] == T[j])
        {
            ++j;
        }
    }

    return j == m;
}

// Function to find the maximum length of k
int getMaxLength(int N, int M, const string &S, const string &T)
{
    int maxLength = 0;

    // Check all substrings of S
    for (int start = 0; start < N; ++start)
    {
        for (int end = start; end < N; ++end)
        {
            string substr = S.substr(start, end - start + 1);
            if (isSubsequence(substr, T))
            {
                maxLength = max(maxLength, (int)substr.length());
            }
        }
    }

    return maxLength;
}

int main()
{
    int N, M;
    string S, T;

    // Input
    cin >> N >> M;
    cin >> S >> T;

    // Find and output the result
    cout << getMaxLength(N, M, S, T) << endl;

    return 0;
}