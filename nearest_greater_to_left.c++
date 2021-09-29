/*Given an array of integers, find the closest (not considering distance, but value) greater on left of every element. If an element has no greater on the left side, print -1.*/
#include <bits/stdc++.h>
using namespace std;

void nextLargestElementToLeft(int arr[], int n)
{
    vector<int> v;
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        if (s.size() == 0)
        {
            v.push_back(-1);
        }
        else if (s.size() > 0 && s.top() > arr[i])
        {
            v.push_back(s.top());
        }
        else if (s.size() > 0 && s.top() <= arr[i])
        {
            while (s.size() > 0 && s.top() <= arr[i])
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
    cout << "\nThe nearest greatest element to left for all the values in the array is: \n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << arr[i] << " --> " << v[i] << endl;
    }
}

int main()
{
    int arr[] = {1, 3, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    nextLargestElementToLeft(arr, n);

    return 0;
}