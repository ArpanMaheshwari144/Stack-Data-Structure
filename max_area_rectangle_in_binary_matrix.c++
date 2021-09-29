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

vector<int> NSL(vector<int> arr, int n)
{
    vector<int> left;

    // stack pair ka banega jisme elements or unki index store hongi jiska first element and second index hoga
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

vector<int> NSR(vector<int> arr, int n)
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

int maxAreaHistogram(vector<int> arr)
{
    int n = arr.size();
    if (n <= 0)
    {
        return 0;
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
    return mx;
}

void maxAreaRectangleInBinaryMatrix(int arr[R][C])
{
    vector<int> v;
    for (int j = 0; j < C; j++)
    {
        v.push_back(arr[0][j]);
    }
    int mx = maxAreaHistogram(v);

    for (int i = 1; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (arr[i][j] == 0)
            {
                v[j] = 0;
            }
            else
            {
                v[j] = v[j] + arr[i][j];
            }
        }
        mx = max(mx, maxAreaHistogram(v));
    }
    cout << "Maximum area of rectangle in a binary matrix is " << mx;
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