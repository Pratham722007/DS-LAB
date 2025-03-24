#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100


typedef struct {
    char name[50];
    int roll_no;
    char department[50];
} Student;

int main() {
    FILE *file;
    Student students[MAX_STUDENTS];
    int count = 0;

    file = fopen("student2.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(file, "%50[^,], %d, %50[^\n]\n", students[count].name, &students[count].roll_no, students[count].department) == 3) {
        count++;
        if (count >= MAX_STUDENTS) {
            break;
        }
    }

    fclose(file);


    printf("Student Records before sorting:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Roll No: %d, Department: %s\n", students[i].name, students[i].roll_no, students[i].department);
    }

    // Bubble Sort
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            
            if (strcmp(students[i].name, students[j].name) > 0) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
            
            else if (strcmp(students[i].name, students[j].name) == 0) {
                if (students[i].roll_no > students[j].roll_no) {
                    Student temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }
        }
    }

    printf("\n------------- After Bubble Sort --------------------\n");
    printf("Student Records:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Roll No: %d, Department: %s\n", students[i].name, students[i].roll_no, students[i].department);
    }
// binary search
// Binary Search Implementation
printf("\n----------------- Binary Search ------------------\n");
char target[50];
printf("Enter student name to search: ");
scanf("%s", target);

int left = 0, right = count - 1;
int found = 0;  

while (left <= right) {
    int mid = left + (right - left) / 2;

    int cmp = strcmp(students[mid].name, target);

    if (cmp == 0) {
      
        printf("\nStudent Found:\n");
        printf("Name: %s, Roll No: %d, Department: %s\n", students[mid].name, students[mid].roll_no, students[mid].department);
        found = 1;
        break;
    }
    if (cmp < 0) {
        left = mid + 1;  
    } else {
        right = mid - 1; 
    }
}


if (!found) {
    printf("Student with name '%s' not found.\n", target);
}


    return 0;
}
