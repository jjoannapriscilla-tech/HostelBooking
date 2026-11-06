
#include <stdio.h>
#include <string.h>

#include "hostel.h"
#include "member1_student.h"
#include "member2_room.h"
#include "member3_allocation.h"

/* Shared hostel data */
HostelData hostel = {0};

/* Display the main menu */
void displayMenu(void)
{
    printf("\n========================================\n");
    printf("   COLLEGE HOSTEL ROOM ALLOCATION SYSTEM\n");
    printf("========================================\n");

    printf("\n--- STUDENT MANAGEMENT ---\n");
    printf("1. Register Student\n");
    printf("2. Display Students\n");
    printf("3. Search Student\n");
    printf("4. Sort Students by Name\n");

    printf("\n--- ROOM MANAGEMENT ---\n");
    printf("5. Initialize Hostel Rooms\n");
    printf("6. Display Room Details\n");
    printf("7. Display Vacant Rooms\n");

    printf("\n--- ROOM ALLOCATION ---\n");
    printf("8. Allocate Room\n");
    printf("9. Cancel Room Allocation\n");
    printf("10. Display Allocation Records\n");

    printf("\n0. Save and Exit\n");

    printf("\nEnter your choice: ");
}

int main(void)
{
    int choice;
    char regNo[20];
    int studentIndex;

    /* Load previously saved data */
    loadData();

    do
    {
        displayMenu();

        if (scanf("%d", &choice) != 1)
        {
            printf("\nInvalid input! Please enter a number.\n");

            while (getchar() != '\n');

            continue;
        }

        switch (choice)
        {
            case 1:
                registerStudent();
                saveData();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                printf("\nEnter Register Number to Search: ");
                scanf(" %19s", regNo);

                studentIndex = searchStudentByRegNo(regNo);

                if (studentIndex != -1)
                {
                    printf("\nStudent Found!\n");

                    printf("Register Number : %s\n",
                           hostel.students[studentIndex].regNo);

                    printf("Name            : %s\n",
                           hostel.students[studentIndex].name);

                    printf("Department      : %s\n",
                           hostel.students[studentIndex].department);

                    printf("Year            : %d\n",
                           hostel.students[studentIndex].year);

                    printf("Phone Number    : %s\n",
                           hostel.students[studentIndex].phone);
                }
                else
                {
                    printf("\nStudent not found!\n");
                }
                break;

            case 4:
                sortStudentsByName();
                saveData();
                break;

            case 5:
                initializeRooms();
                saveData();
                break;

            case 6:
                displayRoomDetails();
                break;

            case 7:
                displayVacantRooms();
                break;

            case 8:
                allocateRoom();
                break;

            case 9:
                cancelAllocation();
                break;

            case 10:
                displayAllocationRecords();
                break;

            case 0:
                saveData();
                printf("\nThank you for using the Hostel Room Allocation System!\n");
                printf("Exiting program...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}
