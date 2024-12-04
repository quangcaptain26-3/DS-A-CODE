//xây dựng bản mẫu hàm tMax để tìm được vị trí phần tủ lớn nhất từ N đến M trong mảng A

#include <iostream>

using namespace std;

template <class T> T tMax(T a[], int n, int m){
    T max = a[n];
    for(int i = n + 1; i <= m; i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    return max;
}