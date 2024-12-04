//Nhập 1 dãy, tìm dãy con tăng dài nhất

//sử dụng danh sách liên kết đơn

#include<iostream>
#include<stack>

using namespace std;

struct node{
    int data;
    node* next;
};

node* createNode(int x){
    node* temp = new node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void addTail(node* &head, int x){
    node* temp = createNode(x);
    if(head == NULL){
        head = temp;
    }else{
        node* p = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
}

void printList(node* head){
    node* p = head;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
}

int main(){
    node* head = NULL;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        addTail(head, x);
    }

    printList(head);

    return 0;
}

//đô phuc tạp thuật toán: O(n^2)
//độ phức tạp bộ nhớ: O(n)
//độ phức tạp thuật toán: O(n)
//độ phức tạp bộ nhớ: O(n)
