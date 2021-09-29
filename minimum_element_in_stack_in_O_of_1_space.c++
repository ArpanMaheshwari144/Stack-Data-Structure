/*Design a Data Structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the SpecialStack. All these operations of SpecialStack must be O(1). To implement SpecialStack, you should only use standard Stack data structure and no other data structure like arrays, list, .. etc.*/
#include <bits/stdc++.h>
using namespace std;

stack<int> s;
int minElement;

struct SpecialStack
{
    void push1(int data)
    {
        if (s.size() == 0)
        {
            minElement = data;
            s.push(data);
            cout << "Number Inserted: " << data << endl;
            return;
        }
        else
        {
            if (data >= minElement)
            {
                s.push(data);
            }
            else if (data < minElement)
            {
                s.push(2 * data - minElement); // pushing flag value
                minElement = data;
            }
        }
        cout << "Number Inserted: " << data << endl;
    }

    void pop1()
    {
        if (s.size() == 0)
        {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Top Most Element Removed: ";
        int t = s.top();
        s.pop();

        if (t < minElement)
        {
            cout << minElement << endl;
            minElement = 2 * minElement - t;
        }
        else
        {
            cout << t << endl;
        }
    }

    void peek1()
    {
        if (s.empty())
        {
            cout << "Stack is empty ";
            return;
        }
        cout << "Top Most Element is: ";
        (s.top() < minElement) ? cout << minElement : cout << s.top();
    }

    void getMinElement()
    {
        if (s.size() == 0)
        {
            cout << "Stack is empty\n";
        }
        cout << "Minimum Element in the stack is: " << minElement << endl;
    }
};

int main()
{
    SpecialStack s;
    s.push1(3);
    s.push1(5);
    s.getMinElement();
    s.push1(2);
    s.push1(1);
    s.getMinElement();
    s.pop1();
    s.getMinElement();
    s.pop1();
    s.getMinElement();
    s.peek1();

    return 0;
}