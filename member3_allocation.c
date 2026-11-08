#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "hostel.h"

/* Find a room using its details */
static Room *findRoomRecord(char block, int floor, int roomNumber)
{
    int i, j, k;

    for (i = 0; i < BLOCKS; i++)
    {
        for (j = 0; j < FLOORS; j++)
        {
            for (k = 0; k < ROOMS_PER_FLOOR; k++)
            {
                Room *r = &hostel.rooms[i][j][k];

                if (r->block == block &&
                    r->floor == floor &&
                    r->roomNumber == roomNumber)
                {
                    return r;
                }
            }
        }
    }

    return NULL;
}

/* Find a student using registration number */
static int findStudent(const char regNo[])
{
    int i;

    for (i = 0; i < hostel.studentCount; i++)
    {
        if (strcmp(hostel.students[i].regNo, regNo) == 0)
            return i;
    }

    return -1;
}

/* Find an available allocation record */
static int getFreeAllocationSlot(void)
{
    int i;

    for (i = 0; i < hostel.allocationCount; i++)
    {
        if (!hostel.allocations[i].active)
            return i;
    }

    if (hostel.allocationCount < MAX_ALLOCATIONS)
        return hostel.allocationCount++;

    return -1;
}

/* Allocate a room */
void allocateRoom(void)
{
    char regNo[20];
    char block;
    int floor, roomNumber;
    int slot;
    Room *room;

    if (!hostel.roomsInitialized)
        initializeRooms();

    printf("\nEnter Student Registration Number: ");
    scanf("%19s", regNo);

    if (findStudent(regNo) == -1)
    {
        printf("Student not found. Register the student first.\n");
        return;
    }

    {
        int i;
        for (i = 0; i < hostel.allocationCount; i++)
        {
            if (hostel.allocations[i].active &&
                strcmp(hostel.allocations[i].regNo, regNo) == 0)
            {
                printf("Student already has a room allocation.\n");
                return;
            }
        }
    }

    printf("Enter Block (A-D): ");
    scanf(" %c", &block);
    block = (char)toupper((unsigned char)block);

    printf("Enter Floor: ");
    scanf("%d", &floor);

    printf("Enter Room Number: ");
    scanf("%d", &roomNumber);

    room = findRoomRecord(block, floor, roomNumber);

    if (room == NULL)
    {
        printf("Room not found.\n");
        return;
    }

    if (room->occupied >= room->capacity)
    {
        printf("Room is full. Please select another room.\n");
        return;
    }

    slot = getFreeAllocationSlot();

    if (slot == -1)
    {
        printf("Maximum allocation records reached.\n");
        return;
    }

    strcpy(hostel.allocations[slot].regNo, regNo);
    hostel.allocations[slot].block = block;
    hostel.allocations[slot].floor = floor;
    hostel.allocations[slot].roomNumber = roomNumber;
    hostel.allocations[slot].active = 1;

    room->occupied++;

    printf("Room allocated successfully!\n");

    saveData();
}

/* Cancel a room allocation */
void cancelAllocation(void)
{
    char regNo[20];
    int i;
    Room *room;

    printf("\nEnter Student Registration Number: ");
    scanf("%19s", regNo);

    for (i = 0; i < hostel.allocationCount; i++)
    {
        Allocation *a = &hostel.allocations[i];

        if (a->active && strcmp(a->regNo, regNo) == 0)
        {
            room = findRoomRecord(a->block, a->floor, a->roomNumber);

            if (room != NULL && room->occupied > 0)
                room->occupied--;

            a->active = 0;

            printf("Room allocation cancelled successfully!\n");

            saveData();
            return;
        }
    }

    printf("No active allocation found for this student.\n");
}

/* Display allocation records */
void displayAllocationRecords(void)
{
    int i;
    int found = 0;

    printf("\n--- ROOM ALLOCATION RECORDS ---\n");

    for (i = 0; i < hostel.allocationCount; i++)
    {
        Allocation *a = &hostel.allocations[i];

        if (a->active)
        {
            printf("\nRegistration Number: %s\n", a->regNo);
            printf("Block: %c\n", a->block);
            printf("Floor: %d\n", a->floor);
            printf("Room Number: %d\n", a->roomNumber);

            found = 1;
        }
    }

    if (!found)
        printf("No active allocation records found.\n");
}

/* Save hostel data */
void saveData(void)
{
    FILE *fp = fopen("hostel.dat", "wb");

    if (fp == NULL)
    {
        printf("Error opening file for saving.\n");
        return;
    }

    if (fwrite(&hostel, sizeof(HostelData), 1, fp) != 1)
        printf("Error saving hostel data.\n");
    else
        printf("Hostel data saved successfully.\n");

    fclose(fp);
}

/* Load hostel data */
void loadData(void)
{
    FILE *fp = fopen("hostel.dat", "rb");

    if (fp == NULL)
    {
        printf("No saved hostel data found.\n");
        return;
    }

    if (fread(&hostel, sizeof(HostelData), 1, fp) != 1)
        printf("Error loading hostel data.\n");
    else
        printf("Hostel data loaded successfully.\n");

    fclose(fp);
}