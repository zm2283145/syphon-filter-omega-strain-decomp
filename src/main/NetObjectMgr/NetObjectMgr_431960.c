/*
 * main/NetObjectMgr: range (2 files, 00431960-00431A70)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "msg_clone.h"
#pragma pop
#include "types.h"
#pragma push
#pragma cplusplus on
#include "net_recv_guard.h"
#pragma pop

/* merge_units: begin func_00431960 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" char D_004E0EE0[];
extern "C" char D_004DFD80[];
MSG_CLONE_BEGIN(cNetSetGobjMsg_v01, 0x30, "NetSetGobjMsg.hh", 0x1A)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004E0EE0;
    F(char, 0x24) = S(char, 0x24);
    F(int, 0x28) = S(int, 0x28);
    F(int, 0x2C) = S(int, 0x2C);
MSG_CLONE_END
#pragma pop /* merge_units */
/* merge_units: end func_00431960 */

/* merge_units: begin func_00431A70 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern unsigned char D_005721D0;
void* Object_LookupById(int*);
void Actor_SetHealth(void*, int, int);
}
typedef struct { char pad[8]; char done; char p1[3]; int id; int arg; } T431A70;
#pragma push
#pragma opt_propagation off
extern "C" int cNetSetGobjMsg_NetReceive(int a0, int a1, int a2, T431A70* m) {
    NetRecvGuard g;
    if (D_005721D0) {
        T431A70* s = m;
        /* .set reorder barrier keeps the empty then-arm */
        if (m->done) asm { .set reorder }
        else {
            int id = s->id;
            void* o = Object_LookupById(&id);
            if (o) Actor_SetHealth(o, s->arg, 1);
        }
    }
    return 0x14;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00431A70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00431A70 */
