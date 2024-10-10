#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// here we include all the standard input and the oupur files.
#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 100
// in this part we will have to assign the value of the max and the min.

// in this part we arecreating a strudnt strucutre that will take the student id and age
struct Student {
    char name[MAX_NAME_LENGTH];
    int id;
    int age;
    char gender;
    char hobby;
};
// for this strucutre we will be taking the student semester and the float 
struct Semester {
// the maximum amoount of the dara this variable can take   
char name[MAX_NAME_LENGTH];
    float gpa;
    float contribution;
};
//
// over here we will have the student record such semester
struct StudentRecord {
    struct Student student;
    struct Semester semesters[8];
    int num_semesters;
};


// we define the  max value
struct StudentRecord students[MAX_STUDENTS];
int num_students = 0;



// in this part we are creating a function that can take the student name,id and age + etc and will store to the student records structure 
void add_student() {
    if (num_students >= MAX_STUDENTS) {
        printf("Maximum number of students reached.\n");
        return;
    }

    struct StudentRecord *record = &students[num_students];

    printf("Enter student name: ");
    scanf("%s", record->student.name);

    printf("Enter student ID: ");
    scanf("%d", &record->student.id);

    printf("Enter student age: ");
    scanf("%d", &record->student.age);

    record->num_semesters = 0;

    num_students++;
    printf("Student add successfully.\n");
}


// as the same function as before but will store the id semseter name, gpa and will also add to the records
void add_semester() {
    int student_id;
    printf("Enter student ID: ");
    scanf("%d", &student_id);

    struct StudentRecord *record = NULL;
    for (int i = 0; i < num_students; i++) {
        if (students[i].student.id == student_id) {
            record = &students[i];
            break;
        }
    }

    if (record == NULL) {
        printf("Student not found.\n");
        return;
    }

    if (record->num_semesters >= 8) {
        printf("Maximum number of semesters reached for this student.\n");
        return;
    }

    struct Semester *semester = &record->semesters[record->num_semesters];

    printf("Please Enter semester name: ");
    scanf("%s", semester->name);

    printf("Enter GPA for the semester: ");
    scanf("%f", &semester->gpa);

    record->num_semesters++;
    printf("Semester adde successfully.\n");
}


// this is the function that we use for displaying the info after user puts the input of the selected operation
void display_student_info() {
    int student_id;
    printf("Enter student ID: ");
    scanf("%d", &student_id);

    struct StudentRecord *record = NULL;
    for (int i = 0; i < num_students; i++) {
        if (students[i].student.id == student_id) {
            record = &students[i];
            break;
        }
    }

    if (record == NULL) {
        printf("Student not found.\n");
        return;
    }

    printf("Student Name: %s\n", record->student.name);
    printf("Student ID: %d\n", record->student.id);
    printf("Student Age: %d\n", record->student.age);

    printf("Semesters:\n");
    for (int i = 0; i < record->num_semesters; i++) {
        printf("  %s: GPA %.2f\n", record->semesters[i].name, record->semesters[i].gpa);
    }
}


// in this part we use the calculate gpa option to take the student input of the gpa and will calculate and generate the output
void calculate_overall_gpa() {
    int student_id;
    printf("Enter student ID: ");
    scanf("%d", &student_id);

    struct StudentRecord *record = NULL;
    for (int i = 0; i < num_students; i++) {
        if (students[i].student.id == student_id) {
            record = &students[i];
            break;
        }
    }

    if (record == NULL) {
        printf("Student not found.\n");
        return;
    }

    if (record->num_semesters == 0) {
        printf("No semesters found for this student.\n");
        return;
    }

    float total_gpa = 0;
    for (int i = 0; i < record->num_semesters; i++) {
        total_gpa += record->semesters[i].gpa;
    }

    float overall_gpa = total_gpa / record->num_semesters;
    printf("Overall GPA for %s: %.2f\n", record->student.name, overall_gpa);
}
// this is the main function that will just provide the user with all the choices that wants.
int main() {
    int choice;

    do {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Add Semester\n");
        printf("3. Display Student Info\n");
        printf("4. Calculate Overall Gpa\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                add_semester();
                break;
            case 3:
                display_student_info();
                break;
            case 4:
                calculate_overall_gpa();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
