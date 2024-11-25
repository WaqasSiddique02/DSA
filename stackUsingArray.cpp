#include <iostream>
using namespace std;

class stack
{
    int *arr;
    int top;
    int size = 50;

public:
    stack()
    {
        arr = new int[size];
        top = -1;
    }

    void push(int n)
    {
        if (top == size - 1)
        {
            cout << "Stack over flow No capacity to push" << endl;
            return;
        }

        top++;
        arr[top] = n;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "No element in the stack nothing to pop" << endl;
            return;
        }
        top--;
    }

    bool empty()
    {
        return top == -1;
    }

    int Top()
    {
        if (top == -1)
        {
            cout << "Nothing in the list " << endl;
            return -1;
        }
        return arr[top];
    }

    void printStack()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
    }

    void reverse()
    {
        if (empty())
        {
            return; // Base case: If stack is empty, do nothing
        }

        int temp = Top(); // Get the top element
        pop();            // Remove the top element
        reverse();        // Recursively reverse the remaining stack
        push(temp);       // Push the element to the top (which will be the bottom of the reversed stack)
    }
};

int main()
{
    stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    // cout<<st.Top()<<endl;
    st.printStack();
    cout << endl;
    st.reverse();
    st.printStack();
    return 0;
}