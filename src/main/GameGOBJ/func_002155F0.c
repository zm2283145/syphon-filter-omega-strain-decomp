#include "types.h"

typedef struct {
    void* vtable;
    char base[0x1C];
    unsigned char kind;
    char pad[3];
    int floor;
    unsigned char locked;
    char pad2[7];
} ElevatorMsg;
typedef struct { char pad[0x10]; void* transport; char pad2[0xF8]; int floorCount; int* floorLocked; } cElevatorGOBJ;
extern unsigned char D_005721C8;
extern char D_004F54C8[];
extern char D_004DAEF0[];
extern void Event_Construct(ElevatorMsg* msg, void* name);
extern void Transport_Send(void* transport, ElevatorMsg* msg, int a, int b);
extern void cMessage_dtor(ElevatorMsg* msg, int flags);

/* Locks the given floor; in network games (unless silent) broadcasts the change. */
void cElevatorGOBJ_LockFloor(cElevatorGOBJ* self, int floor, int silent)
{
    if (floor >= 0 && floor < self->floorCount) {
        self->floorLocked[floor] = 1;
        if (D_005721C8 && !silent) {
            ElevatorMsg msg;
            Event_Construct(&msg, D_004F54C8);
            msg.floor = floor;
            msg.vtable = D_004DAEF0;
            msg.locked = 1;
            msg.kind = 4;
            Transport_Send(self->transport, &msg, -1, -1);
            msg.vtable = D_004DAEF0;
            cMessage_dtor(&msg, 0);
        }
    }
}
