/*Given an array of integers, find the closest (not considering distance, but value) smaller on left of every element. If an element has no smaller on the left side, print -1.*/
#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallestElementToLeft(int arr[], int n)
{
    vector<int> v;
    stack<int> s;

    for (int i = 0; i < n; i++)
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
    return v;
}

int main()
{
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v = nextSmallestElementToLeft(arr, n);

    cout << "The array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nThe nearest smallest element to left for all the values in the array is: \n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << arr[i] << " --> " << v[i] << endl;
    }

    return 0;
}