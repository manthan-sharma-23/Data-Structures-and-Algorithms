#include <bits/stdc++.h>

using namespace std;

class Stack{
    queue <int>q;

    public:
    void Push(int x){
        int s=q.size();
        q.push(x);

        for(int i=0;i<s;i++){
            q.push(q.front());
            q.pop();
        }
    }

};


int main(){
    return 0;
}