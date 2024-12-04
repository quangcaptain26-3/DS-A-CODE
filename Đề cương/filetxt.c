//Cài đặt các thuật toán sắp xếp cơ bản trên 1 mảng các số nguyên, dữ liệu của chương trình được nhập vào từ file text được sinh ngẫu nhiên
//và so sánh thời gian thực hiện thực tế của các thuật toán sắp xếp trên mảng dữ liệu đó.
//Đầu vào: file text chứa dữ liệu ngẫu nhiên


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <conio.h>

#define MAX 100000

void NhapMang(int a[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        a[i]=rand()%1000;
    }
}

void XuatMang(int a[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d\t", a[i]);
    }
}

void Swap(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void BubbleSort(int a[], int n)
{
    int i, j;
    for(i=0; i<n-1; i++)
    {
        for(j=n-1; j>i; j--)
        {
            if(a[j]<a[j-1])
            {
                Swap(&a[j], &a[j-1]);
            }
        }
    }
}

void SelectionSort(int a[], int n)
{
    int i, j, min;
    for(i=0; i<n-1; i++)
    {
        min=i;
        for(j=i+1; j<n; j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        Swap(&a[i], &a[min]);
    }
}


void InsertionSort(int a[], int n)
{
    int i, j, x;
    for(i=1; i<n; i++)
    {
        x=a[i];
        j=i-1;
        while(j>=0 && a[j]>x)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
    }
}


void ShellSort(int a[], int n)
{
    int i, j, x, k;
    for(k=n/2; k>0; k/=2)
    {
        for(i=k; i<n; i++)
        {
            x=a[i];
            j=i-k;
            while(j>=0 && a[j]>x)
            {
                a[j+k]=a[j];
                j-=k;
            }
            a[j+k]=x;
        }
    }
}


void Heapify(int a[], int n, int i)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && a[l]>a[largest])
    {
        largest=l;
    }
    if(r<n && a[r]>a[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        Swap(&a[i], &a[largest]);
        Heapify(a, n, largest);
    }
}

void HeapSort(int a[], int n)
{
    int i;
    for(i=n/2-1; i>=0; i--)
    {
        Heapify(a, n, i);
    }
    for(i=n-1; i>=0; i--)
    {
        Swap(&a[0], &a[i]);
        Heapify(a, i, 0);
    }
}


void Merge(int a[], int l, int m, int r)
{
    int i, j, k;
    int n1=m-l+1;
    int n2=r-m;
    int L[n1], R[n2];
    for(i=0; i<n1; i++)
    {
        L[i]=a[l+i];
    }
    for(j=0; j<n2; j++)
    {
        R[j]=a[m+1+j];
    }
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=R[j];
        j++;
        k++;
    }
}


void MergeSort(int a[], int l, int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        MergeSort(a, l, m);
        MergeSort(a, m+1, r);
        Merge(a, l, m, r);
    }
}


int Partition(int a[], int low, int high)
{
    int pivot=a[high];
    int left=low;
    int right=high-1;
    while(1)
    {
        while(left<=right && a[left]<pivot)
        {
            left++;
        }
        while(right>=left && a[right]>pivot)
        {
            right--;
        }
        if(left>=right)
        {
            break;
        }
        Swap(&a[left], &a[right]);
        left++;
        right--;
    }
    Swap(&a[left], &a[high]);
    return left;
}


void QuickSort(int a[], int low, int high)
{
    if(low<high)
    {
        int pi=Partition(a, low, high);
        QuickSort(a, low, pi-1);
        QuickSort(a, pi+1, high);
    }
}


//main function

int main()
{
    int a[MAX];
    int n;
    int i;
    clock_t start, end;
    double time_use;
    FILE *fp;
    fp=fopen("file.txt", "r");
    if(fp==NULL)
    {
        printf("Khong mo duoc file\n");
        return 0;
    }
    fscanf(fp, "%d", &n);
    for(i=0; i<n; i++)
    {
        fscanf(fp, "%d", &a[i]);
    }
    fclose(fp);
    printf("Mang ban dau:\n");
    XuatMang(a, n);
    printf("\n");
    printf("Chon thuat toan sap xep:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Shell Sort\n");
    printf("5. Heap Sort\n");
    printf("6. Merge Sort\n");
    printf("7. Quick Sort\n");
    printf("8. Thoat\n");
    int choice;
    printf("Nhap lua chon cua ban: ");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        start=clock();
        BubbleSort(a, n);
        end=clock();
        time_use=((double)(end-start))/CLOCKS_PER_SEC;
        printf("Mang sau khi sap xep:\n");
        XuatMang(a, n);
        printf("\n");
        printf("Thoi gian thuc hien: %lf\n", time_use);
        break;
    case 2:
        start=clock();
        SelectionSort(a, n);
        end=clock();
        time_use=((double)(end-start))/CLOCKS_PER_SEC;
        printf("Mang sau khi sap xep:\n");
        XuatMang(a, n);
        printf("\n");
        printf("Thoi gian thuc hien: %lf\n", time_use);
        break;
    case 3:
        start=clock();
        InsertionSort(a, n);
        end=clock();
        time_use=((double)(end-start))/CLOCKS_PER_SEC;
        printf("Mang sau khi sap xep:\n");
        XuatMang(a, n);
        printf("\n");
        printf("Thoi gian thuc hien: %lf\n", time_use);
        break;
    case 4:
        start=clock();
        ShellSort(a, n);
        end=clock();
        time_use=((double)(end-start))/CLOCKS_PER_SEC;
        printf("Mang sau khi sap xep:\n");
        XuatMang(a, n);
        printf("\n");
        printf("Thoi gian thuc hien: %lf\n", time_use);
        break;

    case 5:
        start=clock();
        HeapSort(a, n);
        end=clock();
        time_use=((double)(end-start))/CLOCKS_PER_SEC;
        printf("Mang sau khi sap xep:\n");
        XuatMang(a, n);
        printf("\n");
        printf("Thoi gian thuc hien: %lf\n", time_use);
        break;

    case 6:

        start=clock();
        MergeSort(a, 0, n-1);
        end=clock();
        time_use=((double)(end-start))/CLOCKS_PER_SEC;
        printf("Mang sau khi sap xep:\n");
        XuatMang(a, n);
        printf("\n");
        printf("Thoi gian thuc hien: %lf\n", time_use);
        break;

    case 7:

        start=clock();
        QuickSort(a, 0, n-1);
        end=clock();
        time_use=((double)(end-start))/CLOCKS_PER_SEC;
        printf("Mang sau khi sap xep:\n");
        XuatMang(a, n);
        printf("\n");
        printf("Thoi gian thuc hien: %lf\n", time_use);
        break;

    case 8:

        break;
    }

    return 0;
}
