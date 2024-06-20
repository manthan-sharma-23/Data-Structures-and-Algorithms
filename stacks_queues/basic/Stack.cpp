#include<bits/stdc++.h>

using namespace std;


class Stack{
    int *arr;
    int size;
    int top;
     

public:
    Stack(){
        top=-1;
        size=10000;
        arr=new int[size];
    }

    void push(int num){
        top++;
        arr[top]=num;
        cout <<"Pushed to stack "<<num<<endl;
    }


    void pop(){
        if(top==-1){
            cout <<"Stack is empty"<<endl;
            exit(0);
        }
        top--;
    }

    int Top(){
        if(top==-1){
            cout <<"Stack is empty"<<endl;
            exit(0);
        }
        return arr[top];
    }

    int Size(){
        return size;
    }
};

int main(){

    Stack s;

    s.push(2);
    s.push(2);
    s.Top();
}