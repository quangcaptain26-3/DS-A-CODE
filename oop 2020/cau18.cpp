#include<bits/stdc++.h>

using namespace std;

/* tìm max của 2 số nguyên
template <typename T> T Max(T a, T b){
    return a > b ? a : b;
}
*/

 //tìm min của 2 số nguyên
template <class T> T Max(T a, T b){
    return a < b ? a : b;
}


int main(){
    cout << Max<int>(1, 2) << endl;
    cout << Max<float>(1.5, 2.5) << endl;
    cout << Max<char>('a', 'b') << endl;
    cout << Max<string>("abc", "xyz") << endl;

    return 0;
}

/*xây dụng khuôn hình hàm sắp xếp
template <class T> void Swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}



template <class T> void SapXep(T a[], int n){
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if(a[i] > a[j])
                Swap(a[i], a[j]);
}


int main(){
    int a[5] = {1, 5, 2, 4, 3};
    int n = sizeof(a) / sizeof(int);

    SapXep(a, n);

    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
*/