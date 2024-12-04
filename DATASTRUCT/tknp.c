#include<stdio.h>

int TKNP(int *a, int n, int x){
    int L = 0, R = n - 1;
    int m;
    do{
        m = (L + R) / 2;
        if(a[m] == x){
            return m;
        }else if(a[m] < x){
            L = m + 1;
        }else{
            R = m - 1;
        }
    } while(L <= R);
    return -1;
}

int main(){
    //nhap mang co n phan tu
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    int a[n];
    printf("Nhap mang:\n");
    for(int i = 0; i < n; i++){
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    //nhap x
    int x;
    printf("Nhap x: ");
    scanf("%d", &x);
    //tim kiem nhi phan
    int kq = TKNP(a, n, x);
    if(kq == -1){
        printf("Khong tim thay %d trong mang\n", x);
    }else{
        printf("Tim thay %d tai vi tri %d trong mang\n", x, kq);
    }
    return 0;
}

//đánh giá thuật toán
// - Thời gian chạy: O(logn)
// - Không gian bộ nhớ: O(1)
// - Ưu điểm: hiệu quả, dễ cài đặt
// - Nhược điểm: chỉ áp dụng được cho dãy đã được sắp xếp
// - Ứng dụng: tìm kiếm trong dãy đã được sắp xếp
