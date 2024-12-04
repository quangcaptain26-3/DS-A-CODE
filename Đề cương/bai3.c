//khai báo cấu trúc danh sách liên kết đơn. Thông tin chứa trong mỗi nút gồm: họ tên, mã, sinh viên, điểm trung bình
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct node{
    char name[30];
    char id[10];
    float score;
    struct node *next;
}node;

