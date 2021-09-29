/*Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
Input: arr[]   = {2, 0, 2}
Output: 2
Structure is like below
\  \
\__\
We can trap 2 units of water in the middle gap.

Input: arr[]   = {3, 0, 0, 2, 0, 4}
Output: 10
Structure is like below
      \
\     \
\  \  \
\__\__\ 
We can trap "3*2 units" of water between 3 and 2,
"1 unit" on top of bar 2 and "3 units" between 2 
and 4.*/
#include <bits/stdc++.h>
using namespace std;

void rainWaterTrapping(int arr[], int n)
{
    int maxLeftArray[n], maxRightArray[n];

    // Maximum from left array
    maxLeftArray[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxLeftArray[i] = max(maxLeftArray[i - 1], arr[i]);
    }

    // Maximum from right array
    maxRightArray[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        maxRightArray[i] = max(maxRightArray[i + 1], arr[i]);
    }

    // Take min from left array and right array and subtract the i'th array value
    int water[n];
    for (int i = 0; i < n; i++)
    {
        water[i] = min(maxLeftArray[i], maxRightArray[i]) - arr[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + water[i];
    }

    cout << "Maximum water that can be accumulated is " << sum;
}

int main()
{
    int arr[] = {3, 0, 0, 2, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    rainWaterTrapping(arr, n);

    return 0;
}