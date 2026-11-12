#include <stdio.h>
#include "member2_room.h"

/* Initialize all hostel rooms */
void initializeRooms(void)
{
    int i, j, k;
    int roomNumber = 1;

    if (hostel.roomsInitialized == 1)
    {
        printf("\nRooms are already initialized!\n");
        return;
    }

    for (i = 0; i < BLOCKS; i++)
    {
        roomNumber = 1;

        for (j = 0; j < FLOORS; j++)
        {
            for (k = 0; k < ROOMS_PER_FLOOR; k++)
            {
                hostel.rooms[i][j][k].block = 'A' + i;

                hostel.rooms[i][j][k].floor = j + 1;

                hostel.rooms[i][j][k].roomNumber = roomNumber;

                hostel.rooms[i][j][k].capacity = BEDS_PER_ROOM;

                hostel.rooms[i][j][k].occupied = 0;

                /*
                   Ground floor of blocks A and C
                   contains AC rooms.
                */
                if ((i == 0 || i == 2) && j == 0)
                {
                    hostel.rooms[i][j][k].isAC = 1;
                }
                else
                {
                    hostel.rooms[i][j][k].isAC = 0;
                }

                roomNumber++;
            }
        }
    }

    hostel.roomsInitialized = 1;

    printf("\nHostel rooms initialized successfully!\n");
}

/* Display details of all hostel rooms */
void displayRoomDetails(void)
{
    int i, j, k;

    if (hostel.roomsInitialized == 0)
    {
        printf("\nPlease initialize rooms first!\n");
        return;
    }

    printf("\n========== HOSTEL ROOM DETAILS ==========\n");

    for (i = 0; i < BLOCKS; i++)
    {
        for (j = 0; j < FLOORS; j++)
        {
            for (k = 0; k < ROOMS_PER_FLOOR; k++)
            {
                printf("\nBlock       : %c",
                       hostel.rooms[i][j][k].block);

                printf("\nFloor       : %d",
                       hostel.rooms[i][j][k].floor);

                printf("\nRoom Number : %d",
                       hostel.rooms[i][j][k].roomNumber);

                printf("\nRoom Type   : %s",
                       hostel.rooms[i][j][k].isAC ? "AC" : "Non-AC");

                printf("\nCapacity    : %d",
                       hostel.rooms[i][j][k].capacity);

                printf("\nOccupied    : %d",
                       hostel.rooms[i][j][k].occupied);

                printf("\nVacant Beds : %d\n",
                       hostel.rooms[i][j][k].capacity -
                       hostel.rooms[i][j][k].occupied);
            }
        }
    }
}

/* Display rooms having vacant beds */
void displayVacantRooms(void)
{
    int i, j, k;
    int vacantCount = 0;

    if (hostel.roomsInitialized == 0)
    {
        printf("\nPlease initialize rooms first!\n");
        return;
    }

    printf("\n========== VACANT ROOMS ==========\n");

    for (i = 0; i < BLOCKS; i++)
    {
        for (j = 0; j < FLOORS; j++)
        {
            for (k = 0; k < ROOMS_PER_FLOOR; k++)
            {
                if (hostel.rooms[i][j][k].occupied <
                    hostel.rooms[i][j][k].capacity)
                {
                    printf("\nBlock: %c",
                           hostel.rooms[i][j][k].block);

                    printf(" | Floor: %d",
                           hostel.rooms[i][j][k].floor);

                    printf(" | Room: %d",
                           hostel.rooms[i][j][k].roomNumber);

                    printf(" | Type: %s",
                           hostel.rooms[i][j][k].isAC ? "AC" : "Non-AC");

                    printf(" | Vacant Beds: %d\n",
                           hostel.rooms[i][j][k].capacity -
                           hostel.rooms[i][j][k].occupied);

                    vacantCount++;
                }
            }
        }
    }

    if (vacantCount == 0)
    {
        printf("\nNo vacant rooms available!\n");
    }
    else
    {
        printf("\nTotal rooms with vacancies: %d\n",
               vacantCount);
    }
}

/* Find a room using block, floor and room number */
int findRoom(char block, int floor, int roomNumber,
             int *blockIndex, int *floorIndex, int *roomIndex)
{
    int i, j, k;

    if (hostel.roomsInitialized == 0)
    {
        return 0;
    }

    if (block >= 'a' && block <= 'z')
    {
        block = block - 32;
    }

    for (i = 0; i < BLOCKS; i++)
    {
        for (j = 0; j < FLOORS; j++)
        {
            for (k = 0; k < ROOMS_PER_FLOOR; k++)
            {
                if (hostel.rooms[i][j][k].block == block &&
                    hostel.rooms[i][j][k].floor == floor &&
                    hostel.rooms[i][j][k].roomNumber == roomNumber)
                {
                    *blockIndex = i;
                    *floorIndex = j;
                    *roomIndex = k;

                    return 1;
                }
            }
        }
    }

    return 0;
}