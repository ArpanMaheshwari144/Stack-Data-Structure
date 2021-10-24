/*The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate span of stock’s price for all n days.
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day (uss ith element ke liye usse phle consecutively kitne smaller or kine uske equal elements hai).
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}*/
#include <bits/stdc++.h>
using namespace std;

vector<int> stockSpan(int arr[], int n)
{
    vector<int> v;

    // stack pair ka banega jisme elements or unki index store hongi jiska first element and second index hoga
    stack<pair<int, int>> s;

    for (int i = 0; i < n; i++)
    {
        if (s.size() == 0)
        {
            v.push_back(-1);
        }
        else if (s.size() > 0 && s.top().first > arr[i]) // compare hum stack mei elements se hi karenge
        {
            v.push_back(s.top().second); // vector mei push hum iss baar index ko karenge
        }
        else if (s.size() > 0 && s.top().first <= arr[i])
        {
            while (s.size() > 0 && s.top().first <= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top().second);
            }
        }
        s.push({arr[i], i}); // stack mei push karenge elements or unki index
    }
    return v;
}

int main()
{
    int arr[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v = stockSpan(arr, n);

    cout << "The array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nThe nearest greatest element to left for all the values in the array is: \n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << arr[i] << " --> " << i - v[i] << endl;
    }

    return 0;
}