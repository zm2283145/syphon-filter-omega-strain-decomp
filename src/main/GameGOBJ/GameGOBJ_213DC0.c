/*
 * main/GameGOBJ: range (2 files, 00213DC0-00213EE0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00213DC0 */
#pragma push /* merge_units */
typedef struct { char d[0x9C]; } LdStr_f3;
typedef struct {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    LdStr_f3 s78;
    LdStr_f3 s114;
    char pad1B0[0x10];
} __attribute__((aligned(16))) LdSnd_f3;
typedef struct { void* vtable; char base[0x20]; int kind; int arg; } LdMsg_f3;
typedef struct { char pad[0x150]; char preset[1]; } Lift_f3;
extern char D_004F5448[];
extern char D_004DAED0[];
extern char D_004FFB50[];
extern char D_004DAE30[];
extern int func_00214240(Lift_f3* l);
extern int func_00214470(Lift_f3* l);
extern int func_002141A0(Lift_f3* l);
extern void func_00214310(Lift_f3* l);
extern void Event_Construct(LdMsg_f3* m, void* type);
extern void Event_Send(void* m, void* target, int immediate);
extern void cMessage_dtor(void* m, int flags);
extern void SoundEvent_CtorFromPreset(LdSnd_f3* e, void* preset, Lift_f3* l);
extern void func_0036E220(LdStr_f3* s, int flag);
unsigned char Lift_OpenDoors(Lift_f3* l)
{
    LdSnd_f3 ev;
    LdMsg_f3 msg;
    unsigned char r;
    if (func_00214240(l)) {
        r = func_00214470(l);
        if (r) {
            Event_Construct(&msg, D_004F5448);
            msg.vtable = D_004DAED0;
            msg.kind = 2;
            msg.arg = 0;
            Event_Send(&msg, l, 0);
            msg.vtable = D_004DAED0;
            cMessage_dtor(&msg, 0);
        }
        SoundEvent_CtorFromPreset(&ev, l->preset, l);
        ev.flag = 1;
        Event_Send(&ev, D_004FFB50, 1);
        ev.vt = D_004DAE30;
        func_0036E220(&ev.s114, -1);
        func_0036E220(&ev.s78, -1);
        cMessage_dtor(&ev, 0);
    } else {
        r = 1;
    }
    if (func_002141A0(l)) {
        func_00214310(l);
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00213DC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00213DC0 */

/* merge_units: begin func_00213EE0 */
#pragma push /* merge_units */
typedef struct MsgLC {
    void* vtable;
    char base[0x20];
    int f24;
    int f28;
    char pad[4];
} MsgLC;
extern int func_00214080(void* lift);
#if 0 /* merge_units */
extern unsigned char func_00214470(void* lift);
#endif /* merge_units */
#define func_00214470(a0) ((unsigned char)func_00214470((void *)(a0))) /* merge_units */

extern int func_00213FE0(void* lift);
#if 0 /* merge_units */
extern void func_00214310(void* lift);
#endif /* merge_units */
#define func_00214310(a0) (func_00214310((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void Event_Construct(MsgLC* msg, void* name);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void Event_Send(MsgLC* msg, void* target, int flags);
#endif /* merge_units */
#define Event_Send(a0, a1, a2) (Event_Send((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(MsgLC* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

unsigned char Lift_CloseDoors(void* lift)
{
    unsigned char r = 1;
    if (func_00214080(lift)) {
        r = func_00214470(lift);
        if (r) {
            MsgLC msg;
            Event_Construct(&msg, D_004F5448);
            msg.vtable = D_004DAED0;
            msg.f24 = 3;
            msg.f28 = 0;
            Event_Send(&msg, lift, 0);
            msg.vtable = D_004DAED0;
            cMessage_dtor(&msg, 0);
        }
    }
    if (func_00213FE0(lift)) {
        func_00214310(lift);
    }
    return r;
}
#undef func_00214470 /* merge_units */
#undef func_00214310 /* merge_units */
#undef Event_Construct /* merge_units */
#undef Event_Send /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00213EE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00213EE0 */
