#include "types.h"

/* Elevator floor message (vtable, base data, parameters). */
typedef struct FloorMsg {
    void* vtable;
    char base[0x1C];
    unsigned char kind;
    char pad[3];
    int floor;
    unsigned char locked;
    char pad2[7];
} FloorMsg;

typedef struct cElevatorGOBJ {
    char pad[0x10];
    int handle;
    char pad2[0xF8];
    int floorCount;
    int* floorLocks;
} cElevatorGOBJ;

extern unsigned char D_005721C8;
extern char D_004F54C8[];
extern char D_004DAEF0[]; /* floor message vtable */
extern void Event_Construct(FloorMsg* msg, void* name);
extern void Transport_Send(int target, FloorMsg* msg, int a, int b);
extern void cMessage_dtor(FloorMsg* msg, int flags);

/* Unlocks a floor and, when D_005721C8 is set and not silent, broadcasts the change. */
void cElevatorGOBJ_UnlockFloor(cElevatorGOBJ* self, int floor, int silent) {
    FloorMsg msg;
    if (floor >= 0 && floor < self->floorCount) {
        self->floorLocks[floor] = 0;
        if (D_005721C8 && !silent) {
            Event_Construct(&msg, D_004F54C8);
            msg.floor = floor;
            msg.vtable = D_004DAEF0;
            msg.locked = 0;
            msg.kind = 4;
            Transport_Send(self->handle, &msg, -1, -1);
            msg.vtable = D_004DAEF0;
            cMessage_dtor(&msg, 0);
        }
    }
}
