//Cài đặt các thuật toán sắp xếp với một mảng các cấu trúc sinh viên( tên, tuổi, diểm trung bình), khoá sắp xếp là trường tên
//sử dụng quick sort và tính thời gian thực hiện của thuật toán

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX 100000

typedef struct
{
    char name[30];
    int age;
    float score;
} Student;

//sử dụng quick sort để sắp xếp mảng sinh viên theo tên và tính thời gian thực hiện của thuật toán
void Swap(Student *a, Student *b)
{
    Student temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void QuickSort(Student a[], int left, int right)
{
    int i, j;
    Student x;
    x=a[(left+right)/2];
    i=left;
    j=right;
    do
    {
        while(strcmp(a[i].name, x.name)<0 && i<right)
        {
            i++;
        }
        while(strcmp(a[j].name, x.name)>0 && j>left)
        {
            j--;
        }
        if(i<=j)
        {
            Swap(&a[i], &a[j]);
            i++;
            j--;
        }
    }
    while(i<=j);
    if(left<j)
    {
        QuickSort(a, left, j);
    }
    if(i<right)
    {
        QuickSort(a, i, right);
    }
}

void NhapMang(Student a[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("Nhap sinh vien thu %d:\n", i+1);
        printf("Ten: ");
        fflush(stdin);
        gets(a[i].name);
        printf("Tuoi: ");
        scanf("%d", &a[i].age);
        printf("Diem trung binh: ");
        scanf("%f", &a[i].score);
    }
}

void XuatMang(Student a[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("Sinh vien thu %d:\n", i+1);
        printf("Ten: %s\n", a[i].name);
        printf("Tuoi: %d\n", a[i].age);
        printf("Diem trung binh: %.2f\n", a[i].score);
    }
}

int main()
{
    Student a[MAX];
    int n;
    clock_t start, end;
    double time_use;
    printf("Nhap so sinh vien: ");
    scanf("%d", &n);
    NhapMang(a, n);
    start=clock();
    QuickSort(a, 0, n-1);
    end=clock();
    time_use=(double)(end-start)/CLOCKS_PER_SEC;
    printf("Thoi gian thuc hien: %lf\n", time_use);
    XuatMang(a, n);
    return 0;
}


