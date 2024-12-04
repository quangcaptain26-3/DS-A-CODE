#include<stdio.h>
#include<stdlib.h>

typedef struct student{
    char *name;
    int code;
    float average;
    struct student *next;
} Student;

Student *head = NULL;

void insert_student(char *name, int code, float average){
    Student *new_student = malloc(sizeof(Student));
    new_student->name = name;
    new_student->code = code;
    new_student->average = average;
    new_student->next = NULL;

    if(head == NULL){
        head = new_student;
    }else{
        Student *current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new_student;
    }
}

void bubble_sort_students(){
    Student *current = head;
    Student *next;

    while (current != NULL){
        next = current->next;

        while(next != NULL){
            if(strcmp(current->name, next->name) > 0){
                Student *temp = current;
                current = next;
                next = temp;
            } else if(strcmp (current->name, next->name) == 0 && current->code > next->code){
                Student *temp = current;
                current = next;
                next = temp;
            }

            next = next->next;
        }

        current = current->next;
    }
}

void search_student_name(char *name){
    Student *current = head;

    while (current != NULL){
        if(strcmp(current->name, name) == 0){
            printf("Student found!\n");
            printf("Name: %s\n", current->name);
            printf("Code: %d\n", current->code);
            printf("Average: %.2f\n", current->average);
            break;
        }
        current = current->next;
    }

    if(current == NULL){
        printf("Student not found!\n");
    }
}

void print_student_list(){
    Student *current = head;

    while (current != NULL){
        printf("Name: %s\n", current->name);
        printf("Code: %d\n", current->code);
        printf("Average: %.2f\n", current->average);
        printf("\n");
        current = current->next;
    }
}

int main(){
    insert_student("Joao", 1, 9.5);
    insert_student("Maria", 2, 8.5);
    insert_student("Jose", 3, 7.5);
    insert_student("Pedro", 4, 6.5);
    insert_student("Ana", 5, 5.5);
    insert_student("Carlos", 6, 4.5);
    insert_student("Paulo", 7, 3.5);
    insert_student("Lucas", 8, 2.5);
    insert_student("Marcos", 9, 1.5);
    insert_student("Lucia", 10, 0.5);

    printf("Before sorting:\n");
    print_student_list();

    bubble_sort_students();

    printf("After sorting:\n");
    print_student_list();

    search_student_name("Joao");
    search_student_name("Maria");
    search_student_name("Jose");
    search_student_name("Pedro");
    search_student_name("Ana");
    search_student_name("Carlos");
    search_student_name("Paulo");
    search_student_name("Lucas");
    search_student_name("Marcos");
    search_student_name("Lucia");

    return 0;



}