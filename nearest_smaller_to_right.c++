/*Given an array of integers, find the closest (not considering distance, but value) smaller on right of every element. If an element has no smaller on the right side, print -1.*/
#include <bits/stdc++.h>
using namespace std;

void nextSmallestElementToRight(int arr[], int n)
{
    vector<int> v;
    stack<int> s;

    for (int i = n - 1; i >= 0; i--)
    {
        if (s.size() == 0)
        {
            v.push_back(-1);
        }
        else if (s.size() > 0 && s.top() < arr[i])
        {
            v.push_back(s.top());
        }
        else if (s.size() > 0 && s.top() >= arr[i])
        {
            while (s.size() > 0 && s.top() >= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    reverse(v.begin(), v.end());

    cout << "\nThe nearest smallest element to right for all the values in the array is: \n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << arr[i] << " --> " << v[i] << endl;
    }
}

int main()
{
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    nextSmallestElementToRight(arr, n);

    return 0;
}