/*
 * main/player: range (2 files, 00177C00-00177C60)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vt8_chain_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* merge_units: begin func_00177C00 */
#pragma push /* merge_units */
#pragma cplusplus on
DEFINE_VT8_CHAIN_DTOR(cPlayerRespawnCB_dtor, D_004D9DC0, D_004D9DE0)
#pragma pop /* merge_units */
/* merge_units: end func_00177C00 */

/* merge_units: begin func_00177C60 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Ev_7C60 { void* vt; char pad[0x18]; int size; char pad20[4]; int target; char pad28[8]; };
struct Q_7C60 { int type; unsigned char a; unsigned char b; char pad6[2]; void* vt; void* obj; };
struct O_7C60 { char pad[0x30]; void* recv; };
struct S_7C60 { char pad[0xC]; O_7C60* obj; };
struct G_7C60 { int pad0; float t; };
extern "C" {
extern G_7C60* g_Fader;
extern char D_004F7940[];
extern char D_004DB890[];
extern char D_004D9DE0[];
extern char D_004D9DC0[];
void Event_Construct(Ev_7C60* e, void* type);
void Event_Send(Ev_7C60* e, void* target, int a);
void cMessage_dtor(Ev_7C60* e, int f);
void* Mem_Alloc(int pool, int size, char* file, int line);
void EventQueue_Admit(Q_7C60* q);
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
void Alloc_Lock(int id);
void Alloc_Unlock(int id);
}
static inline void Init_7C60(Q_7C60* q, O_7C60* obj)
{
    q->vt = D_004D9DE0;
    q->a = 1;
    q->type = 0xF;
    q->b = 0;
    q->vt = D_004D9DC0;
    q->obj = obj;
}
extern "C" void Player_RespawnPollEvent(S_7C60* self)
{
    Q_7C60* q;
    if (g_Fader->t == 0.0f) {
        Ev_7C60 e;
        Event_Construct(&e, D_004F7940);
        e.target = 0;
        e.vt = D_004DB890;
        e.size = 0x40;
        Event_Send(&e, self->obj->recv, 0);
        e.vt = D_004DB890;
        cMessage_dtor(&e, 0);
        return;
    }
    if (g_ProfileLockEnabled)
        Alloc_Lock(9);
    g_ProfileLockDepth++;
    q = (Q_7C60*)Mem_Alloc(0, 0x10, "player.cc", 0x1AA);
    if (g_ProfileLockEnabled)
        Alloc_Unlock(9);
    g_ProfileLockDepth--;
    if (q)
        Init_7C60(q, self->obj);
    EventQueue_Admit(q);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00177C60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00177C60 */
