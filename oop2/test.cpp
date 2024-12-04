#include<bits/stdc++.h>

using namespace std;

queue<int> q;

void init(){
    while(!q.empty()){
        q.pop();
    }
}

void push(int x){
    q.push(x);
}

void pop(){
    if(!q.empty()){
        q.pop();
    }
}

int top(){
    if(!q.empty()){
        return q.front();
    }
    return -1;
}


