#include<bits/stdc++.h> 
using namespace std;

deque<int> dq;

int main(){
    //Them 3, 6 vao cuoi deque
    dq.push_back(3);
    dq.push_back(6);
    //Luc nay deque la: 3 6
    //Them 4 vao dau deque
    dq.push_front(4);
    //Luc nay deque la: 4 3 6
    //Them 1 vao dau deque
    dq.push_back(1);
    //Luc nay deque la: 4 3 6 1

    cout << "Kich thuoc cua deque la: " << dq.size() << endl;
    cout << "Phan tu dau tien trong deque la: " << dq.front() << endl;
    cout << "Phan tu cuoi cung trong deque la: " << dq.back() << endl;

    cout << "Xoa bo phan tu dau deque: " << endl;
    dq.pop_front(); 
    //Luc nay deque la: 4, 3

    cout << "Kich thuoc cua queue la: " << dq.size() << endl;
    cout << "Phan tu dau tien trong deque la: " << dq.front() << endl;
    cout << "Phan tu cuoi cung trong deque la: " << dq.back() << endl;

}