/*
 * main/message: 2 files, 00326AF0-00326B80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00326AF0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { void* vtable; char pad4[0x18]; int flags; char pad20[4]; unsigned char enable; char pad25[0xB]; } Msg00326AF0;
extern char D_0052AF10[];
extern char D_004DE6F0[];
extern char D_004DCF10[];
extern void* GObj_IdentityB(int handle);
extern void Event_Construct(Msg00326AF0* ev, void* desc);
extern void Event_Send(Msg00326AF0* ev, void* target, int flags);
extern void cMessage_dtor(Msg00326AF0* ev, int flags);
/* Script: EnableSuperJump(obj, enable). */
int Script_EnableSuperJump_2(int* args)
{
    Msg00326AF0 ev;
    unsigned char enable = args[1] != 0;
    void* obj = GObj_IdentityB(args[0]);
    Event_Construct(&ev, D_0052AF10);
    ev.vtable = D_004DE6F0;
    ev.flags = 0x40;
    ev.enable = enable;
    Event_Send(&ev, obj, 0);
    ev.vtable = D_004DCF10;
    cMessage_dtor(&ev, 0);
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00326AF0 */

/* merge_units: begin func_00326B80 */
#pragma push /* merge_units */
/* Script message object (vtable, base data, parameters). */
typedef struct Msg {
    void* vtable;
    char base[0x18];
    int size;
    char pad[4];
    unsigned char enable;
    char pad2[0xB];
} Msg;

typedef struct ScriptArgs1 {
    int target;
} ScriptArgs1;

#if 0 /* merge_units */
extern int GObj_IdentityB(int handle);
#endif /* merge_units */
#define GObj_IdentityB(a0) ((int)GObj_IdentityB((a0))) /* merge_units */

#if 0 /* merge_units */
extern void Event_Construct(Msg* msg, void* name);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((Msg00326AF0 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void Event_Send(Msg* msg, int target, int flags);
#endif /* merge_units */
#define Event_Send(a0, a1, a2) (Event_Send((Msg00326AF0 *)(a0), (void *)(a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(Msg* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((Msg00326AF0 *)(a0), (a1))) /* merge_units */


/* Script native: EnableSuperJump(target) - sends an enable message to the target. */
int Script_EnableSuperJump(ScriptArgs1* args) {
    Msg msg;
    int target = GObj_IdentityB(args->target);
    Event_Construct(&msg, D_0052AF10);
    msg.vtable = D_004DE6F0;
    msg.enable = 1;
    msg.size = 0x40;
    Event_Send(&msg, target, 0);
    msg.vtable = D_004DCF10;
    cMessage_dtor(&msg, 0);
    return 0;
}
#undef GObj_IdentityB /* merge_units */
#undef Event_Construct /* merge_units */
#undef Event_Send /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00326B80 */
