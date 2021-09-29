/*Design a Data Structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the SpecialStack. All these operations of SpecialStack must be O(1). To implement SpecialStack, you should only use standard Stack data structure and no other data structure like arrays, list, .. etc.*/
#include <bits/stdc++.h>
using namespace std;

stack<int> s;
stack<int> ss; // supporting stack

struct SpecialStack
{

    void push1(int data)
    {
        s.push(data);
        if (ss.size() == 0 || ss.top() >= data)
        {
            ss.push(data);
            cout << "Number Inserted: " << data << endl;
            return;
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

        int ans = s.top();
        s.pop();
        if (ss.top() == ans)
        {
            ss.pop();
        }

        cout << "Top Most Element Removed: " << ans << endl;
    }

    void getMinElement()
    {
        if (ss.size() == 0)
        {
            cout << "Stack is empty\n";
        }
        cout << "Minimum Element in the stack is: " << ss.top() << endl;
    }
};

int main()
{
    SpecialStack s;
    s.push1(10);
    s.push1(20);
    s.push1(30);
    s.getMinElement();
    s.push1(5);
    s.getMinElement();

    return 0;
}