
#include <stdio.h>
#include <string.h>
#include "member1_student.h"

/* Register a new student */
void registerStudent(void)
{
    char regNo[20];
    int year;

    if (hostel.studentCount >= MAX_STUDENTS)
    {
        printf("\nStudent limit reached!\n");
        return;
    }

    printf("\n----- STUDENT REGISTRATION -----\n");

    printf("Enter Register Number: ");
    scanf(" %19s", regNo);

    /* Check duplicate register number */
    if (searchStudentByRegNo(regNo) != -1)
    {
        printf("\nStudent already registered!\n");
        return;
    }

    strcpy(hostel.students[hostel.studentCount].regNo, regNo);

    printf("Enter Student Name: ");
    scanf(" %49[^\n]",
          hostel.students[hostel.studentCount].name);

    printf("Enter Department: ");
    scanf(" %29[^\n]",
          hostel.students[hostel.studentCount].department);

    printf("Enter Year of Study (1-4): ");
    if (scanf("%d", &year) != 1)
    {
        printf("Invalid year input!\n");
        while (getchar() != '\n');
        return;
    }

    if (year < 1 || year > 4)
    {
        printf("Invalid year! Enter a year between 1 and 4.\n");
        return;
    }

    hostel.students[hostel.studentCount].year = year;

    printf("Enter Phone Number: ");
    scanf(" %14s",
          hostel.students[hostel.studentCount].phone);

    hostel.studentCount++;

    printf("\nStudent registered successfully!\n");
}

/* Display all registered students */
void displayStudents(void)
{
    int i;

    if (hostel.studentCount == 0)
    {
        printf("\nNo students registered yet!\n");
        return;
    }

    printf("\n========== STUDENT DETAILS ==========\n");

    for (i = 0; i < hostel.studentCount; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("Register Number : %s\n",
               hostel.students[i].regNo);
        printf("Name            : %s\n",
               hostel.students[i].name);
        printf("Department      : %s\n",
               hostel.students[i].department);
        printf("Year            : %d\n",
               hostel.students[i].year);
        printf("Phone Number    : %s\n",
               hostel.students[i].phone);
    }
}

/* Search student using register number */
int searchStudentByRegNo(const char regNo[])
{
    int i;

    for (i = 0; i < hostel.studentCount; i++)
    {
        if (strcmp(hostel.students[i].regNo, regNo) == 0)
        {
            return i;
        }
    }

    return -1;
}

/* Sort students alphabetically using Bubble Sort */
void sortStudentsByName(void)
{
    int i, j;
    Student temp;

    if (hostel.studentCount == 0)
    {
        printf("\nNo students available to sort!\n");
        return;
    }

    for (i = 0; i < hostel.studentCount - 1; i++)
    {
        for (j = 0; j < hostel.studentCount - i - 1; j++)
        {
            if (strcmp(hostel.students[j].name,
                       hostel.students[j + 1].name) > 0)
            {
                temp = hostel.students[j];

                hostel.students[j] =
                    hostel.students[j + 1];

                hostel.students[j + 1] = temp;
            }
        }
    }

    printf("\nStudents sorted alphabetically!\n");

    displayStudents();
}
