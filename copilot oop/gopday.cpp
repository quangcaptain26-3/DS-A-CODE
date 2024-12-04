#include<iostream>

using namespace std;

int a[100], b[100], c[100];

int main(){
    int n, m;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }

    int size = 0;
    int i = 0, j = 0;
    while(i < n && j < m){
        if(a[i] < b[j]){
            c[size++] = a[i++];
        }else{
            c[size++] = b[j++];
        }
    }
    while(i < n){
        c[size++] = a[i++];
    }
    while(j < m){
        c[size++] = b[j++];
    }
    for(int i = 0; i < size; i++){
        cout << c[i] << " ";
    }
}