#include <iostream>
using namespace std;

class stack{
    int *arr;
    int top;
    int size=50;
public:
    stack(){
        arr=new int[size];
        top=-1;
    }

    void push(int n){
        if(top==size-1){
            cout<<"Stack over flow No capacity to push"<<endl;
            return ;
        }

        top++;
        arr[top]=n;
    }

    void pop(){
        if(top==-1){
            cout<<"No element in the stack nothing to pop"<<endl;
            return ;
        }
        top--;
    }

    bool empty(){
        if(top==-1){
            return true ;
        }
    }

    int Top(){
        if(top==-1){
            cout<<"Nothing in the list "<<endl;
            return -1;
        }
        return arr[top];
    }

    void printStack(){
        for(int i=top;i>=0;i--){
            cout<<arr[i]<<" ";
        }
    }

};

int main(){
    stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.pop();
    cout<<st.Top()<<endl;
    st.printStack();
    return 0;
}