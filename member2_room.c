#ifndef MEMBER2_ROOM_H
#define MEMBER2_ROOM_H

#include "hostel.h"

void initializeRooms(void);
void displayRoomDetails(void);
void displayVacantRooms(void);
int findRoom(char block, int floor, int roomNumber,
             int *blockIndex, int *floorIndex, int *roomIndex);

#endif
