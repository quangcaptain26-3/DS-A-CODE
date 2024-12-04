#include<bits/stdc++.h>

using namespace std;

queue <int> q;

int main(){
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Phan tu dau tien cua queue: " << q.front() << endl;    
    cout << "Kich thuoc cua queue la: " << q.size() << endl;

    cout << "Loai bo phan tu dau trong queue: " << endl;    
    q.pop();

    if(q.empty())
        cout << "Queue rong" << endl;
    else
        cout << "Queue khong rong" << endl;
    
    cout << "Phan tu dau tien trong queue: " << q.front() << endl;

    cout << "Kich thuoc cua queue la: " << q.size() << endl;

}