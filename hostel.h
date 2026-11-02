
#ifndef HOSTEL_H
#define HOSTEL_H

#define MAX_STUDENTS 100
#define MAX_ALLOCATIONS 100

#define BLOCKS 4
#define FLOORS 3
#define ROOMS_PER_FLOOR 20
#define BEDS_PER_ROOM 4

/* Student information */
typedef struct {
    char regNo[20];
    char name[50];
    char department[30];
    int year;
    char phone[15];
} Student;

/* Room information */
typedef struct {
    char block;
    int floor;
    int roomNumber;
    int isAC;
    int capacity;
    int occupied;
} Room;

/* Room allocation information */
typedef struct {
    char regNo[20];
    char block;
    int floor;
    int roomNumber;
    int active;
} Allocation;

/* Complete hostel data */
typedef struct {
    Student students[MAX_STUDENTS];
    int studentCount;

    Room rooms[BLOCKS][FLOORS][ROOMS_PER_FLOOR];

    Allocation allocations[MAX_ALLOCATIONS];
    int allocationCount;

    int roomsInitialized;
} HostelData;

/* Shared data */
extern HostelData hostel;

/* MEMBER 1 - Student Management */
void registerStudent(void);
void displayStudents(void);
int searchStudentByRegNo(const char regNo[]);
void sortStudentsByName(void);

/* MEMBER 2 - Room Management */
void initializeRooms(void);
void displayRoomDetails(void);
void displayVacantRooms(void);
int findRoom(char block, int floor, int roomNumber,
             int *blockIndex, int *floorIndex, int *roomIndex);

/* MEMBER 3 - Allocation and File Management */
void allocateRoom(void);
void cancelAllocation(void);
void displayAllocationRecords(void);
void saveData(void);
void loadData(void);

#endif
