/*
 * main/GameGOBJ: range (2 files, 00215530-002155F0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00215530 */
#pragma push /* merge_units */
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00215530(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00215530 */

/* merge_units: begin func_002155F0 */
#pragma push /* merge_units */
typedef struct {
    void* vtable;
    char base[0x1C];
    unsigned char kind;
    char pad[3];
    int floor;
    unsigned char locked;
    char pad2[7];
} ElevatorMsg;
typedef struct { char pad[0x10]; void* transport; char pad2[0xF8]; int floorCount; int* floorLocked; } cElevatorGOBJ_002155F0;
#if 0 /* merge_units */
extern void Event_Construct(ElevatorMsg* msg, void* name);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void Transport_Send(void* transport, ElevatorMsg* msg, int a, int b);
#endif /* merge_units */
#define Transport_Send(a0, a1, a2, a3) (Transport_Send((int)(a0), (void *)(a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(ElevatorMsg* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */


/* Locks the given floor; in network games (unless silent) broadcasts the change. */
void cElevatorGOBJ_LockFloor(cElevatorGOBJ_002155F0* self, int floor, int silent)
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
#undef Event_Construct /* merge_units */
#undef Transport_Send /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002155F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002155F0 */
