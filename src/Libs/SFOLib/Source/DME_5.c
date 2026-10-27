/*
 * Libs/SFOLib/Source/DME: 1 file, 00429B30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00429B30 */
#pragma push /* merge_units */
#include "types.h"

/* Stack message object: vtable followed by the base message data. */
typedef struct Msg {
    void* vtable;
    char data[0x2C];
} Msg;

extern char D_00572400;
extern char D_00582740[]; /* message type key "NetPlayGameMsg" */
/* NetPlayGameMsg vtable */
extern void cMessage_getSOBJClassId();
extern void cNetPlayGameMsg_dtor();
extern void cNetPlayGameMsg_Clone();
extern void cNetPlayGameMsg_Pack();
void * const D_004E0EC0[8] = { (void*)0x0, (void*)0x0, (void*)cNetPlayGameMsg_dtor, (void*)cNetPlayGameMsg_Clone, (void*)cNetPlayGameMsg_Pack, (void*)cMessage_getSOBJClassId, (void*)0x0, (void*)0x0 };
extern void cMessage_ctor_cMessageNameR(Msg* msg, void* name);
extern void cNetObj_SendMessage_int_cMessageR_int_int(int target, Msg* msg, int a, int b);
extern void cMessage_dtor(Msg* msg, int flags);

/* Sets the D_00572400 flag and broadcasts a NetPlayGameMsg to all machines. */
void cDME_SendPlayGame(void) {
    Msg msg;
    D_00572400 = 1;
    cMessage_ctor_cMessageNameR(&msg, D_00582740);
    msg.vtable = ((char*)D_004E0EC0);
    cNetObj_SendMessage_int_cMessageR_int_int(0, &msg, -1, -1);
    msg.vtable = ((char*)D_004E0EC0);
    cMessage_dtor(&msg, 0);
}
static inline void merge_flush_func_00429B30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00429B30 */
