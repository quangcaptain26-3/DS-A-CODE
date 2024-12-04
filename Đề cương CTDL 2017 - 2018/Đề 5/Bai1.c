//Trình bày thuật toán tìm kiếm nhị phân trên mảng gồm n số nguyên

int Binary_Search(int a[], int n, int x){
    int left = 0, right = n - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(a[mid] == x){
            return mid;
        }
        else if(a[mid] > x){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return -1;
}