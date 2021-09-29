/*Given a binary matrix, find the maximum size rectangle binary-sub-matrix with all 1’s.
Example:

Input :   0 1 1 0
          1 1 1 1
          1 1 1 1
          1 1 0 0

Output :  1 1 1 1
          1 1 1 1*/
#include <bits/stdc++.h>
using namespace std;

#define R 100
#define C 100
#define n 100
#define m 100

void maxAreaRectangleInBinaryMatrix(int arr[R][C])
{
    int dp[n + 1][m + 1];
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0)
            {
                dp[i][j] = arr[i][j] == 1 ? 1 : 0;
            }
            else
            {
                dp[i][j] = arr[i][j] == 1 ? (dp[i - 1][j] + 1) : 0;
            }
            int min = dp[i][j];
            for (int k = j; k >= 0; k--)
            {
                if (min == 0)
                {
                    break;
                }
                if (dp[i][k] < min)
                {
                    min = dp[i][k];
                }
                maxArea = max(maxArea, min * (j - k + 1));
            }
        }
    }
    cout << "Maximum area of rectangle in a binary matrix is " << maxArea;
}

int main()
{
    int arr[R][C] = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0},
    };

    maxAreaRectangleInBinaryMatrix(arr);

    return 0;
}