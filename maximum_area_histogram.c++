/*Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have same width and the width is 1 unit.
For example, consider the following histogram with 7 bars of heights {6, 2, 5, 4, 5, 1, 6}. The largest possible rectangle possible is 12 (see the below figure, the max area rectangle is highlighted in red)*/
#include <bits/stdc++.h>
using namespace std;

vector<int> NSL(int arr[], int n)
{
    vector<int> left;

    // stack pair ka banega jisme elements or unki index store hongi like first element hoga and second index hoga
    stack<pair<int, int>> s;
    int pseudoIndex = -1;

    for (int i = 0; i < n; i++)
    {
        if (s.size() == 0)
        {
            left.push_back(pseudoIndex);
        }
        else if (s.size() > 0 && s.top().first < arr[i]) // compare hum stack mei elements se hi karenge
        {
            left.push_back(s.top().second); // vector mei push hum iss baar index ko karenge
        }
        else if (s.size() > 0 && s.top().first >= arr[i])
        {
            while (s.size() > 0 && s.top().first >= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                left.push_back(pseudoIndex);
            }
            else
            {
                left.push_back(s.top().second);
            }
        }
        s.push({arr[i], i}); // stack mei push karenge elements or unki index
    }
    return left;
}

vector<int> NSR(int arr[], int n)
{
    vector<int> right;

    // stack pair ka banega jisme elements or unki index store hongi jiska first element and second index hoga
    stack<pair<int, int>> s;
    int pseudoIndex = n;

    for (int i = n - 1; i >= 0; i--)
    {
        if (s.size() == 0)
        {
            right.push_back(pseudoIndex);
        }
        else if (s.size() > 0 && s.top().first < arr[i]) // compare hum stack mei elements se hi karenge
        {
            right.push_back(s.top().second); // vector mei push hum iss baar index ko karenge
        }
        else if (s.size() > 0 && s.top().first >= arr[i])
        {
            while (s.size() > 0 && s.top().first >= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                right.push_back(pseudoIndex);
            }
            else
            {
                right.push_back(s.top().second);
            }
        }
        s.push({arr[i], i}); // stack mei push karenge elements or unki index
    }
    reverse(right.begin(), right.end());

    return right;
}

void maxAreaHistogram(int arr[], int n)
{
    if (n <= 0)
    {
        cout << "Please enter some elements in the array";
        exit(0);
    }

    vector<int> left = NSL(arr, n);
    vector<int> right = NSR(arr, n);

    int width[n], area[n];
    for (int i = 0; i < n; i++)
    {
        width[i] = right[i] - left[i] - 1;
        area[i] = arr[i] * width[i];
    }

    int mx = area[0];
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, area[i]);
    }
    cout << "Maximum area is " << mx;
}

int main()
{
    int arr[] = {6, 2, 5, 4, 5, 1, 6}; // This array denotes the height of the particular buildings
    // int arr[] = {}; // This array denotes the height of the particular buildings
    int n = sizeof(arr) / sizeof(arr[0]);

    maxAreaHistogram(arr, n);

    return 0;
}