#include <iostream>
using namespace std;

class stack{
    string *arr;
    int top;
    int size=100;
public:
    stack(){
        arr=new string[size];
        top=-1;
    }

    void push(string n){
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
        return top==-1;
    }

    string Top(){
        if(top==-1){
            cout<<"Nothing in the list "<<endl;
            return "";
        }
        return arr[top];
    }

    void printStack(){
        for(int i=top;i>=0;i--){
            cout<<arr[i]<<" ";
        }
    }

    void reverseSentence(string s){
        for(int i=0;i<s.length();i++){
            string word="";
            while(s[i]!=' '&&i<s.length()){
                word+=s[i];
                i++;
            }
            push(word);
        }

        while(!empty()){
            cout<<Top()<<" ";
            pop();
        }cout<<endl;

    }


};

int main(){
    stack st;
    string s="Hello , how you are doing? ";
    st.reverseSentence(s);
    return 0;
}