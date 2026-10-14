/*
 * main/human: range (5 files, 00185630-00185970)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"
#include "net_local_id.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_00185630 */
#pragma push /* merge_units */
typedef struct { void* vtable; char base[0x18]; int size; char pad20[4]; unsigned char holster; char pad25[0xB]; } Msg_185630;
typedef struct { char pad[0x4C]; int classKey; char pad50[0x3524 - 0x50]; void* weapons; } G_185630;
extern int D_0049D010;
extern char D_004EF030[];
extern char D_004DA9B0[];
extern char D_004DCF10[];
extern signed char* D_005061D0;
extern void Event_Construct(Msg_185630* msg, void* name);
extern void cMessage_dtor(Msg_185630* msg, int flags);
extern void Global_ForceHolster(void* w);
void func_00185630(G_185630* g)
{
    Msg_185630 msg;
    Event_Construct(&msg, D_004EF030);
    msg.vtable = D_004DA9B0;
    msg.size = 0x40;
    msg.holster = *D_005061D0++ != 0;
    if (g && g->classKey == D_0049D010) Global_ForceHolster(g->weapons);
    msg.vtable = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00185630(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00185630 */

/* merge_units: begin func_001856D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(10)
extern "C" {}
struct Ctl_56D0 { VPAD16(a) VPAD2(b) VPAD1(c) virtual int isNet(); };
typedef struct { char pad[0xC]; int idC; int id10; char pad14[0x18]; unsigned char b2C; unsigned char b2D; unsigned char b2E; char pad2F[0x29]; Ctl_56D0* ctl; } Obj_56D0;
extern "C" {
int func_003FBC40(int id);
void func_002D1FF0(void* key, int id);
int NetMap_BindReceiver(int id, int owner, Obj_56D0* o);
}
static inline unsigned char IsNet_56D0(Obj_56D0* o)
{
    unsigned char ok = 0;
    Ctl_56D0* c = o->ctl;
    if (c && c->isNet()) ok = 1;
    return ok;
}
extern "C" void func_001856D0(Obj_56D0* o)
{
    if (IsNet_56D0(o)) o->id10 = o->idC;
    else { int v = o->idC; if (v == -1) o->id10 = v; else { o->id10 = v; asm { .set reorder } /* barrier: keeps the identical arms from merging */ } }
    if (IsNet_56D0(o) || func_003FBC40(o->id10)) {
        int ok = o->b2D != 0;
        ok = ok ? o->b2C != 0 : ok;
        ok = ok ? (o->b2E != 0) ^ 1 : ok;
        if (ok) func_002D1FF0(&o->idC, o->id10);
    }
    {
        int t = o->id10;
        NetMap_BindReceiver(t, NetLocalId(), o);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001856D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001856D0 */

/* merge_units: begin func_00185840 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
int func_003FA780(int* a, unsigned char* flag, void** p);
void func_002C6B70(void* p, int a);
void func_002C6690(void* p, int a);
}
extern "C" void func_00185840(void)
{
    unsigned char flag;
    void* p;
    int a;
    while (func_003FA780(&a, &flag, &p)) {
        if (flag) func_002C6B70(p, a);
        else func_002C6690(p, a);
        {
            void* q = p;
            AllocGuard guard;
            Mem_Free(0, q, "human.cc", 0x447D);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00185840(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00185840 */

/* merge_units: begin func_00185940 */
#pragma push /* merge_units */
void func_00185940(int a0, int a1) {
    int v1;
    int cond;

    v1 = 0 + -1;
    cond = a1 != v1;
    if (cond) goto L00185958;
    v1 = *(int*)((char*)a0 + 12);
    *(int*)((char*)a0 + 16) = v1;
    goto L00185960;
L00185958:;
    *(int*)((char*)a0 + 16) = a1;
L00185960:;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00185940(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00185940 */

/* merge_units: begin func_00185970 */
#pragma push /* merge_units */
#pragma cplusplus on
class C_185970 { public: VPAD32(a) virtual unsigned char Mode(); char pad4[0x40]; void* t44; void* t48; char pad4C[0x1E0 - 0x4C]; void* t1E0; void* t1E4; };
struct R_185970 { char pad[0x10]; char* target; };
struct O_185970 { char pad[0x58]; C_185970* ctl; char pad5C[0x3584 - 0x5C]; char* target; };
extern "C" void func_00185970(O_185970* o, R_185970* r)
{
    if (r->target) {
        o->target = r->target;
        if (o->ctl->Mode() == 2) {
            o->ctl->t1E0 = r->target;
            { char* x = r->target; if (x) x += 0x1C; o->ctl->t1E4 = x; }
        } else {
            o->ctl->t44 = r->target;
            { char* x = r->target; if (x) x += 0x1C; o->ctl->t48 = x; }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00185970(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00185970 */
