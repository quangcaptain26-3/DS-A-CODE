#include<bits/stdc++.h>

using namespace std;

queue<int> q;

void initQ(queue<int> &q){
    while(!q.empty()){
        q.pop();
    }
}

void addQ(queue<int> &q, int x){
    q.push(x);
}

void delQ(queue<int> &q){
    q.pop();
}

int topQ(queue<int> q){
    return q.front();
}

bool isEmpty(queue<int> q){
    return q.empty();
}

//main function convert binary to decimal
int main(){
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        initQ(q);
        addQ(q, 1);
        while(!isEmpty(q)){
            int t = topQ(q);
            delQ(q);
            if(t % x == 0){
                cout << t << endl;
                break;
            }
            addQ(q, t * 10);
            addQ(q, t * 10 + 1);
        }
    }
    return 0;
}